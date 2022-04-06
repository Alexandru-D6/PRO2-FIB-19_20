/**
 * @mainpage Extension de la clase Conjuntos de Estudiantes.

 * En este ejemplo se añade la funcionalidad de obtener la nota media de los estudiantes con nota del conjunto.
 * Las clase modifica es <em>Cjt_estudiants</em>.

*/

/** @file pro2.cc
 *  @brief Programa principal para el ejercicio <em>Extension de la clase Conjuntos de Estudiantes</em>.
 */

#include "Cjt_estudiants.hh"
#include "Estudiant.hh"

#ifndef NO_DIAGRAM    //explicado en Cjt_estudiants.hh
#include <iostream>
using namespace std;
#endif

/** @brief Programa principal para el ejercicio "Extension de la clase Conjuntos de Estudiantes".
 */
int main() {
  Cjt_estudiants c;
  c.llegir();
 
  int op = readint();
  while (op!= -5){
    Estudiant est; 
    int dni; 
    bool b;
    switch (op){ 
    case -1:   // afegir estudiant
      est.llegir();
      c.afegir_estudiant(est,b);
      if (b)  cout << "L'estudiant " << est.consultar_DNI() << " ja hi era" << endl << endl;
      break;
    case -2:   // esborrar estudiant
      cin >> dni; //  dni de l'estudiant a esborrar
      c.esborrar_estudiant(dni,b);
      if (not b)  cout << "L'estudiant amb dni " << dni << " no hi era" << endl << endl;      
     break; 
    case -3:   // escriure conjunt
      cout << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
      break;
    case -4:   // mitjana conjunt
      cout << "Nota mitjana: ";
      cout << c.mitjana_estudiants_amb_nota() << endl << endl;
    }
    op = readint();
  }
}
