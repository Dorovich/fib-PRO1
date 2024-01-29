#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<bool> > Tauler;

int radar (const Tauler& t, int fila, int columna) {
    int radio = 1;
    while (radio < t.size()) {
        for (int i = columna-radio; i <= columna+radio; i++) {
            if (i >= 0 and i <= 9) {
                if (fila-radio >= 0 and t[fila-radio][i]) return radio;
                else if (fila+radio <= 9 and t[fila+radio][i]) return radio;
            }
        }
        for (int i = fila-radio; i <= fila+radio; i++) {
            if (i >= 0 and i <= 9) {
                if (columna-radio >= 0 and t[i][columna-radio]) return radio;
                else if (columna+radio <= 9 and t[i][columna+radio]) return radio;
            }
        }
        radio++;
    }
    return -1;
}

int main () {
    Tauler t (10, vector<bool> (10, false));
    char fil, dir;
    int col, tam;
    
    for (int i = 0; i < 10; i++) {
        cin >> fil >> col >> tam >> dir;
        if (dir == 'h') {
            for (int j = 0; j < tam; j++) t[fil-'a'][col-1+j] = true;
        }
        if (dir == 'v') {
            for (int j = 0; j < tam; j++) t[fil-'a'+j][col-1] = true;
        }
    }

    cout << "  12345678910" << endl;
    for (int i = 0; i < 10; i++) {
        cout << char('a'+i) << ' ';
        for (int j = 0; j < 10; j++) {
            if (t[i][j]) cout << 'X';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;

    while (cin >> fil >> col) {
        if (t[fil-'a'][col-1]) cout << fil << col << " tocat!" << endl;
        else {
            cout << fil << col << " aigua! ";
            fil = fil-'a';
            col = col-1;
            cout << "vaixell mes proper a distancia " << radar(t, fil, col) << endl;
        }
    }
}