#include <iostream>
#include <vector>
using namespace std;

/*
int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (v.size() == 0 or x < v[esq] or x > v[dre] or esq > dre) return -1;
    else {
        int m = (esq+dre)/2;
        if (x > v[m]) return posicio(x, v, m+1, dre);
        if (x < v[m]) return posicio(x, v, esq, m-1);
        return m;
    }
}

vector<double> diferencia (const vector<double>& v1, const vector<double>& v2) {
    vector<double> dif;
    for (int i = 0; i < v1.size(); i++) {
        if (i == 0 or v1[i] != v1[i-1]) {
            int p = posicio(v1[i], v2, 0, v2.size()-1);
            if (p == -1) dif.push_back(v1[i]);
        }
    }
    return dif;
}
*/

//pre: x, un vector ordenado de menor a mayor v, la posicion donde empezar pos
//post: true si x esta en v a partir de pos, false en caso contrario. deja su posicion+1 en pos
bool troba (double x, const vector<double>& v, int& pos) {
    while (pos < v.size() and v[pos] <= x) {
        if (x == v[pos]) {
            pos++;
            return true;
        }
        else pos++;
    }
    return false;
}

vector<double> diferencia (const vector<double>& v1, const vector<double>& v2) {
    vector<double> dif;
    int pos = 0;
    for (int i = 0; i < v1.size(); i++) {
        if ((i == 0 or v1[i] != v1[i-1]) and not troba(v1[i], v2, pos)) dif.push_back(v1[i]);
    }
    return dif;
}

int main () {
    int n1, n2;
    cin >> n1 >> n2;
    vector<double> v1(n1), v2(n2), d;
    for (int i = 0; i < n1; i++) cin >> v1[i];
    for (int i = 0; i < n2; i++) cin >> v2[i];
    d = diferencia(v1, v2);
    for (int i = 0; i < d.size(); i++) {
        if (i == 0) cout << endl;
        else cout << ' ';
        cout << d[i];
    }
    cout << endl;
}