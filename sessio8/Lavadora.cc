#include "Lavadora.hh"
#include <iostream>

Lavadora::Lavadora() {
    prendas = list<Prenda> ();
    ini = false;
    pes = 0;
    pesmax = 0;
    col = false;
}

void Lavadora::inicializar(int pmax, bool col) {
    ini = true;
    pesmax = pmax;
    this->col = col;
}

void Lavadora::anadir_prenda (const Prenda& p) {
    pes += p.consul_peso();
    prendas.insert(prendas.end(), p);
}

void Lavadora::lavado () {
    ini = false; 
    pes = 0;
    prendas.clear();
}

bool Lavadora::esta_inicializada() const {
    return ini;
}

bool Lavadora::consultar_color() const {
    return col;
}

int Lavadora::consultar_peso() const {
    return pes;
}

int Lavadora::consultar_peso_maximo() const {
    return pesmax;
}

void Lavadora::escribir() const {
    if (ini) {
        cout << "   Lavadora:" << endl;
        if (col) cout << "Lavadora de color, con peso actual ";
        else cout << "Lavadora blanca, con peso actual ";
        cout << pes << " y peso maximo " << pesmax << "; sus prendas son" << endl;
        for (list<Prenda>::const_iterator it = prendas.begin(); it != prendas.end(); ++it) {
            it->escribir();
        }
    }else {
        cout << "Lavadora no inicializada" << endl;
    }
    cout << endl;
}