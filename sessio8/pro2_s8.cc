/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main () {
    int command;
    Lavadora L;
    Cubeta C;
    while (cin >> command and command != -8) {
        if (command == -1) {
            int pesmax; bool col;
            cin >> pesmax;
            col = readbool();

            L.inicializar(pesmax, col);
        }else if (command == -2) {
            int pes; bool col;
            cin >> pes;
            col = readbool();

            Prenda P(pes, col);

            L.anadir_prenda(P);
        }else if (command == -3) {
            int pes; bool col;
            cin >> pes;
            col = readbool();

            Prenda P(pes, col);
            
            C.anadir_prenda(P);
        }else if (command == -4) {
            C.completar_lavadora(L);
        }else if (command == -5) {
            L.lavado();
        }else if (command == -6) {
            C.escribir();
        }else if (command == -7) {
            L.escribir();
        }
    }
}
