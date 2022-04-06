/* Poseu aqui vostre nom, cognoms i grup de laboratori:


*/

#include "Cjt_estudiants.hh"
#include "solution.hh"

/* Traieu els comentaris "//" i completeu les operacions

   Recordeu que no podeu fer servir elements privats de les classes
   {\tt Cjt\_estudiants} i {\tt Es\-tu\-diant}
*/

void extreure_reavaluables(const Cjt_estudiants& c1, const Cjt_estudiants& c2, double x, double y, double z, Cjt_estudiants& reava)
  /* Pre: c1 i c2 contenen els mateixos estudiants, reava es buit,
          0<=x,y,z<=Estudiant::nota_maxima(), x<=y */
  /* Post: el conjunt reava est� format pels estudiants reavaluables de c1 i c2 
           respecte a x,y,z, tots sense nota */
{
        int size = c1.mida();
        for (int i = 1; i <= size; ++i) {
                Estudiant est = c1.consultar_iessim(i);
                double nota;
                if (est.te_nota()) nota = est.consultar_nota();
                else nota = -1;
                if (nota >= x and nota <= y) {
                        est = c2.consultar_iessim(i);

                        if (est.te_nota()) nota = est.consultar_nota();
                        else nota = -1;

                        if (nota >= z) {
                                Estudiant est_temp(est.consultar_DNI());
                                bool b;
                                reava.afegir_estudiant(est_temp, b);
                        }
                }
        }

}
