#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

// Константы
const int BOARD_SIZE = 8;
const int EMPTY = 0;
const int WHITE_PAWN = 1;
const int BLACK_PAWN = 2;
const int WHITE_KING = 3;
const int BLACK_KING = 4;

// Уровни сложности бота
enum class Difficulty {
    EASY,       // Случайные ходы
    HARD        // Минимакс с альфа-бета отсечением
};

// Структура для хода
struct Move {
    int fromRow, fromCol;
    int toRow, toCol;
    vector<pair<int, int>> capturedPieces;
    bool isCapture = false;
    
    Move() : fromRow(-1), fromCol(-1), toRow(-1), toCol(-1) {}
    Move(int fr, int fc, int tr, int tc) 
        : fromRow(fr), fromCol(fc), toRow(tr), toCol(tc) {}
    
    void print() const {
        cout << char('A' + fromCol) << fromRow + 1 << " -> " 
             << char('A' + toCol) << toRow + 1;
        if(isCapture) cout << " (взятие)";
    }
};

class CheckersGame {
private:
    int board[BOARD_SIZE][BOARD_SIZE];
    bool isWhiteTurn;
    Difficulty botDifficulty;
    HANDLE hConsole;
    int selectedRow, selectedCol;
    bool pieceSelected;
    vector<Move> possibleMoves;
    int whiteScore, blackScore;
    int moveCount;
    bool gameOver;
    bool exitRequested;
    
public:
    CheckersGame(Difficulty diff) : isWhiteTurn(true), botDifficulty(diff), 
                                    pieceSelected(false), selectedRow(4), 
                                    selectedCol(4), whiteScore(0), blackScore(0),
                                    moveCount(0), gameOver(false), exitRequested(false) {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        initializeBoard();
    }
    
    void initializeBoard() {
        // Очищаем доску
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = EMPTY;
            }
        }
        
        // Расставляем белые шашки
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if((i + j) % 2 == 1) {
                    board[i][j] = WHITE_PAWN;
                }
            }
        }
        
        // Расставляем черные шашки
        for(int i = 5; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if((i + j) % 2 == 1) {
                    board[i][j] = BLACK_PAWN;
                }
            }
        }
    }
    
    void run() {
        srand(static_cast<unsigned int>(time(0)));
        drawBoard();
        
        while(true) {
            if(isGameOver()) {
                showGameOver();
                break;
            }
            
            if(exitRequested) {
                break;
            }
            
            if(isWhiteTurn) {
                handlePlayerInput();
            } else {
                makeBotMove();
            }
            
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
    
    bool isGameOver() {
        return gameOver;
    }
};