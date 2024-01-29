#include <iostream>
using namespace std;

struct Fraccio {
    int num, den;   // sempre estrictament positius
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

Fraccio fraccio(int n, int d) {
    Fraccio r;
    if (n == 0) {
        r.num = n;
        r.den = 1;
        return r;
    }
    int x = mcd(n, d);
    r.num = n/x;
    r.den = d/x;
    return r;
}

Fraccio suma(const Fraccio& x, const Fraccio& y) {
    Fraccio f;
    f.num = x.num;
    int m = mcm(x.den, y.den);
    f.num *= m/x.den;
    f.num += y.num*(m/y.den);
    f.den = m;
    return f;
}

int main () {
    Fraccio f, act;
    char c;
    cin >> f.num >> c >> f.den >> c;
    f = fraccio(f.num, f.den);
    while (cin >> act.num >> c >> act.den >> c) {
        act = fraccio(act.num, act.den);
        f = suma(f, act);
        f = fraccio(f.num, f.den);
    }
    cout << f.num << "/" << f.den << endl;
}