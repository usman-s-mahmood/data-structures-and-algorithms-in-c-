#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

int main() 
{
    int num1, num2;
    cout << "Enter first integer for GCD: ";
    cin >> num1;
    cout << "Enter second integer for GCD: ";
    cin >> num2;
    int result = gcd(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is " << result << endl;
    return 0;
}
