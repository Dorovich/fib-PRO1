#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matrix;
typedef vector<char> Row;

void pasteOnPos (Matrix& aux, Matrix toPaste, int posX, int posY, int move) {
    int k = 0;
    for (int i = posX-move; i <= posX+move; i++) {
        int h = 0;
        for (int j = posY-move; j <= posY+move; j++) {
            aux[i][j] = toPaste[k][h];
            h++;
        }
        k++;
    }
}

Matrix paint (int n) {
    int size = 1;
    for (int i = 0; i < n; i++) size *= 3;
    Matrix aux(size, Row(size, '.'));
    if (n == 1) {
        int x = 1;
        int y = 1;
        aux[y][x] = 'O';
        aux[y+1][x] = '|';
        aux[y-1][x] = '|';
        aux[y][x+1] = '-';
        aux[y][x-1] =  '-';
        return aux;
    }
    else {
        Matrix toPaste = paint(n-1);
        int middleX = aux[0].size()/2;
        int middleY = aux.size()/2;
        int move = toPaste.size()/2;
        pasteOnPos(aux, toPaste, middleX+toPaste.size(), middleY, move);
        pasteOnPos(aux, toPaste, middleX-toPaste.size(), middleY, move);
        pasteOnPos(aux, toPaste, middleX, middleY+toPaste.size(), move);
        pasteOnPos(aux, toPaste, middleX, middleY-toPaste.size(), move);
        pasteOnPos(aux, toPaste, middleX, middleY, move);
        return aux;
    }
    
}

int main () {
    int n;
    cin >> n;
    
    int h = 1;
    for (int i = 0; i < n; i++) h *= 3;
    int w = h+2;
    
    Matrix canvas(h, Row(w, '.'));
    Matrix aux = paint(n);
    
    for (int i = 0; i < canvas.size(); i++) {
        canvas[i][0] = '|';
        canvas[i][canvas[0].size()-1] = '|';
    }

    int k = 0;
    for (int i = 1; i < w-1; i++) {
        for (int j = 0; j < h; j++) canvas[j][i] = aux[j][k];
        k++;
    }
    for (int i = 0; i < canvas.size(); i++) {
        for (int j = 0; j < canvas[0].size(); j++) {
            if (canvas[i][j] == '.') cout << ' ';
            else cout << canvas[i][j];
        }
        cout << endl;
    }
}