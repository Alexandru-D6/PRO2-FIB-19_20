/** @file Cjt_estudiants.hh
    @brief Especificación de la clase Conjunt de Estudiants 
*/

#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"

#ifndef NO_DIAGRAM //Se excluye del diagrama modular en el Doxygen 
#include <vector>  //pero el compilador de c++ lo sigue teniendo en cuenta.
#endif

/** @class Cjt_estudiants
    @brief Representa un conjunto de multiples estudiantes
*/

class Cjt_estudiants {
public:

  //Constructores

   /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de estudiantes.
      \pre <em>cierto</em>
      \post Crea un conjunto de estudiantes vacio
  */ 
  Cjt_estudiants();

  //Modificadores

   /** @brief Añade un estudiante al conjunto
      \pre El parámetro implícito no esta lleno
      \post b = indica si el p.i. original contiene un estudiante con el dni de est;
            si b = falso, se ha añadido el estudiante est al p.i.
   */
  void afegir_estudiant(const Estudiant &est, bool& b);

   /** @brief Elimina el estudiante especificado del conjunto
      \pre <em>cierto</em>
      \post b indica si el p.i. original contenia un estudiante con el dni dni;
            si b = cierto, este estudiante fue eliminado del p.i.
   */
  void esborrar_estudiant(int dni, bool& b);

  //Consultores
	
   /** @brief Consultora de tamaño
      \pre <em>cierto</em>
      \post El resultado es el nombre de estudiantes del p.i.
   */
  int mida() const;

   /** @brief Consultora de tamaño maximo
      \pre <em>cierto</em>
      \post El resultado es el nombre maximo de estudiantes que puede llegar 
            a tener el p.i.
   */
  static int mida_maxima();
  
  /** @brief Consultora de nota media
      \pre <em>cierto</em>
      \post El resultado es la media de las nota de los estudiantes con nota del p.i.;
            si no hay ninguno, el resultado es -1.
   */
  double mitjana_estudiants_amb_nota() const;

  // Lectura i escriptura
	
   /** @brief Operacion de lectura
      \pre <em>cierto</em>
      \post El p.i. contiene el conjunto de estudiantes leido por el canal estandar
            de entrada.
   */
  void llegir();

   /** @brief Operacion de escritura
      \pre <em>cierto</em>
      \post Se han escrito por el canal estandar de salida los estudiantes del conjunto
            que contiene el p.i. en orden ascendente por DNI.
   */
  void escriure() const;

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest;
  int nest; 
  static const int MAX_NEST = 20; // nombre maxim d'elements del conjunt
  int nest_amb_nota;  
  double suma_notes;

  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel DNI dels estudiants
       i no cont� estudiants repetits
     - 0 <= nest_amb_nota <= nest <= vest.size() = MAX_NEST
     - nest_amb_nota �s el nombres d'estudiants amb nota de vest[0..nest-1]
     - suma_notes �s la suma de les notes (dels estudiants amb nota) de vest[0..nest-1]
  */  
    
  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: el elements del par�metre impl�cit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0<=left, right<vest.size(), right>=left-1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */
 
};

#endif
