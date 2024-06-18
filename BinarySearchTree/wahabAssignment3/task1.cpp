#include <iostream>
using namespace std;

int Series(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return 4 * Series(n - 1) + 1;
}

int main() {
    int n = 5; // Example value for n
    cout << "Series(" << n << ") = " << Series(n) << endl;
    return 0;
}
