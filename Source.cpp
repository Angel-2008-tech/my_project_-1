#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

// Зовнішня функція, що створює об'єкт
Matrix makeMatrix(int r, int c) {
    Matrix m;
    if (!m.Init(r, c)) {
        cout << "Помилкові аргументи передано у функцію makeMatrix!" << endl;
        exit(1); // завершуємо роботу програми при помилці
    }
    return m;
}

int main() {
    system("chcp 1251"); // Для коректного відображення кирилиці в консолі

    // Спосіб 1: Використання методу Read() для створення матриці користувачем
    Matrix m1;
    cout << "=== Створення першої матриці (через введення) ===" << endl;
    m1.Read();
    m1.Display();
    cout << "Мінімальний елемент: " << m1.getMin() << endl;
    cout << "Максимальний елемент: " << m1.getMax() << endl;
    cout << "Сума елементів: " << m1.getSum() << endl;

    // Спосіб 2: Використання зовнішньої функції makeMatrix() та setElement()
    cout << "\n=== Створення другої матриці (через функцію makeMatrix) ===" << endl;
    Matrix m2 = makeMatrix(2, 3);

    // Встановлюємо елементи вручну
    m2.setElement(0, 0, 1.2f);
    m2.setElement(0, 1, -4.5f);
    m2.setElement(0, 2, 7.1f);
    m2.setElement(1, 0, 0.0f);
    m2.setElement(1, 1, 9.9f);
    m2.setElement(1, 2, 3.14f);

    m2.Display();
    cout << "Елемент [0][1]: " << m2.getElement(0, 1) << endl;
    cout << "Мінімальний елемент: " << m2.getMin() << endl;
    cout << "Максимальний елемент: " << m2.getMax() << endl;
    cout << "Сума елементів: " << m2.getSum() << endl;

    // Спосіб 3: Демонстрація помилки при створенні
    cout << "\n=== Спроба створення матриці з некоректними даними ===" << endl;
    Matrix m3 = makeMatrix(-1, 5); // Програма виведе помилку та завершиться

    return 0;
}