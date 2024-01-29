#include <iostream>
#include <vector>
using namespace std;

int suma_digits (int n) {
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main () {
    vector<int> v;
    int n;
    while (cin >> n) v.push_back(n);
    n = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i > 0 and v[i-1]%suma_digits(v[i]) == 0) n++;
    }
    cout << n << endl;
}