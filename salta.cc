#include <iostream>
#include <vector>
using namespace std;

string sortida (int p, vector<int>& v) {
    int i = p;
    while (i >= 0 and i < v.size()) {
        if (i+v[p] == i) return "mai";
        i += v[p];
    }
    if (i < 0) return "esquerra";
    else return "dreta";
}

int main () {
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    string s = sortida(p, v);
    cout << s << endl;
}