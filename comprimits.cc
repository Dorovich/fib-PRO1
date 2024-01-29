#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Parell {
    int valor;                           // Diferent de zero
    int pos;                             // Més gran o igual que zero
};

typedef vector<Parell> Vec_Com;          // Ordenat per pos!
     
Vec_Com suma(const Vec_Com& v1, const Vec_Com& v2) {
    Vec_Com suma;
    int i = 0, j = 0;
    while (i < v1.size() and j < v2.size()) {
        if (v1[i].pos == v2[j].pos) {
            Parell p;
            p.pos = v1[i].pos;
            p.valor = v1[i].valor + v2[j].valor;
            if (p.valor != 0) suma.push_back(p);
            i++;
            j++;
        }
        else if (v1[i].pos < v2[j].pos) {
            suma.push_back(v1[i]);
            i++;
        }
        else if (v1[i].pos > v2[j].pos) {
            suma.push_back(v2[j]);
            j++;
        }
    }
    if (i < v1.size()) {
        suma.push_back(v1[i]);
        i++;
    }
    if (j < v2.size()) {
        suma.push_back(v2[j]);
        j++;
    }
    return suma;
}

void llegeix(Vec_Com& v) {
    int n;
    char tmp_c;
    cin >> n;
    Vec_Com tmp_v(n);
    for (int i = 0; i < n; i++) cin >> tmp_v[i].valor >> tmp_c >> tmp_v[i].pos;
    v = tmp_v;
}

int main () {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
        Vec_Com p1, p2, sum;
        llegeix(p1);
        llegeix(p2);
        sum = suma(p1, p2);
        cout << sum.size();
        for (int i = 0; i < sum.size(); i++) cout << ' ' << sum[i].valor << ';' << sum[i].pos;
        cout << endl;
    }
}