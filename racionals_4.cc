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

int mcm (int a, int b) {
    int x = a*b;
    if (x < 0) x *= -1;
    return x/mcd(a, b);
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
    Racional r, rx;
    string op;

    cin >> r.num >> r.den;
    r = racional(r.num, r.den);
    if (r.den != 1) cout << r.num << "/" << r.den << endl;
    else cout << r.num << endl;

    while (cin >> op >> rx.num >> rx.den) {
        rx = racional(rx.num, rx.den);
        
        if (op == "suma") {
            int m = mcm(r.den, rx.den);
            r.num *= m/r.den;
            r.den = m;
            rx.num *= m/rx.den;
            r.num += rx.num;
        }
        else if (op == "resta") {
            int m = mcm(r.den, rx.den);
            r.num *= m/r.den;
            r.den = m;
            rx.num *= m/rx.den;
            r.num -= rx.num;
        }
        else if (op == "multiplica") {
            r.num *= rx.num;
            r.den *= rx.den;
        }
        else if (op == "divideix") {
            r.num *= rx.den;
            r.den *= rx.num;
        }
        
        r = racional(r.num, r.den);
        if (r.den != 1) cout << r.num << "/" << r.den << endl;
        else cout << r.num << endl;
    }
}