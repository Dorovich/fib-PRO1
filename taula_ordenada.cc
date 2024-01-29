#include <iostream>
#include <vector>
using namespace std;

void insereix(vector<double>& v) {
    if (v.size() > 1) {
        double x = v[v.size()-1];
        bool found = false;
        for (int i = 0; i < v.size(); i++) {
            if (x <= v[i]) found = true;
            if (found) {
                double aux = v[i];
                v[i] = x;
                x = aux;
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    insereix(v);
    for(int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << v[i];
    }
    cout << endl;
}