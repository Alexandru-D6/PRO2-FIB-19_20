#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)  {
  int dni = est.consultar_DNI();
  int i = cerca_dicot(vest, 0, nest-1, dni);
  b = false;
  if (vest[i].consultar_DNI() == dni) b = true;

  if (not b) {
    for (int j = nest; j > i; --j) vest[j] = vest[j-1];
    ++nest;
    vest[i] = est;

    if (est.te_nota()) incrementar_interval(est.consultar_nota());
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
  int i = cerca_dicot(vest, 0, nest-1, dni);
  b = false;
  if (vest[i].consultar_DNI() == dni) b = true;

  if (b) {
    if (vest[i].te_nota()) decrementar_interval(vest[i].consultar_nota());
    for (int j = i; j < nest - 1; ++j) vest[j] = vest[j+1];
    --nest;
  }
}