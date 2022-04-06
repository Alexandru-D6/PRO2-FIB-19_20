#include "LlistaIOEstudiant.hh"
#include <fstream>

void LlegirLlistaEstudiant(list<Estudiant>& l) {
    Estudiant est;
    est.llegir();
    ofstream salida ("salida.txt");

    if (salida.is_open()) {
        if (est.te_nota()) {
            salida << est.consultar_DNI() << ' ' << est.consultar_nota() << endl;
        }else {
            salida << est.consultar_DNI() << endl;
        }
    }

    list<Estudiant>::iterator it = l.begin();

    while (est.consultar_DNI() != 0) {
        l.insert(it, est);
        est.llegir();
        if (salida.is_open()) {
        if (est.te_nota()) {
            salida << est.consultar_DNI() << ' ' << est.consultar_nota() << endl;
        }else {
            salida << est.consultar_DNI() << endl;
        }
    }
    }
}

void EscriureLlistaEstudiant(const list<Estudiant>& l) {
    for (list<Estudiant>::const_iterator it = l.begin(); it != l.end(); ++it) it->escriure();
}