#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
    Complex a, b(-4), c(23.0, 45.9);
	
    cout << a << ", " << b << ", " << c << endl;
    a = b + c;
    cout << "A = B + C, A = " << a << endl;
    Complex m = b - c;

    cout << "M = B - C, M = " << m << endl;
    cout << "M * A=" << m * a << endl;
    cout << "M / 4.45 = " << m / 4.45 << endl;

    Complex d;

    cout << "Enter complex number D = ";
    cin >> d;
    a += c + d;
    cout << "D = " << d << "\nA = " << a << endl;

    return 0;
}
