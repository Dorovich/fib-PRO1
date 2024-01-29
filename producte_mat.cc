#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

Matriu producte (const Matriu& a, const Matriu& b) {
    int n = a.size(), p = b.size(), q = b[0].size();
    Matriu m (n, vector<int> (q, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                m[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    return m;
}

int main () {
    int na, nb;
    cin >> na >> nb;
    Matriu a (na, vector<int> (na)), b (nb, vector<int> (nb));
    Matriu m = producte(a, b);
    
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < na; j++) cin >> a[i][j];
    }
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < nb; j++) cin >> b[i][j];
    }
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) cout << m[i][j];
        cout << endl;
    }
}