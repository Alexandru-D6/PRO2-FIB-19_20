#include <iostream>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
#include <list>
using namespace std;

int main() {
    list<ParInt> l;

    LlegirLlistaParInt(l);
    int frag; cin >> frag;

    list<ParInt>::const_iterator it = l.begin();

    int amount = 0, delay = 0;
    while (it != l.end()) {
        int aux = it -> primer();
        if (aux == frag) {
            ++amount;
            delay += it -> segon();
        }
        ++it;
    }

    cout << frag << ' ' << amount << ' ' << delay << endl;

}