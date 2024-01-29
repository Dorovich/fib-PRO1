#include <iostream>
#include <vector>
using namespace std;

struct Player {
    string name;
    double score;     // mitjana anotadora
};

struct Team {
    string tname;
    Player mvp;       // jugador millor valorat
};

typedef vector<Team> League;

League read_data() {
    // el teu codi aquí
}

int main() {
    // el teu codi aquí
}
