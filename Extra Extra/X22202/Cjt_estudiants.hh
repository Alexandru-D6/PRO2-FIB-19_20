#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest; // estudiants del conjunt

  int nest; // nombre d'estudiants del conjunt 

  static const int MAX_NEST = 10; // nombre maxim d'elements del conjunt

  int nombre_aprovats; // nombre d'aprovats del conjunt
  
  int nombre_presentats;  // nombre de presentats del conjunt

  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel dni dels estudiants i no cont� estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - nombre_aprovats = nombre d'elements de vest[0..nest-1] amb nota >= Estudiant::nota_maxima();
     - nombre_presentats = nombre d'elements de vest[0..nest-1] amb nota 
  */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0 <= left, right < vest.size(), right >= left + 1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */


public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */

  void esborrar_estudiant(int dni, bool& b);
  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del par�metre impl�cit */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'estudiants del par�metre impl�cit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat �s el nombre maxim d'estudiants que pot arribar
     a tenir el par�metre impl�cit */

  int presentats() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants del par�metre impl�cit amb
     nota */
  
  int aprovats() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants del par�metre impl�cit amb
     nota >= Estudiant::nota_maxima()/2 */

  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal est�ndar d'entrada un enter  (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida els estudiants del
     par�metre impl�cit en ordre ascendent per DNI */
};

#endif

