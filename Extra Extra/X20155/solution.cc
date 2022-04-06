// Poseu aqui vostre nom, cognoms i grup de laboratori

#include "Cjt_estudiants.hh"
#include "solution.hh"
#include <algorithm>

/* Traieu els comentaris "//" i completeu les operacions

   Recordeu que no podeu fer servir elements privats de les classes
   {\tt Cjt\_estudiants} i {\tt Es\-tu\-diant}
*/

void escriure_becats(const Cjt_estudiants& c) {
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida els estudiants
     de c amb beca en ordre ascendent per DNI */
   int becados = c.estudiants_amb_beca();

   if (becados > 0) {
      Estudiant est = c.becat_menys_prioritari();
      est.escriure();
      --becados;

      int i = 0;
      while (i < c.mida() and becados > 0) {
         Estudiant est2 = c.consultar_iessim(i+1);
         if (est2.consultar_DNI() != est.consultar_DNI() and est2.mes_prioritari(est)) {
            est2.escriure();
            --becados;
         }   
         ++i;
      }
   }else cout << '0' << endl;
}

