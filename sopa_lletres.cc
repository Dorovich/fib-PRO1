#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matriu;

void changeline (Matriu& sopa, int line, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (sopa[line][i] > 'Z') sopa[line][i] += 'A'-'a';
    }
}

void changecolumn (Matriu& sopa, int column, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (sopa[i][column] > 'Z') sopa[i][column] += 'A'-'a';
    }
}

void changediag_1 (Matriu& sopa, int line, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (sopa[line+i][i] > 'Z') sopa[line+i][i] += 'A'-'a';
    }
}

void changediag_2 (Matriu& sopa, int column, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (sopa[i][column+i] > 'Z') sopa[i][column+i] += 'A'-'a';
    }
}

Matriu searchw (const vector<string>& s, const Matriu& m) {
    int x = s.size(), f = m.size(), c = m[0].size();
    Matriu sopa = m;
    for (int i = 0; i < x; i++) {

        //buscar filas
        if (f >= s[i].size()) {
            for (int j = 0; j < f; j++) {
                int fit = 0, begin = 0, end = 0;
                for (int k = 0; k < c; k++) {
                    if (s[i][fit] == m[j][k] or s[i][fit]-'A'-'a' == m[j][k]) {
                        fit++;
                        if (fit == 1) begin = k;
                        if (fit == s[i].size()) {
                            end = k;
                            changeline(sopa, j, begin, end);
                        }
                    }
                    else if (fit != s[i].size()) fit = begin = end = 0;
                }
            }
        }

        //buscar columnas
        if (c >= s[i].size()) {
            for (int j = 0; j < c; j++) {
                int fit = 0, begin = 0, end = 0;
                for (int k = 0; k < f; k++) {
                    if (s[i][fit] == m[k][j] or s[i][fit]-'A'-'a' == m[k][j]) {
                        fit++;
                        if (fit == 1) begin = k;
                        if (fit == s[i].size()) {
                            end = k;
                            changecolumn(sopa, j, begin, end);
                        }
                    }
                    else if (fit != s[i].size()) fit = begin = end = 0;
                }
            }
        }

        //buscar diagonales por filas
        if (f >= s[i].size()) {
            for (int j = 0; j < f; j++) {
                int fit = 0, begin = 0, end = 0;
                for (int k = 0; k < c; k++) {
                    if (j+k < f and (s[i][fit] == m[j+k][k] or s[i][fit]-'A'-'a' == m[j+k][k])) {
                        fit++;
                        if (fit == 1) begin = k;
                        if (fit == s[i].size()) {
                            end = k;
                            changediag_1(sopa, j, begin, end);
                        }
                    }
                    else if (fit != s[i].size()) fit = begin = end = 0;
                }
            }
        }


        //buscar diagonales por columnas
        if (f >= s[i].size()) {
            for (int k = 0; k < c; k++) {
                int fit = 0, begin = 0, end = 0;
                for (int j = 0; j < f; j++) {
                    if (j+k < f and (s[i][fit] == m[j][j+k] or s[i][fit]-'A'-'a' == m[j][j+k])) {
                        fit++;
                        if (fit == 1) begin = j;
                        if (fit == s[i].size()) {
                            end = j;
                            changediag_2(sopa, k, begin, end);
                        }
                    }
                    else if (fit != s[i].size()) fit = begin = end = 0;
                }
            }
        }
    }
    return sopa;
}

int main () {
    int x, f, c;
    bool skipline = true;
    
    while (cin >> x >> f >> c) {
        vector<string> w(x);
        for (int i = 0; i < x; i++) cin >> w[i];
        
        Matriu m (f, vector<char> (c));
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) cin >> m[i][j];
        }

        if (not skipline) cout << endl;
        else skipline = false;

        Matriu M = searchw (w, m);
        for (int i = 0; i < f; i++) {
            bool skip = true;
            for (int j = 0; j < c; j++) {
                if (not skip) cout << ' ';
                else skip = false; 
                cout << M[i][j];
            }
            cout << endl;
        }
    }
}