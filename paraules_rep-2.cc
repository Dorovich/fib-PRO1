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
    
        vector<int> chars(n+1, 0);
        vector<Paraula> p;
        for (int i = 0; i < n; i++) { //calcula cuantas veces aparece cada palabra
            bool found = false;
            for (int j = 0; j < p.size(); j++) {
                if (p[j].text == v[i]) {
                    p[j].num++;
                    found = true;
                    chars[p[j].num-1] -= v[i].size();
                    chars[p[j].num] += v[i].size();
                }
            }
            if (not found) {
                Paraula x;
                x.text = v[i];
                x.num = 1;
                chars[1] += v[i].size();
                p.push_back(x);
            }
        }

        for (int i = 1; i < n+1; i++) {
            if (chars[i] != 0) cout << i << " : " << chars[i] << endl;
        }
        cout << endl;
    }
}