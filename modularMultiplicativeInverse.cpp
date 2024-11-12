#include <iostream>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;  // Store results of recursive call
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

// Function to find modular inverse of a under modulo m
// Assumes that a and m are coprime
int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, x, y);
    if (g != 1) {
        cout << "Inverse doesn't exist";
        return -1;
    } else {
        // m is added to handle negative x
        return (x % m + m) % m;
    }
}

int main() {
    int a, m;
    cout << "Enter a and m: ";
    cin >> a >> m;
    int inverse = modInverse(a, m);
    if (inverse != -1) {
        cout << "Modular multiplicative inverse is " << inverse << endl;
    }
    return 0;
}
