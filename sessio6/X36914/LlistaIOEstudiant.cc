#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
    Estudiant inp;

    inp.llegir();
    while (not(inp.consultar_DNI() == 0 and inp.consultar_nota() == 0)) {
        l.push_back(inp);
        inp.llegir();
    }
}

void EscriureLlistaEstudiant(const list<Estudiant>& l) {
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
    list<Estudiant>::const_iterator it = l.begin();
    while (it != l.end())  {
        it -> escriure();
        ++it;
    }
}