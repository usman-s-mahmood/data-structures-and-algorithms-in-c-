#include <iostream>

using namespace std;

double power(double base, int exponent) {
    
    if (exponent == 0)
        return 1;
    if (exponent < 0)
        return 1 / power(base, -exponent);
    return base * power(base, exponent - 1);
}

int main() 
{
    double base;
    int exponent;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    double result = power(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;
    return 0;
}
