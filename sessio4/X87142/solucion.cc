#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
  int i = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());

  b = est.consultar_DNI() == vest[i].consultar_DNI();

  if (not b) {
    for (int j = nest; j > i; --j) vest[j] = vest[j-1];
    ++nest;
    vest[i] = est;

    recalcular_posicio_imax();
  }
}

void Cjt_estudiants::eliminar_estudiants_sense_nota() {
  int j = 0;
  vector <Estudiant> cjt_temp(nest);
  for (int i = 0; i < nest; ++i) {
    if (vest[i].te_nota()) {
        cjt_temp[j] = vest[i];
        ++j;
    }
  }
  nest = j;
  for (int i = 0; i < nest; ++i) vest[i] = cjt_temp[i];
  recalcular_posicio_imax();
}