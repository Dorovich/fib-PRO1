#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriz;

// Pre: f > 0, c > 0; a l'entrada hi ha una matriu d'enters de dimensions f*c
// Post: retorna la matriu d'enters que hi havia a l'entrada
Matriz read_matriz(int f, int c) {
    Matriz m(f, Fila(c));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) cin >> m[i][j];
    }
    return m;
}

int submatriz_sup (const Matriz& m, int pos_i, int pos_j) {
    int c = m[0].size(), count = 0;
    for (int i = 0; i <= pos_i; i++) {
        for (int j = pos_j; j < c; j++) count += m[i][j];
    }
    return count;
}

int submatriz_inf (const Matriz& m, int pos_i, int pos_j) {
    int f = m.size(), count = 0;
    for (int i = pos_i; i < f; i++) {
        for (int j = 0; j <= pos_j; j++) count += m[i][j];
    }
    return count;
}

int main () {
    int f, c;
    cin >> f >> c;
    Matriz m = read_matriz(f, c);
    int pos_i, pos_j;
    while (cin >> pos_i >> pos_j) {
        int sup = submatriz_sup(m, pos_i, pos_j), inf = submatriz_inf(m, pos_i, pos_j);
        if (sup == inf) cout << "si: " << sup << endl;
        else cout << "no: " << sup << ", " << inf << endl;
    }
}