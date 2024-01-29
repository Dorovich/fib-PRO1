#include <iostream>
using namespace std;

struct Rellotge {
    int h;      // hores (0<=h<24)
    int m;      // minuts (0<=m<60)
    int s;      // segons (0<=s<60)
};

Rellotge mitja_nit() {
    Rellotge x;
    x.h = x.m = x.s = 0;
    return x;
}

void incrementa(Rellotge& r) {
    r.s++;
    if (r.s >= 60) {
        r.s -= 60;
        r.m++;
    }
    if (r.m >= 60) {
        r.m -= 60;
        r.h++;
    }
    if (r.h >= 24) r.h -= 24;
}

void escriu(const Rellotge& r) {
    if (r.h < 10) cout << '0' << r.h << ":";
    else cout << r.h << ":";
    if (r.m < 10) cout << '0' << r.m << ":";
    else cout << r.m << ":";
    if (r.s < 10) cout << '0' << r.s << endl;
    else cout << r.s << endl;
}

int main () {
    Rellotge m = mitja_nit();
    m.h = 23;
    m.m = m.s = 59;
    for (int i = 0; i < 1; i++) incrementa(m);
    escriu(m);
}