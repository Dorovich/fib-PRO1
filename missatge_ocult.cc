#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matriu;

struct Coord {
    int x, y;
};

Coord seguentD (const Coord& p, int n) {
    Coord new_p;
    new_p.x = p.x-1;
    new_p.y = p.y+1;
    if (new_p.x == n-2 and new_p.y == n) {
        new_p.x = new_p.y = 0;
    }
    else if (new_p.y == n) {
        int aux = new_p.x;
        new_p.x = new_p.y-1;
        new_p.y = aux+2;
    }
    else if (new_p.x < 0) {
        new_p.x = new_p.y;
        new_p.y = 0;
    }
    return new_p;
}

int main () {
    int n, d, l;
    Coord p;
    while (cin >> n >> d >> l >> p.x >> p.y) {
        Matriu m (n, vector<char> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> m[i][j];
        }

        bool got_X = false;
        for (int i = 0; i < l; i++) {
            char c = m[p.x][p.y];
            if (c == 'X') {
                if (not got_X) got_X = true;
                else {
                    cout << ' ';
                    got_X = false;
                }
            }
            else {
                if (got_X) {
                    cout << 'X';
                    got_X = false;
                }
                cout << c;
            }
            for (int j = 0; j <= d; j++) p = seguentD(p, n);
        }

        cout << endl;
    }
}