#include "Cubeta.hh"
#include <iostream>

Cubeta::Cubeta() {
    ropablanca = stack<Prenda>();
    ropacolor = stack<Prenda>();
}

Cubeta::Cubeta(const Cubeta& c) {
    ropablanca = c.ropablanca;
    ropacolor = c.ropacolor;
}

void Cubeta::anadir_prenda(const Prenda& p) {
    if (p.consul_color()) ropacolor.push(p);
    else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav) {
    if (lav.consultar_color()) completar_lavadora_pila_it(ropacolor, lav);
    else completar_lavadora_pila_it(ropablanca, lav);
}

/*void completar_lavadora_pila_rec(stack<Prenda>& p, Lavadora& l) {
 //coming soon
}*/

void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l) {
    /*while(not p.empty() and l.consultar_peso() + p.top().consul_peso() <= l.consultar_peso_maximo()) {
        l.anadir_prenda(p.top());
        p.pop();
    }*/

    stack<Prenda> sobrantes;

    while (not p.empty()) {
        if (l.consultar_peso() + p.top().consul_peso() <= l.consultar_peso_maximo()) {
            l.anadir_prenda(p.top());
            p.pop();
        }else {
            sobrantes.push(p.top());
            p.pop();
        }
    }
    
    while (not sobrantes.empty()) {
        p.push(sobrantes.top());
        sobrantes.pop();
    }
}

void Cubeta::escribir() const {
    cout << "   Cubeta:" << endl;
    cout << "Ropa de color de la cubeta:" << endl;
    escribir_pila_prenda(ropacolor);

    cout << "Ropa blanca de la cubeta:" << endl;
    escribir_pila_prenda(ropablanca);
    
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p) {
    stack<Prenda> temp = p;
    while (not temp.empty()) {
        temp.top().escribir();
        temp.pop();
    }
}


