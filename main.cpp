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
void mainMenu() {
    clearScreen();
    setColor(11);

    cout << "=========================\n";
    cout << "   СИСТЕМА СТУДЕНТОВ\n";
    cout << "=========================\n";
    cout << "1. Просмотр студентов\n";
    cout << "2. Выставить оценки\n";
    cout << "3. Выход\n";
    cout << "Выберите пункт: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleTitleA("Система управления студентами");

    int choice;

    while (true) {
        mainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            viewStudents();
            break;
        case 2:
            setGrades();
            break;
        case 3:
            return 0;
        default:
            cout << "Неверный ввод!\n";
            Sleep(1000);
        }
    }
}

void viewStudents() {
    int index = 0;
    char key;

    while (true) {
        clearScreen();
        setColor(14);

        cout << "===== ПРОСМОТР СТУДЕНТОВ =====\n\n";
        cout << "Студент: " << students[index].name << "\n";
        cout << "Возраст: " << students[index].age << "\n";
        cout << "Оценка: " << students[index].grade << "\n\n";

        setColor(10);
        cout << "[A] Назад  [D] Вперед  [Q] Выйти\n";
        setColor(7);

        key = getchar();

        if (key == 'a' || key == 'A') {
            if (index > 0) index--;
        }
        else if (key == 'd' || key == 'D') {
            if (index < students.size() - 1) index++;
        }
        else if (key == 'q' || key == 'Q') {
            break;
        }
    }
}