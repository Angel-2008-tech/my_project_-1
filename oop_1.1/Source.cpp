// Source.cpp
#include <iostream>
#include <windows.h> // Додано для налаштування кодування консолі
#include "Pay.h"

using namespace std;

// Зовнішня функція для створення об'єкту
Pay makePay(double f, int s) {
    Pay p;
    if (!p.Init(f, s)) {
        cout << "Помилка: невірні аргументи для ініціалізації!" << endl;
    }
    return p;
}

int main() {
    // Встановлення кодування 1251 для вводу та виводу кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1. Демонстрація ініціалізації через метод Init
    cout << "--- Перевірка методу Init та Display ---" << endl;
    Pay p1;
    p1.Init(20000.0, 15);
    p1.Display();
    cout << "Нарахована сума (при 22 робочих днях у місяці): " << p1.summa(22) << endl << endl;

    // 2. Демонстрація введення значень з клавіатури
    cout << "--- Перевірка методу Read ---" << endl;
    Pay p2;
    p2.Read();
    p2.Display();
    int wd;
    cout << "Введіть кількість робочих днів у поточному місяці: ";
    cin >> wd;
    cout << "Нарахована сума: " << p2.summa(wd) << endl << endl;

    // 3. Демонстрація роботи зовнішньої функції makePay з перевіркою параметрів
    cout << "--- Перевірка зовнішньої функції makePay ---" << endl;
    double f;
    int s;
    cout << "Введіть оклад: ";
    cin >> f;
    cout << "Введіть кількість відпрацьованих днів: ";
    cin >> s;
    Pay p3 = makePay(f, s);
    p3.Display();

    return 0;
}