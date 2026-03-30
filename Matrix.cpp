#include "Matrix.h"
#include <iostream>

using namespace std;

bool Matrix::setRows(int r) {
    if (r > 0) {
        rows = r;
        return true;
    }
    else {
        rows = 0;
        return false;
    }
}

bool Matrix::setCols(int c) {
    if (c > 0) {
        cols = c;
        return true;
    }
    else {
        cols = 0;
        return false;
    }
}

bool Matrix::setData(float** d) {
    data = d;
    return true;
}

bool Matrix::Init(int r, int c) {
    // ѕерев≥рка лише через методи setRows та setCols
    if (setRows(r) && setCols(c)) {
        data = new float* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new float[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0.0f; // ≥н≥ц≥ал≥зац≥€ нул€ми
            }
        }
        return true;
    }
    return false;
}

void Matrix::Read() {
    int r, c;
    do {
        cout << "¬вед≥ть к≥льк≥сть р€дк≥в (> 0): ";
        cin >> r;
        cout << "¬вед≥ть к≥льк≥сть стовпц≥в (> 0): ";
        cin >> c;
    } while (!Init(r, c));

    cout << "¬вед≥ть елементи матриц≥:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "ћатриц€[" << i << "][" << j << "] = ";
            cin >> data[i][j];
        }
    }
}

void Matrix::Display() const {
    cout << endl << "ћатриц€ (" << rows << "x" << cols << "):" << endl;
    if (rows <= 0 || cols <= 0 || data == nullptr) {
        cout << "ћатриц€ порожн€." << endl;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::setElement(int r, int c, float value) {
    if (r >= 0 && r < rows && c >= 0 && c < cols && data != nullptr) {
        data[r][c] = value;
    }
}

float Matrix::getElement(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols && data != nullptr) {
        return data[r][c];
    }
    return 0.0f;
}

float Matrix::getMin() const {
    if (rows <= 0 || cols <= 0 || data == nullptr) return 0.0f;
    float min_val = data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] < min_val) {
                min_val = data[i][j];
            }
        }
    }
    return min_val;
}

float Matrix::getMax() const {
    if (rows <= 0 || cols <= 0 || data == nullptr) return 0.0f;
    float max_val = data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] > max_val) {
                max_val = data[i][j];
            }
        }
    }
    return max_val;
}

float Matrix::getSum() const {
    if (rows <= 0 || cols <= 0 || data == nullptr) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += data[i][j];
        }
    }
    return sum;
}