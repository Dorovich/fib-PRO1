#include <iostream>
using namespace std;

bool is_power_2 (int n) {
    if (n == 0) return false;
    else if (n == 2 or n == 1) return true;
    else if (n%2 == 0) return is_power_2(n/2);
    else return false;
}

int main () {
    int n, pos = 0;
    bool found = false;
    while (not found and cin >> n and n != -1) {
        pos++;
        found = is_power_2(n);
    }
    if (found) cout << pos << endl;
    else cout << '0' << endl;
}