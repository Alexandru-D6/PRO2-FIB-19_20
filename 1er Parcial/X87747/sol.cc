#include <vector>
#include "utils.PRO2"
//#include <iostream>
//using namespace std;
 
 /* Pre: v.size() > 0 */
 /* Post: el resultat es el nombre de solitaris a v */
int solitaris(const vector<int> &v) {
    int v_size = v.size();
    int contador = 0;

    for (int i = 0; i < v_size; ++i) {
        if (i == v_size - 1) {
            if (i == 0) {
                ++contador;
            }else {
                if (v[i] != v[i-1]) ++contador;
            }
        }else if (i == 0) {
            if (v[i] != v[i+1]) ++contador;
        }else{
            if (v[i] != v[i-1] and v[i] != v[i+1]) ++contador;
        }
    }
    return contador;
}