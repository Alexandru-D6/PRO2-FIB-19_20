#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
    ParInt inp;

    while (inp.llegir() and not(inp.primer() == 0 and inp.segon() == 0))
        l.push_back(inp);
}

void EscriureLlistaParInt(const list<ParInt>& l) {
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
    list<ParInt>::const_iterator it = l.begin();
    while (it != l.end()) it -> escriure();
}