#include <iostream>
#include <vector>
using namespace std;

struct Paraula {
    string text;
    int num;        //numero de veces que aparece en la secuencia (> 0)
};

int main () {
    int n;
    
    while (cin >> n) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
    
        vector<Paraula> p;
        for (int i = 0; i < n; i++) { //calcula cuantas veces aparece cada palabra
            bool found = false;
            for (int j = 0; j < p.size(); j++) {
                if (p[j].text == v[i]) {
                    p[j].num++;
                    found = true;
                }
            }
            if (not found) {
                Paraula x;
                x.text = v[i];
                x.num = 1;
                p.push_back(x);
            }
        }

        for (int i = 1; i < n; i++) { //calcula los digitos que suman las palabras que se repiten igual
            int chars = 0;
            for (int j = 0; j < p.size(); j++) {
                if (i == p[j].num) chars += p[j].text.size();
            }
            if (chars != 0) cout << i << " : " << chars << endl;
        }
        cout << endl;
    }
}