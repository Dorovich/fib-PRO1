#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    while (cin >> n) { 
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int total = 0;
        for (int i = 0; i < n; i++) {
            int j = i-1, count = 0;
            while (count < v[i] and j >= 0) {
                count += v[j];
                j--;
            }
            if (count == v[i]) total++;
        }
        cout << total << endl;
    }
}