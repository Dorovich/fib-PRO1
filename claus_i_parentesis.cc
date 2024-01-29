#include <iostream>
using namespace std;

int main () {
    string x;
    while (cin >> x) {
        int c = 0, p = 0, i = 0;
        int last_c = c, last_p = p;
        bool error = false;
        while (not error and i < x.size()) {
            if (x[i] == '[') c++;
            else if (x[i] == ']') c--;
            else if (x[i] == ')') p--;
            else if (x[i] == '(') p++;

            if (c < 0 or p < 0) error = true;
            else if (last_c > p and c < last_c) error = true;
            else if (last_p > c and p < last_p) error = true;

            last_c = c;
            last_p = p;
            i++;
        }
        if (error or c != 0 or p != 0) cout << "no" << endl;
        else cout << "si" << endl;
    }
}