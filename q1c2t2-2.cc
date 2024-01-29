#include <iostream>
#include <vector>
using namespace std;

// Pre: --
// Post: retorna la posició de l'últim element de v amb valor inferior a x,
//       retorna -1 si aquest element no existeix
int last_position_of (const vector<int>& v, double x) {
    int n = v.size(), last = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] < x) last = i;
    }
    return last;
}

int main () {
    int n;
    while (cin >> n) {
        double x = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int numpar = 0;
        for (int i = 0; i < n; i++) {
            if (v[i]%2 == 0) {
                numpar++;
                x += v[i];
            } 
        }
        x /= numpar;

        cout << last_position_of(v, x) << endl;
    }
}