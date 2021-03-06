#include <algorithm>
#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  intervals = vector<int> (10, 0);
}

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

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
  int i;
  bool found=false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1; 
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  } 
  if (found) return i;
  else return left;
}  

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima() 
{
  return MAX_NEST;
}
 
int Cjt_estudiants::nombre_est_interval(int i) const
{
  return intervals[i];
}

void Cjt_estudiants::ordenar() {
  sort(vest.begin(), vest.begin() + nest, Estudiant::comp);
}

void Cjt_estudiants::incrementar_interval(double x)
{ 
  int i;
  if (x == 10) i = 9;
  else i = int(x);
  ++intervals[i];
}

void Cjt_estudiants::decrementar_interval(double x)
{
  int i;
  if (x == 10) i = 9;
  else i = int(x);
  --intervals[i];
}


void Cjt_estudiants::llegir() {
  cin >> nest; 
  for (int i = 0; i < nest; ++i) { 
    vest[i].llegir();
    if (vest[i].te_nota()) {
      incrementar_interval(vest[i].consultar_nota());
    }
  }
  ordenar();
}

void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}

