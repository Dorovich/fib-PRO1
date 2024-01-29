#include <iostream>
#include <vector>
using namespace std;

struct Estudiant {
    int dni;
    string nom;
    double nota;        // La nota és un valor entre 0 i 10, o -1 que representa NP
    bool repetidor;
};

void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj) {
    int total = -1;
    for (int i = 0; i < es.size(); i++) {
        if (not es[i].repetidor and es[i].nota != -1) {
            if (total == -1) {
                min = max = es[i].nota;
                total++;
            }
            else {
                if (es[i].nota > max) max = es[i].nota;
                else if (es[i].nota < min) min = es[i].nota;
            }
            mitj += es[i].nota;
            total++;
        }
    }
    if (total == -1.0) min = max = mitj = total;
    else {
        if (max == 0) mitj = 0;
        else mitj /= total*1.0;
    }
}

int main () {
    int n;
    cin >> n;
    vector<Estudiant> es(n);
    for (int i = 0; i < n; i++) cin >> es[i].nota;
    double min, max, mitj;
    informacio(es, min, max, mitj);
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "mitj: " << mitj << endl;
}