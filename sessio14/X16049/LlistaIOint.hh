#ifndef LLISTA_IO_INT
#define LLISTA_IO_INT

#include "utils.PRO2"
#include  "Llista.hh"

void llegir_llista_int(Llista<int> &l, int marca)
{
  int n;
  cin >> n;
  while (n != marca){
    l.afegir(n);
    cin >> n;
  }
}


void escriure_llista_int(Llista<int> l) {
  l.inici();
  cout << "[Primer]"<<endl;
  while (not l.dreta_de_tot()){
    cout << l.actual() << " ";
    l.avanca();
  }
  cout << "[Ultim] " << endl;
}

inline void
escriure_llista_int_rev(Llista<int> l)
{
  cout << "[Ultim] " << endl;
  if (not l.es_buida()){
    l.fi();  l.retrocedeix();
    while (not l.sobre_el_primer()){
      cout << l.actual() << endl;
      l.retrocedeix();
    }
    cout << l.actual() << endl;
  }
  cout << "[Primer]"<<endl;
}

#endif
