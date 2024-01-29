#include <iostream>
#include <vector>
using namespace std;

// Pre: c es un caracter
// Post: retorna true si c es una lletra, false en cas contrari
bool es_letra (char c) {
    return ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z');
}

// Pre: a l'entrada hi ha una sequencia de caracters
// Post: escriu els mateixos caracters que a l'entrada
//       reordenats: primer els que no son lletres (en el
//       mateix ordre en que van apareixer) i, a continuacio,
//       les lletres (en ordre invers a el de la seva aparicio)
void signos_letras () {
    char c;
    if (cin >> c) {
        if (not es_letra(c)) {
            cout << c;
            signos_letras();
        }
        else {
            signos_letras();
            cout << c;
        }
    }
}

int main () {
    signos_letras();
    cout << endl;
}