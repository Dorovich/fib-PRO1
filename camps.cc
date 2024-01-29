#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

int camps (const Matriu& m) {
    int f = m.size(), c = m[0].size();
    int camps = 0;

    for (int i = 0; i < f; i++) {
        int act, last = 0;

        for (int j = 0; j < c; j++) {
            act = m[i][j];
            if (last != act and last == 0) {
                camps++;
                if (i > 0 and act == m[i-1][j]) camps--;
            }
            last = act;
        }
    }

    return camps;
}

int main () {
    int f, c;
    while (cin >> f >> c) {
        Matriu m(f, vector<int> (c));
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) cin >> m[i][j];
        }
        cout << camps(m) << endl;
    }
}