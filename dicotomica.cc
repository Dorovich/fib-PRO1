#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (v.size() == 0 or x < v[esq] or x > v[dre] or esq > dre) return -1;
    else {
        int m = (esq+dre)/2;
        if (x > v[m]) return posicio(x, v, m+1, dre);
        if (x < v[m]) return posicio(x, v, esq, m-1);
        return m;
    }
}

int main () {
    double x, n;
    cin >> x >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << posicio(x, v, 0, n-1) << endl;
}