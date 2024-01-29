#include <iostream>
using namespace std;

struct Racional {
    int num, den;
};

int mcd (int a, int b) {
    while (a != 0 and b != 0) {
        if (a >= b) a -= b;
        else b -= a;
    }
    if (a == 0) return b;
    else return a;
}

Racional racional(int n, int d) {
    Racional r;
    if (n == 0) {
        r.num = n;
        r.den = 1;
        return r;
    }
    bool neg = false;
    if (d < 0) {
        d *= -1;
        neg = true;
    }
    if (n < 0) {
        n *= -1;
        if (neg) neg = false;
        else neg = true;
    }
    int x = mcd(n, d);
    if (neg) n *= -1;
    r.num = n/x;
    r.den = d/x;
    return r;
}

int main () {
    Racional r;
    while (cin >> r.num >> r.den) {
        r = racional(r.num, r.den);
        cout << r.num << ' ' << r.den << endl;
    }
}