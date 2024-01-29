#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matriu;
typedef vector<vector<int> > Matriu_i;

int maxp (string s, const Matriu& m, const Matriu_i& p) {
    int f = m.size(), c = m[0].size();
    int val = 0, max = 0;

    //buscar filas
    for (int j = 0; j < f; j++) {
        int fit = 0;

        for (int k = 0; k < c; k++) {
            if (s[fit] == m[j][k]) {
                fit++;
                val += p[j][k];
                if (fit == s.size()) {
                    if (val > max) max = val;
                    val = 0;
                }
            }
            else if (fit != s.size()) fit = val = 0;
        }
    }

    //buscar columnas
    for (int j = 0; j < c; j++) {
        int fit = 0;

        for (int k = 0; k < f; k++) {
            if (s[fit] == m[k][j]) {
                fit++;
                val += p[k][j];
                if (fit == s.size()) {
                    if (val > max) max = val;
                    val = 0;
                }
            }
            else if (fit != s.size()) fit = val = 0;
        }
    }

    return max;
}

int main () {
    int f, c, t;
    string s;

    while (cin >> f >> c) {
        Matriu m (f, vector<char> (c));
        Matriu_i p (f, vector<int> (c));

        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) cin >> m[i][j];
        }
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) cin >> p[i][j];
        }

        cin >> t;
        for (int i = 0; i < t; i++) {
            cin >> s;
            int x = maxp(s, m, p);
            if (x == 0) cout << "no" << endl;
            else cout << x << endl;
        }
    }
}