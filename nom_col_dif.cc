#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;
typedef vector<int> Linia;

Matriu read_matrix (int f, int c) {
    Matriu m(f, Linia(c));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) cin >> m[i][j];
    }
    return m;
}

//pre: dos index de columnes de la matriu m. 0 <= a,b <= m.size()
//post: true si la columna a es diferent a la b, false altrament
bool is_different (int a, int b, const Matriu& m) {
    if (a != b) {
        for (int i = 0; i < m.size(); i++) {
            if (m[i][a] != m[i][b]) return true;
        }
    }
    return false;
}

int main () {
    int f, c;
    while (cin >> f >> c) {
        Matriu m = read_matrix(f, c);
        int total = 0;
        for (int i = 0; i < m[0].size(); i++) {
            int j = i-1;
            bool repetida = false; 
            while (not repetida and j >= 0) {
                repetida = not is_different(i, j, m);
                j--;
            }
            if (not repetida) total++;
        }
        cout << total << endl;
    }
}