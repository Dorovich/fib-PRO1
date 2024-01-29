#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

bool creix (const Matriu& m, int x, int y) {
   int f = m.size(), c = m[0].size();

   if (x > 0 and y > 0) { //superior esquerra
        int act = m[x][y];
        int i = x-1, j = y-1;
        while (i >= 0 and j >= 0) {
            if (act >= m[i][j]) return false;
            else {
                act = m[i][j];
                i--;
                j--;
            }
        }
   }
   if (x < f and y > 0) { //inferior esquerra
        int act = m[x][y];
        int i = x+1, j = y-1;
        while (i < f and j >= 0) {
            if (act >= m[i][j]) return false;
            else {
                act = m[i][j];
                i++;
                j--;
            }
        }
   }
   if (x > 0 and y < c) { //superior dreta
        int act = m[x][y];
        int i = x-1, j = y+1;
        while (i >= 0 and j < c) {
            if (act >= m[i][j]) return false;
            else {
                act = m[i][j];
                i--;
                j++;
            }
        }
   }
   if (x < f and y < c) { //inferior dreta
        int act = m[x][y];
        int i = x+1, j = y+1;
        while (i < f and j < c) {
            if (act >= m[i][j]) return false;
            else {
                act = m[i][j];
                i++;
                j++;
            }
        }
   }
   return true;
}

int main () {
    int f, c;
    while (cin >> f >> c) {
        Matriu m(f, vector<int> (c));
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) cin >> m[i][j];
        }
        int x, y;
        cin >> x >> y;
        if (creix(m, x, y)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}