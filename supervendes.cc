#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;       // títol del llibre
    int nb_pag;         // número de pàginas del llibre
};

struct Author {
    string name;        // nom de l'autor
    Book bestseller;    // llibre supervendes
};

typedef vector<Author> Library;

Library read_data() {
    int n;
    cin >> n;
    Library l(n);
    for (int i = 0; i < n; i++) cin >> l[i].name >> l[i].bestseller.title >> l[i].bestseller.nb_pag;
    return l;
}

int main() {
    Library l = read_data();
    char c;
    int n;
    while (cin >> c >> n) {
        cout << "-- begin query" << endl;
        for (int i = 0; i < l.size(); i++) {
            if (l[i].bestseller.title[0] == c and l[i].bestseller.nb_pag > n) cout << l[i].name << endl;
        }
        cout << "-- end query" << endl;
    }
}
