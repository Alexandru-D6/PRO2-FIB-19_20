#include <iostream>
#include "Llista.hh"
#include "LlistaIOint.hh"
using namespace std;

int main() {
    Llista<int> a;

    llegir_llista_int(a, -99);
    int n; cin >> n;

    a.esborrar_tots(n);

    escriure_llista_int(a);
}