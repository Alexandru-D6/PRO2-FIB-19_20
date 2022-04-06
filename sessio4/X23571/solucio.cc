#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
  int i = primer_est_amb_nota;

  while (i < nest and vest[i].consultar_nota() < nota_b) ++i;

  return i;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat) {
  int k = cerca_lineal_per_dni(vest, 0, nest-1, est.consultar_DNI());

  trobat = est.consultar_DNI() == vest[k].consultar_DNI();

  if (not trobat) {
    int i;

    if (est.te_nota()) {
      i = cerca_dicot_per_nota_dni(vest, primer_est_amb_nota, nest-1, est);
    }else {
      i = cerca_dicot_per_dni(vest, 0, primer_est_amb_nota-1, est.consultar_DNI());
      ++primer_est_amb_nota;
    }

    ++nest;
    for (int j = nest; j > i; --j) vest[j] = vest[j-1];
    vest[i] = est;
  }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
  for (int i = primer_est_amb_nota; i < nest; ++i) {
    if (vest[i].consultar_nota() >= nota_i and vest[i].consultar_nota() <= nota_s) vest[i].escriure();
  }
}