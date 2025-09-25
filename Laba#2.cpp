#include <iostream> 
#include <cmath> 

using namespace std;

int main()
{
    double n;  // вхідний параметр 
    double z1; // результат обчислення 1-го виразу 
    double z2; // результат обчислення 2-го виразу 

    cout << "n = "; cin >> n;

    z1 = (cos(n)+sin(n))/(cos(n) - sin(n));
    z2 = tan(2 * n) + 1.0 / 1/cos(2 * n);

    cout << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cin.get();
    return 0;
}