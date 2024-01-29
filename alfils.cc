#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<bool> > Tauler;

void buscalfil (const Tauler& t, int fila, int columna) {
   int filas = t.size(), columnas = t[0].size();

   if (fila > 0 and columna > 0) { //superior esquerra
        int i = fila-1, j = columna-1;
        bool found = false;
        while (not found and i >= 0 and j >= 0) {
            if (t[i][j]) {
                cout << "(" << fila+1 << "," << columna+1 << ")<->(" << i+1 << "," << j+1 << ")" << endl;
                found = true;
            }
            else {
                i--;
                j--;
            }
        }
   }
   if (fila < filas and columna > 0) { //inferior esquerra
        int i = fila+1, j = columna-1;
        bool found = false;
        while (not found and i < filas and j >= 0) {
            if (t[i][j]) {
                cout << "(" << fila+1 << "," << columna+1 << ")<->(" << i+1 << "," << j+1 << ")" << endl;
                found = true;
            }
            else {
                i++;
                j--;
            }
        }
   }
   if (fila > 0 and columna < columnas) { //superior dreta
        int i = fila-1, j = columna+1;
        bool found = false;
        while (not found and i >= 0 and j < columnas) {
            if (t[i][j]) {
                cout << "(" << fila+1 << "," << columna+1 << ")<->(" << i+1 << "," << j+1 << ")" << endl;
                found = true;
            }
            else {
                i--;
                j++;
            }
        }
   }
   if (fila < filas and columna < columnas) { //inferior dreta
        int i = fila+1, j = columna+1;
        bool found = false;
        while (not found and i < filas and j < columnas) {
            if (t[i][j]) {
                cout << "(" << fila+1 << "," << columna+1 << ")<->(" << i+1 << "," << j+1 << ")" << endl;
                found = true;
            }
            else {
                i++;
                j++;
            }
        }
   }
}

int main () {
    int f, c;
    cin >> f >> c;
    Tauler t (f, vector<bool> (c, false));
    char x;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cin >> x;
            if (x == 'X') t[i][j] = true;
        }
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (t[i][j]) buscalfil(t, i, j);
        }
    }
}