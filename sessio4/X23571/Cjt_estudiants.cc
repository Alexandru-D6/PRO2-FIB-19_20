#include <algorithm>
#include "Cjt_estudiants.hh"


Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  primer_est_amb_nota=0;
  vest = vector<Estudiant>(MAX_NEST);
}

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

int Cjt_estudiants::mida() const {
  return nest;
}

int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}
 

void Cjt_estudiants::ordenar() {
  sort(vest.begin(), vest.begin() + nest, Estudiant::comp_nota_dni);
}


void Cjt_estudiants::llegir() {
  cin >> nest; 
  for (int i = 0; i < nest; ++i) {
    vest[i].llegir();
    if (not vest[i].te_nota())  primer_est_amb_nota++;
  }
  ordenar();
}


void Cjt_estudiants::escriure() const {
  cout << "Estudiants sense nota " << primer_est_amb_nota << endl;
  cout << "Estudiants amb nota " << nest-primer_est_amb_nota << endl;
  for (int i = 0; i < nest; ++i) vest[i].escriure();
}


int Cjt_estudiants::cerca_lineal_per_dni(const vector<Estudiant> &v, int ini, int fi, int dni_b) {
  int i = ini; 
  while (i<=fi and v[i].consultar_DNI() != dni_b) i++;
  return i;
}



int Cjt_estudiants::cerca_dicot_per_dni(const vector<Estudiant> &vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  while (left <= right) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i-1;
    else if (x > vest[i].consultar_DNI()) left = i+1;
    else return i;
  }
  // i es la posicio, si l'element existeix
  return left;  
}  


int Cjt_estudiants::cerca_dicot_per_nota_dni(const vector<Estudiant> &v, int left, int right, const Estudiant& e) {
  while (left <= right) { 
    int i = (left + right)/2;
    if (Estudiant::comp_nota_dni(e,v[i])) right = i - 1; 
    else if (Estudiant::comp_nota_dni(v[i],e)) left = i + 1; 
    else return i;
  } 
    return left;
}  

