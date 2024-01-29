#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> Llista;

Llista read_words (int n) {
    Llista w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    return w;
}

bool is_prefix (string ref, string s) {
    if (s == ref) return true;
    else if (s.size() <= ref.size()) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ref[i]) return false;
        }
        return true;
    }
    return false;
}

int main () {
    int n, linea = 0;
    while (cin >> n) {
        linea++;
        int total = 1;
        string ref;
        cin >> ref;
        Llista w = read_words(n-1);
        for (int i = 0; i < n-1; i++) {
            if (is_prefix(ref, w[i])) total++;
        }
        cout << "Linea " << linea << ": " << total << " - " << ref << endl;
    }
}