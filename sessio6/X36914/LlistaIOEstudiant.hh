#define LLISTA_IO_ESTUDIANT

#include <iostream>
#include "Estudiant.hh"
#include <list>
using namespace std;

void LlegirLlistaEstudiant(list<Estudiant>& l);
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)

void EscriureLlistaEstudiant(const list<Estudiant>& l);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l