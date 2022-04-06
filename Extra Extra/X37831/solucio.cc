//#define NDEBUG
#include <cassert>
#include "Cjt_estudiants.hh"


// NOMÉS PODEU MODIFICAR AQUEST FITXER.
// AQUEST ÉS L'ÚNIC FITXER QUE S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// SÓLO PODËIS MODIFICAR ESTE ARCHIVO.
// ESTE ARCHIVO ES EL ÚNICO QUE SE UTILIZARÄ PARA EVALUAR VUESTRA ENTREGA.



// Aquest mètode forma part de la implementació de la classe Cjt_estudiants.
// L'especificació d'aquest mètode és al fitxer Cjt_estudiants.hh
void Cjt_estudiants::avaluacio_global_iesim(int i) {
    Estudiant est = vest[i-1];
    int total_ex = est.nombre_notes_parcials();
    double nota_global = 0;
    double porcentaje_examen_perdido = 0;
    int j = 0;

    while (j < total_ex and porcentaje_examen_perdido <= 0.5) {
        if (est.consultar_nota_parcial(j+1) != -1) {
            nota_global += est.consultar_nota_parcial(j+1) * pes_parcial(j+1);
        }else {
            porcentaje_examen_perdido += pes_parcial(j+1);
        }
        ++j;
    }

    if (porcentaje_examen_perdido <= 0.5) vest[i-1].assignar_nota_global(nota_global);
    else vest[i-1].assignar_nota_global(-1);
}



// Aquest mètode forma part de la implementació de la classe Cjt_estudiants.
// L'especificació d'aquest mètode és al fitxer Cjt_estudiants.hh

// La part de la implementació donada és correcta, però incompleta.
// Podeu completar la part que falta de la implementació en
// l'espai indicat pel comentari 
void Cjt_estudiants::parcials_presentats_aprovats() const {
  vector<bool> subconj(nombre_parcials,false);
  // exàmens parcials presentats per tots els estudiants aprovats
  int np = 0; 
  int i = 0;
  while (i < nest and vest[i].consultar_nota_global() < 5.0) ++i; 
  if (i < nest) {
     for (int j = 1; j <= nombre_parcials; ++j) {
        if (vest[i].consultar_nota_parcial(j) != -1) {
	   subconj[j-1] = true;
	   ++np;
        }
     } 
     ++i;
     // exàmens parcials als quals s'ha presentat el primer estudiant aprovat
  }

    while (i < nest) {
        if (vest[i].consultar_nota_global() >= 5.0) {
            for (int j = 1; j <= nombre_parcials; ++j) {
                if (vest[i].consultar_nota_parcial(j) == -1) {
                    subconj[j-1] = false;
                }
            } 
        }
        ++i;
    }
  // Completeu aquí el cos del mètode parcials_presentats_aprovats


  cout << endl << "Examens parcials presentats per tots els estudiants aprovats: ";
  if (np > 0) {
     for (int j = 1; j <= nombre_parcials; ++j) {
        if (subconj[j-1]) cout << " " << j;
     }
  }
  cout << endl;
}
