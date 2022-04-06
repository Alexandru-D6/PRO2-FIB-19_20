#include <iostream>
#include <set>
using namespace std;

void escribir_set(set<string> &a) {
    for (set<string>::iterator it = a.begin(); it != a.end(); ++it) cout << ' ' << *it;
    cout << endl;
}

int main() {
    set<string> todas;
    set<string> ninguna;
    string temp;

    while (cin >> temp and temp != ".") ninguna.insert(temp);

    int actividades;
    cin >> actividades;

    for (int i = 0; i < actividades; ++i) {
        set<string> temp_set;
        while (cin >> temp and temp != ".") {
            if (i == 0) todas.insert(temp);
            else if (todas.find(temp) != todas.end()) temp_set.insert(temp);
            

            //ninguna actividad
            ninguna.erase(temp);

        }
        if (i != 0) todas = temp_set;
    }

    cout << "Totes les activitats:";
    escribir_set(todas);
    cout << "Cap activitat:";
    escribir_set(ninguna);

}