// Pay.h
#pragma once

class Pay {
private:
    double first; // оклад
    int second;   // кількість відпрацьованих днів

public:
    // Константні методи зчитування (геттери)
    double GetFirst() const { return first; }
    int GetSecond() const { return second; }

    // Методи запису (сеттери) з перевіркою
    bool SetFirst(double value);
    bool SetSecond(int value);

    // Обов'язкові методи
    bool Init(double f, int s);
    void Read();
    void Display() const;

    // Специфічний метод для варіанту 14
    double summa(int work_days_in_month) const;
};
