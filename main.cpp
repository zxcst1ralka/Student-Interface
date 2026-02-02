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
    {"Иван Петров", 18, 0},
    {"Анна Смирнова", 19, 0},
    {"Дмитрий Кузнецов", 20, 0},
    {"Мария Иванова", 18, 0}
};
