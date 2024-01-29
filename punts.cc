#include <iostream>
#include <cmath>
using namespace std;

struct Punt {
    double x, y;
};

double distancia(const Punt& a, const Punt& b) {
    double x = b.x-a.x;
    double y = b.y-a.y;
    return sqrt(x*x+y*y);
}

int main () {
    Punt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << distancia(a, b) << endl;
}