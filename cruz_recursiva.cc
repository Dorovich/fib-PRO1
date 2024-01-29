#include <iostream>
using namespace std;

int pot (int n, int e) {
    int x = 1;
    while (e > 0) {
        x *= n;
        e--;
    }
    return x;
}

void creu (int n, int fila, int columna, int ne) {    
    if (columna == 0) {
        cout << '|';
    }
    else if (columna >= ne and fila < ne) {
        columna -= ne;
        fila++;
        cout << '|';
    }

    if (n == 1) {
        if (fila%3 == 0 or fila%3 == 2) {
            if (columna%3 == 1) cout << '|';
            else cout << ' ';
        }
        else if (fila%3 == 1) {
            if (columna%3 == 0 or columna%3 == 2) cout << '-';
            else cout << 'O';
        }
        creu(n, fila, columna+1, ne);
    }
    else {
        creu(n-1, fila, columna, ne);
        creu(n-1, fila, columna+ne/3, ne);
        creu(n-1, fila, columna+2*ne/3, ne);
    }
}

int main () {
    int n;
    cin >> n;
    int ne = pot(3, n);
    creu(n, 0, 0, ne);
}