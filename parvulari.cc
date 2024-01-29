#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Profesor {
    string nom;
    int car, pas;
};

bool esMillor (Profesor a, Profesor b) {
    if (a.car > b.car) return true;
    if (a.car < b.car) return false;
    if (a.pas > b.pas) return true;
    if (a.pas < b.pas) return false;
    if (a.nom.size() < b.nom.size()) return true;
    if (a.nom.size() > b.nom.size()) return false;
    return a.nom < b.nom;
}

int main () {
    int n1;
    cin >> n1;
    for (int x1 = 0; x1 < n1; x1++) {
        int n2;
        cin >> n2;
        vector<Profesor> v(n2);
        for (int x2 = 0; x2 < n2; x2++) cin >> v[x2].nom >> v[x2].car >> v[x2].pas;
        
        if (n2 != 1) sort(v.begin(), v.end(), esMillor);
        
        for (int x2 = 0; x2 < n2; x2++) cout << v[x2].nom << endl;
        cout << endl;
    }
}