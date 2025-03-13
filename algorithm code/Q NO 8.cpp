#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1); // Fix: Add '*' for multiplication
}

int main() {
    int n = 5;
    cout << "Factorial(" << n << ") = " << factorial(n) << endl;
    return 0;
}

