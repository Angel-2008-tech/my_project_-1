#include <iostream>
#include <cmath>
using namespace std;

// прототип функції h
double h(double a, double b);

int main()
{
    double s, t;

    cout << "s = ";
    cin >> s;
    cout << "t = ";
    cin >> t;

    // h(t^2,1)
    double h1 = h(t * t, 1);

    // h(1, t*s^2)
    double h2 = h(1, t * s * s);

    // h(s, t)
    double h3 = h(s, t);

    // Обчислення виразу
    double result = (pow(h1, 3) + h2) / (1 + pow(h3, 2));

    cout << "Result = " << result << endl;

    return 0;
}

// визначення функції h(a,b)
double h(double a, double b)
{
    return a * a * sin(b) + b * b * cos(a);
}