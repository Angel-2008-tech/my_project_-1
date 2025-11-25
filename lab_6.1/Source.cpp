#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cassert> // Бібліотека для тестів

using namespace std;

// 1. ЛОГІКА (Те, що ми будемо тестувати)

// Перевірка умови
bool ok(int x, int i) {
    // критерій: всі, крім парних з індексами, кратними 13
    if (x % 2 == 0 && i % 13 == 0) return false;
    return true;
}

// Функція обробки (приймає масив, змінює його і повертає count та sum через посилання)
void processArray(int* p, int N, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (ok(p[i], i)) {
            count++;
            sum += p[i];
            p[i] = 0;
        }
    }
}

// 2. ТЕСТИ (Перевірка нашої логіки)
void runTests() {
    cout << "Running tests... ";

    // ТЕСТ 1: Перевірка функції ok()
    // Випадок А: Парне число (10) на індексі 13 (кратне 13). Має бути false.
    assert(ok(10, 13) == false);

    // Випадок Б: Непарне число (11) на індексі 13. Має бути true.
    assert(ok(11, 13) == true);

    // Випадок В: Парне число (10) на індексі 1 (не кратне 13). Має бути true.
    assert(ok(10, 1) == true);

  
    const int testSize = 3;
    int testArray[testSize] = { 10, 11, 12 };
  

    int count = 0, sum = 0;
    processArray(testArray, testSize, count, sum);


    assert(testArray[0] == 10);
    assert(testArray[1] == 0);
    assert(testArray[2] == 0);
    assert(sum == 23);
    assert(count == 2);

    cout << "All tests passed! OK." << endl;
}

// 3. ОСНОВНА ПРОГРАМА
int main() {
    // Спочатку запускаємо тести
    runTests();

    cout << "--------------------------------\n";

    srand(time(NULL));
    const int N = 25;
    int p[N];

    // формування масиву
    for (int i = 0; i < N; i++) {
        p[i] = 15 + rand() % (94 - 15 + 1);
    }

    // виведення
    cout << "Original:\n";
    for (int i = 0; i < N; i++) {
        cout << setw(4) << p[i];
    }
    cout << endl;

    int count = 0;
    int sum = 0;

    // Виклик нашої винесеної функції
    processArray(p, N, count, sum);

    // результати
    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    // модифікований масив
    cout << "Modified:\n";
    for (int i = 0; i < N; i++) {
        cout << setw(4) << p[i];
    }
    cout << endl;

    return 0;
}