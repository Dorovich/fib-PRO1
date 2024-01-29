#include <iostream>
#include <vector>
using namespace std;

struct Punt {
    double x,y;
};

bool baricentre (const vector<Punt>& v, Punt& b) {
    b.x = b.y = 0;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        b.x += v[i].x;
        b.y += v[i].y;
    }
    b.x /= n;
    b.y /= n;
    
    for (int i = 0; i < n; i++) {
        if (v[i].x == b.x and v[i].y == b.y) return true;
    }
    return false;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    int n;
    while (cin >> n) {
        vector<Punt> v(n);
        
        bool es_diferent = false;
        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y;
            if (i > 0 and (v[i].x != v[i-1].x or v[i].y != v[i-1].y)) es_diferent = true;
        }
        
        Punt b;
        bool dins_v = baricentre(v, b);

        cout << "baricentre: (" << b.x << "," << b.y << ")" << endl;
        if (not es_diferent) cout << "el vector no compleix la propietat 1" << endl;
        else if (b.x != b.y) cout << "el vector no compleix la propietat 2" << endl;
        else if (dins_v) cout << "el vector no compleix la propietat 3" << endl;
        else cout << "vector normalitzat" << endl;
    }
}