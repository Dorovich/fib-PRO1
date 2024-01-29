#include <iostream>
using namespace std;

struct Rectangle {
    int x_esq, x_dre, y_baix, y_dalt;
};

struct Punt {
    double x, y;
};

void llegeix(Rectangle& r) {
    cin >> r.x_esq >> r.x_dre >> r.y_baix >> r.y_dalt;
}

int relacio(const Rectangle& r1, const Rectangle& r2) {
    if (r1.x_esq == r2.x_esq and r1.x_dre == r2.x_dre and r1.y_baix == r2.y_baix and r1.y_dalt == r2.y_dalt) return 4;
    if (r1.x_esq >= r2.x_esq and r1.x_dre <= r2.x_dre and r1.y_baix >= r2.y_baix and r1.y_dalt <= r2.y_dalt) return 1;
    if (r2.x_esq >= r1.x_esq and r2.x_dre <= r1.x_dre and r2.y_baix >= r1.y_baix and r2.y_dalt <= r1.y_dalt) return 2;    

    if (r1.x_esq <= r2.x_esq and r1.x_dre <= r2.x_dre and r1.x_dre >= r2.x_esq) {
        if (r1.y_dalt >= r2.y_dalt and r1.y_baix >= r2.y_baix and r1.y_baix <= r2.y_dalt) return 3;
        if (r1.y_dalt <= r2.y_dalt and r1.y_baix <= r2.y_baix and r1.y_dalt >= r2.y_baix) return 3;
    }
    else if (r1.x_esq >= r2.x_esq and r1.x_dre >= r2.x_dre and r1.x_esq <= r2.x_dre) {
        if (r1.y_dalt >= r2.y_dalt and r1.y_baix >= r2.y_baix and r1.y_baix <= r2.y_dalt) return 3;
        if (r1.y_dalt <= r2.y_dalt and r1.y_baix <= r2.y_baix and r1.y_dalt >= r2.y_baix) return 3;
    }

    return 0;
}

int main () {
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        Rectangle r1, r2;
        llegeix(r1);
        llegeix(r2);
        int comp = relacio(r1, r2);
        if (comp == 0) cout << "els rectangles no intersecten" << endl;
        if (comp == 1) cout << "el primer rectangle es interior al segon" << endl;
        if (comp == 2) cout << "el segon rectangle es interior al primer" << endl;
        if (comp == 3) cout << "els rectangles intersecten" << endl;
        if (comp == 4) cout << "els rectangles son iguals" << endl;
    }
}