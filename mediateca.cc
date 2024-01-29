#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
    string artist, title, genre;
    int year;
};

bool comp(const Track &a, const Track &b) {
    if (a.artist < b.artist) return true;
    else if (a.artist == b.artist) {
        if (a.year < b.year) return true;
        else if (a.year == b.year) {
            if (a.title < b.title) return true;
        }
    }
    return false;
}

vector<Track> read_tracks(int n) {
    vector<Track> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].artist >> v[i].title >> v[i].genre >> v[i].year;
    }
    return v;
}

void print_track(const Track &t) {
    cout << t.artist;
    cout << " (" << t.year;
    cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<Track> v = read_tracks(n);
    string s;
    while (cin >> s) {
        vector<Track> g;
        for (int i = 0; i < n; i++) if (v[i].genre == s) g.push_back(v[i]);
        sort(g.begin(), g.end(), comp);
        for (int i = 0; i < g.size(); i++) print_track(g[i]);
    }
}
