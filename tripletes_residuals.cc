#include <iostream>
using namespace std;

int main () {
    int n, total = 0;
    while (cin >> n) {
        int count = 0, v1, v2, v3;
        cin >> v1 >> v2;
        n -= 2;
        while (n > 0) {
            cin >> v3;
            if (v1%v2 == v3) count++;
            v1 = v2;
            v2 = v3;
            n--;
        }
        
        cout << count << endl;
        total += count;
    }
    cout << "Total: " << total << endl;
}