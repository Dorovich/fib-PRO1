#include <iostream>
#include <cmath>
using namespace std;

struct Punt {
    double x, y;
};

struct Cercle {
    Punt centre;
    double radi;
};

double distancia(const Punt& a, const Punt& b) {
    double x = b.x-a.x;
    double y = b.y-a.y;
    return sqrt(x*x+y*y);
}

void desplaca(Punt& p1, const Punt& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
}

void escala(Cercle& c, double esc) {
    c.radi *= esc;
}

void desplaca(Cercle& c, const Punt& p) {
    desplaca(c.centre, p);
}

bool es_interior(const Punt& p, const Cercle& c) {
    if (distancia(p, c.centre) < c.radi) return true;
    return false;
}

int main () {}