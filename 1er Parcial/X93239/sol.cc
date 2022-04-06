#include "utils.PRO2"
#include <vector>

/* Pre: cert */
/* Post: el resultat es el nombre d'elements frontissa de v */
int comptatge_frontisses(const vector<int> &v) {
    int suma_izq = 0;
    int suma_der = 0;

    int vsize = v.size();
    for (int i = 1; i < vsize; ++i) {
        suma_izq += v[i];
    }

    int contador = 0;
    for (int i = 0; i < vsize; ++i) {
        if (v[i] == suma_izq - suma_der) ++contador;

        suma_der += v[i];
        if (i < vsize - 1) suma_izq -= v[i+1];
    }

    return contador;
}