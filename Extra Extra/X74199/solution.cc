// Poseu aqui vostre nom, cognoms i grup de laboratori

#include "Cjt_estudiants.hh"

// Traieu els //, /*, etc. adients i completeu les operacions

/* Operaci� afegir_estudiant: el codi que us donem compila sense error i fa
   coses correctes, per� clarament insuficients; analitzeu amb cura quins
   camps de la classe resten per actualitzar
*/

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */
{
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  b = (i<nest) and (x== vest[i].consultar_DNI());
    
  // b indica si est hi es a vest; si b es fals, i es la posicio on ha
  // d'anar est per mantenir l'ordre a vest; 
 
  if (not b) {
   for (int j=nest; j>i; --j) vest[j] = vest[j-1];
   vest[i] = est;
   ++nest;

   if (i <= pitjor_becat) ++pitjor_becat;

   if (est.te_nota() and est.consultar_nota() >= min_nota_beca) {
      if (num_beques == 0 and est.consultar_nota() >= min_nota_beca) {
         ++num_beques;
         pitjor_becat = i;
      }else if (num_beques < max_beques and num_beques > 0) {
         Estudiant est_inf = becat_menys_prioritari();
         if (est.mes_prioritari(est_inf)) {
            ++num_beques;
         }else if (est.consultar_nota() > min_nota_beca){
            ++num_beques;
            pitjor_becat = i;
         }
      }else if (num_beques == max_beques) {
         Estudiant est_inf = becat_menys_prioritari();
         if (est.mes_prioritari(est_inf)) {
            pitjor_becat = immediatament_millor(pitjor_becat);
         }
      }
   }
  }
}


/* Operaci� immediatament_millor: la linia del cout no pinta res i haurieu de
   treure-la quan comenceu a implementar l'operaci�, per� permet fer
   lliuraments sense error de compilaci�, de forma que l'altra operaci� es
   podria avaluar manualment
*/

int Cjt_estudiants::immediatament_millor(int i) const
/* Pre: 0<=i<nest; vest[i] te nota */
/* Post: el resultat �s la posici� en vest[0..nest-1] de l'estudiant
   immediatament millor que vest[i], si n'hi ha; -1 en cas contrari */
{
   double nota_base = vest[i].consultar_nota();
   double nota_siguiente = vest[i].nota_maxima();
   int pos_siguiente_nota = -1;

   for (int j = 0; j < nest; ++j) {
      if (j != i) {
         if (vest[j].te_nota() and vest[j].consultar_nota() > nota_base and vest[j].consultar_nota() < nota_siguiente) {
            pos_siguiente_nota = j;
            nota_siguiente = vest[j].consultar_nota();
         }else if (vest[j].te_nota() and vest[j].consultar_nota() == nota_base and j > i) {
            pos_siguiente_nota = j;
            j = nest;
         }
      }
   }
   return pos_siguiente_nota;
}


