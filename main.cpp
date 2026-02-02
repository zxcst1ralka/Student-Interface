#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    int grade;
};

vector<Student> students = {
    {"���� ������", 18, 0},
    {"���� ��������", 19, 0},
    {"������� ��������", 20, 0},
    {"����� �������", 18, 0}
};
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

void gotoXY(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
