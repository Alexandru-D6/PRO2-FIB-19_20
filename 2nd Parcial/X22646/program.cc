#include <iostream>
#include "Cua.hh"
#include "CuaIOint.hh"
using namespace std;

int main() {
    Cua<int> a;
    llegir_cua_int(a, -1);

    Cua<int> b;
    b = a.galopar();

    escriure_cua_int(b);
}