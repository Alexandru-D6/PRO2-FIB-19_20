#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> totes, cap, falta;
    string x;
    while (cin >> x and x != ".") totes.insert(x);
    cap = totes;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        falta = totes;
        while (cin >> x and x != ".") {
            cap.erase(x);
            falta.erase(x);
        }

        for (set<string>::iterator it = falta.begin(); it != falta.end(); ++it) totes.erase(*it);
    }

    cout << "Totes les activitats:";
    for (set<string>::iterator it = totes.begin(); it != totes.end(); ++it) cout << ' ' << *it;
    cout << endl;

    cout << "Cap activitat:";
    for (set<string>::iterator it = cap.begin(); it != cap.end(); ++it) cout << ' ' << *it;
    cout << endl;
}