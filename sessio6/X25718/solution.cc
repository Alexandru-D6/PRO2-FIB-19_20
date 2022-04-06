#include "solution.hh"

void esborra_tots(list<Estudiant> &t, int x) {
    /*list<Estudiant> temp;
    for (list<Estudiant>::iterator it = t.begin(); it != t.end(); ++it) if(it->consultar_DNI() != x) temp.push_back(*it);
    t = temp;*/
    list<Estudiant>::iterator it = t.begin();

    while (it != t.end()) {
        if(it->consultar_DNI() == x) {
            it = t.erase(it);
        }else ++it;
    }
}