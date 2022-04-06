#include <iostream>
#include "ArbreG.hh"
#include "ArbGIOint.hh"
using namespace std;

int main() {
    ArbreGen<int> a;
    llegir_arbre_int(a, -1);

    cout << a.max_suma_cami() << endl;
}