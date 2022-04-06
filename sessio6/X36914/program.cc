#include <iostream>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"
#include <list>
using namespace std;

int main() {
    list<Estudiant> l;

    LlegirLlistaEstudiant(l);
    int frag; cin >> frag;

    list<Estudiant>::const_iterator it = l.begin();

    int amount = 0;
    while (it != l.end()) {
        int aux = it -> consultar_DNI();
        if (aux == frag) {
            ++amount;
        }
        ++it;
    }

    cout << frag << ' ' << amount << endl;

}