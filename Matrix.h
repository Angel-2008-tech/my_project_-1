#pragma once

class Matrix {
private:
    float** data;
    int rows;
    int cols;

public:
    // Константні методи зчитування
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    float** getData() const { return data; }

    // Методи запису з перевіркою коректності
    bool setRows(int r);
    bool setCols(int c);
    bool setData(float** d);

    // Обов'язкові методи
    bool Init(int r, int c);
    void Read();
    void Display() const;

    // Методи варіанту
    void setElement(int r, int c, float value);
    float getElement(int r, int c) const;

    float getMin() const;
    float getMax() const;
    float getSum() const;
};
