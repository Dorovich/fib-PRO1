#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Client {
    string client_id;
    Date birth_date;
    bool priority;
    int total_amount;
};

//compare conditions
bool cmp (Client& a, Client& b) {
    if (a.priority and not b.priority) return true;
    else if (b.priority and not a.priority) return false;
    else {
        if (a.total_amount > b.total_amount) return true;
        else if (a.total_amount == b.total_amount) {
            if (a.birth_date.year < b.birth_date.year) return true;
            else if (a.birth_date.year == b.birth_date.year) {
                if (a.birth_date.month < b.birth_date.month) return true;
                else if (a.birth_date.month == b.birth_date.month) {
                    if (a.birth_date.day < b.birth_date.day) return true;
                    else if (a.birth_date.day == b.birth_date.day) {
                        if (a.client_id < b.client_id) return true;
                    }
                }
            }
        }
        return false;
    }
}

//returns true when client a is older than b. Returns false otherwise
bool is_older(const Client& a, const Client& b) {
    Date x = a.birth_date;
    Date y = b.birth_date;
    if (x.year != y.year) return x.year < y.year;
    if (x.month != y.month) return x.month < y.month;
    return x.day < y.day;
}

//reads client data from input
void get_client (Client& c) {
    int n, compres_sup_1000 = 0;
    cin >> c.client_id >> c.birth_date.day >> c.birth_date.month >> c.birth_date.year >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        c.total_amount += v[i];
        if (v[i] >= 1000) compres_sup_1000++;
    }
    c.priority = compres_sup_1000 >= 3;
}


//gets client info vector v 
void get_client_vector(vector<Client>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) get_client(v[i]);
}

//prints date info in format dd-mm-yyyy
void print_date(Date date) {
    if (date.day < 10) cout << 0;
    cout << date.day << '-';
    if (date.month < 10) cout << 0;
    cout << date.month << '-';
    cout << date.year;
}

//writes v on output channel
void write_client_vector(const vector<Client>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        cout << v[i].priority << ' ' << v[i].total_amount << ' ';
        print_date(v[i].birth_date);
        cout << ' ' << v[i].client_id << endl;
    }
}
        
int main() {
    int n;
    cin >> n;
    vector<Client> v(n);
    get_client_vector(v);
    sort(v.begin(),v.end(),cmp);
    write_client_vector(v);
}