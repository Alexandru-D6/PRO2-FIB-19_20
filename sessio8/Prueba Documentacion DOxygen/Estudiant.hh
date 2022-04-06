/** @file Estudiant.hh
 *  @brief Especificación de la clase Estudiant
 */

#ifndef ESTUDIANT_HPP
#define ESTUDIANT_HPP

#ifndef NO_DIAGRAM    //explicado en Cjt_estudiants.hh
#include "utils.PRO2"
#endif


/** @class Estudiant
    @brief Representa un estudiante con un dni y una nota, que puede ser un NP o 0 <= nota <= 10
*/

class Estudiant {
public:
  //Constructores

  /** @brief Creadora por defecto
      \pre <em>cierto</em>
      \post El resultado es un estudiante con DNI = 0 y sin nota.
   */
  Estudiant();

  /** @brief Creadora con valores concretos
      \pre dni >= 0.
      \post el resultado es un estudiante con DNI = dni y sin nota.
   */
  Estudiant(int dni);

  /** @brief Destructora por defecto
      \pre <em>cierto</em>
      \post Borra automaticamente los objetos locales al salir de un ambito de visibilidad.
   */
  ~Estudiant();

  //Modificadores

  /** @brief Añade una nota al parametro implicito
      \pre El parametro implicito no tiene nota, 0 <= "nota" <= nota_maxima().
      \post La nota del p.i. pasa a ser "nota".
   */
  void afegir_nota(double nota);

  /** @brief Modifica la nota al p.i.
      \pre El parametro implicito tiene nota, 0 <= "nota" <= nota_maxima().
      \post La nota del p.i. pasa a ser "nota".
    */
  void modificar_nota(double nota);
                                    
  //Consultores

  /** @brief Consultora de DNI
      \pre <em>cierto</em>
      \post El resultado es el DNI de p.i.
   */
  int consultar_DNI() const;

  /** @brief Consultora de nota
      \pre El p.i. tiene nota
      \post El resultado es la nota del p.i.
   */
  double consultar_nota() const;

  /** @brief Consultora de nota maxima
      \pre <em>cierto</em>
      \post El resultado es la nota maxima de los elementos de la clase
   */
  static double nota_maxima();

  /** @brief Consultora de existencia de nota
      \pre <em>cierto</em>
      \post El resultado indica si el p.i. tiene nota o no.
   */
  bool te_nota()  const;
  
  /** @brief Comparadora de estudiantes
      \pre <em>cierto</em>
      \post El resultado indica si el DNI de e1 es mas pequeño que el de e2.
   */
  static bool comp(const Estudiant& e1, const Estudiant& e2); 

  // Lectura i escriptura

  /** @brief Operacion de lectura
      \pre Hay preparados en el canal estandar de entrada un entero no negativo y un double
      \post El p.i. pasa a tener los atribuos leidos por el canal estandar de entrada;
            si el double no pertenece al intervalo [0..nota_maxima()], el p.i. se queda sin nota.
   */
  void llegir();

  /** @brief Operacion de escritura
      \pre <em>cierto</em>
      \post Se han escrito los atributos del p.i. por el canal estandar de salida;
            si no tiene nota escribe "NP".
   */
  void escriure() const;



  // Tipus de m�dul: dades
  // Descripci� del tipus: cont� el DNI d'un estudiant, 
  // que �s un enter positiu, i pot tenir nota, que seria un double 
  // Les notes v�lides s�n les de l'interval 0..nota_maxima() 

private:    
  int dni;
  double nota;
  bool amb_nota;
  static const int MAX_NOTA = 10;
  /* 
     Invariant de la representaci�: 
     - 0 <= dni
     - si amb_nota, llavors 0 <= nota <= MAX_NOTA 
  */

};
#endif
