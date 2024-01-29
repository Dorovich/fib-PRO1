#include <iostream>
#include <vector>
using namespace std;

int posicio_maxim (const vector<double>& v, int m) {
    double max = v[0], pos_max = 0;
    for (int i = 1; i <= m; i++) {
        if (v[i] > max) {
            max = v[i];
            pos_max = i;
        }
    }
    return pos_max;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << posicio_maxim(v, m) << endl;
}