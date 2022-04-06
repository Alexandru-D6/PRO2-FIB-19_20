#include <iostream>
#include "ArbIOint.hh"
#include "Arbre.hh"
using namespace std;

int main() {
    Arbre<int> a;
    llegir_arbre_int(a, -99);
    
    a.arbre_maxims();
    //cout << b.arrel() << endl;
    escriure_arbre_int(a);
}