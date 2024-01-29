#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Sudoku;

bool es_valid (const Sudoku& s) {
    for (int b1 = 0; b1 < 9; b1 += 3) {
        for (int b2 = 0; b2 < 9; b2 += 3) {
            vector<int> v(9, 0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) v[s[i+b1][j+b2]-1]++;
            }
            for (int i = 0; i < 9; i++) {
                if (v[i] != 1) return false;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        vector<int> h(9, 0);
        vector<int> v(9, 0);
        for (int j = 0; j < 9; j++) {
            h[s[i][j]-1]++;
            v[s[j][i]-1]++;
        }
        for (int j = 0; j < 9; j++) {
            if (h[j] != 1 or v[j] != 1) return false;
        }
    }

    return true;
}

int main () {
    int n;
    cin >> n;
    for (int x = 0; x < n; x++) {
        Sudoku s (9, vector<int> (9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cin >> s[i][j];
        }
        if (es_valid(s)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}