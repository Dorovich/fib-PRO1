#include <iostream>
#include <vector>
using namespace std;

struct Enviament {
    string dni;
    string exer;
    int temps;
    string res;
};

typedef vector<Enviament> Historia;

void env_verds (const Historia& h, vector<string> dnis, int& data) {
    int n = h.size(), m = dnis.size();
    
    vector<int> num(m, 0);
    for (int i = 1; i < n; i++) {
        if (h[i].res == "verd") {
            for (int j = 0; j < m; j++) {
                if (dnis[j] == h[i].dni) num[j]++;
            }
        }
    }

    data = 0;
    string alu = h[0].dni;
    for (int j = 0; j < m; j++) {
        if (num[j] > data) {
            data = num[j];
            alu = dnis[j];
        }
    }

    if (data != 0) cout << alu << " (" << data << ")" << endl;
    else cout << "-" << endl;
}

void exe_verds (const Historia& h, vector<string> dnis, vector<string> exercicis, int& data) {
    int n = h.size(), m = dnis.size(), p = exercicis.size();
    
    vector<int> num(m, 0);
    for (int i = 0; i < n; i++) {
        
        vector<bool> fet(p, false);
        for (int j = 0; j < m; j++) {
            if (h[i].dni == dnis[k] and h[i].res == "verd" and not fet[k]) {
                fet[k] = true;
                num[k]++;
            }
        }
    }

    data = 0;
    string alu = h[0].dni;
    for (int j = 0; j < m; j++) {
        if (num[j] > data) {
            data = num[j];
            alu = dnis[j];
        }
    }

    if (data != 0) cout << alu << " (" << data << ")" << endl;
    else cout << "-" << endl;
}

/*void exe_vermells (const Historia& h, vector<string> dnis, int& data) 
    int n = h.size();
}

void exe_intent (const Historia& h, vector<string> dnis, int& data) {
    int n = h.size();
}

void ult_env (const Historia& h, vector<string> dnis) {
    int n = h.size();
}*/

int main () {
    int n, data;
    cin >> n;
    Historia h(n);
    for (int i = 0; i < n; i++) cin >> h[i].dni >> h[i].exer >> h[i].temps >> h[i].res;
    
    vector<string> dnis(1, h[0].dni);           //conjunt del dnis
    for (int i = 0; i < n; i++) {
        bool nuevo = true;
        for (int j = 0; j < dnis.size(); j++) {
            if (dnis[j] == h[i].dni) nuevo = false;
        }
        if (nuevo) dnis.push_back(h[i].dni);
    }

    vector<string> exercicis(1, h[0].exer);     //conjunt del exercicis
    for (int i = 0; i < n; i++) {
        bool nuevo = true;
        for (int j = 0; j < exercicis.size(); j++) {
            if (exercicis[j] == h[i].exer) nuevo = false;
        }
        if (nuevo) exercicis.push_back(h[i].exer);
    }

    cout << "alumne amb mes enviaments verds:     ";
    env_verds(h, dnis, data);
    cout << "alumne amb mes exercicis verds:      ";
    exe_verds(h, dnis, exercicis, data);
    /*cout << "alumne amb mes exercicis vermells:   ";
    exe_vermells(h, dnis, data);
    cout << "alumne amb mes exercicis intentats:  ";
    exe_intent(h, dnis, data);
    cout << "alumne que ha fet l'ultim enviament: ";
    ult_env(h, dnis);*/
}