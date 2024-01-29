#include <iostream>
#include <vector>
using namespace std;

vector<bool> garbell (int tamany) {
    vector<bool> g(tamany+1, true);
    g[0] = g[1] = false;
    for (int i = 2; i <= tamany; i++) {
        if (g[i]) {
            for (int j = i*i; j <= tamany; j += i) g[j] = false;
        }
    }
    return g;
}

int main () {
    vector<bool> g = garbell(1000);
    int n;
    while (cin >> n) {
        if (g[n]) cout << n << " es primer" << endl;
        else cout << n << " no es primer" << endl;
    }
}