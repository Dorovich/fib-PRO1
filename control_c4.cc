#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

void min_max(const Matriu& mat, int& minim, int& maxim) {
    minim = maxim = mat[0][0];
    int f = mat.size(), c = mat[0].size();
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] > maxim) maxim = mat[i][j];
            if (mat[i][j] < minim) minim = mat[i][j];
        }
    }
}

int main () {
    int f, c, difmax = 0, cont_mat = 0, primera = 1;
    while (cin >> f >> c) {
        cont_mat++;
        Matriu m(f, vector<int> (c));
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) cin >> m[i][j];
        }
        int min, max;
        min_max(m, min, max);
        if (max - min > difmax) {
            difmax = max - min;
            primera = cont_mat;
        }
    }
    cout << "la diferencia maxima es " << difmax << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << primera << endl;
}