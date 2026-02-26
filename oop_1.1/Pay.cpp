// Pay.cpp
#include "Pay.h"
#include <iostream>

using namespace std;

bool Pay::SetFirst(double value) {
    // Оклад має бути додатним числом
    if (value > 0) {
        first = value;
        return true;
    }
    else {
        first = 1.0; // Встановлення безпечного значення за замовчуванням
        return false;
    }
}

bool Pay::SetSecond(int value) {
    // Кількість відпрацьованих днів має бути додатним числом
    if (value > 0) {
        second = value;
        return true;
    }
    else {
        second = 1; // Встановлення безпечного значення за замовчуванням
        return false;
    }
}

bool Pay::Init(double f, int s) {
    // Використання методів Set для уникнення дублювання коду та обов'язкової перевірки
    return SetFirst(f) && SetSecond(s);
}

void Pay::Read() {
    double f;
    int s;
    do {
        cout << "Введіть оклад (first > 0): ";
        cin >> f;
        cout << "Введіть кількість відпрацьованих днів (second > 0): ";
        cin >> s;
    } while (!Init(f, s)); // Запитуємо доти, доки не введуть коректні дані
}

void Pay::Display() const {
    cout << "Оклад (first) = " << first << endl;
    cout << "Кількість відпрацьованих днів (second) = " << second << endl;
}

double Pay::summa(int work_days_in_month) const {
    // Уникнення ділення на нуль
    if (work_days_in_month <= 0) return 0;

    // Обчислення за формулою: оклад / кількість_робочих_днів_у_місяці * кількість_відпрацьованих_днів
    return (first / work_days_in_month) * second;
}