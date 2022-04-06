#include <iostream>
#include "BinTreeIOEst.hh"
using namespace std;

int busqueda(const BinTree<Estudiant>& arbol, int& nota, const int& est) {
    if (not arbol.empty()) {
        if (arbol.value().consultar_DNI() == est) {
            if (arbol.value().te_nota()) nota = arbol.value().consultar_nota();
            else nota = -1;
            return 0;
        }else {
            int left = busqueda(arbol.left(), nota, est);
            int nota2;
            int right = busqueda(arbol.right(), nota2, est);
            if (left != -1 and right != -1) {
                if (left <= right) return 1 + left;
                else {
                    nota = nota2;
                    return 1 + right;
                }
            }else if (left != -1) {
                return 1 + left;
            }else if (right != -1) {
                nota = nota2;
                return 1 + right;
            }else return -1;
        }
    }
    return -1;
}

int main() {
    BinTree<Estudiant> arbol;

    read_bintree_est(arbol);

    int est;
    while (cin >> est) {
        int nota;
        int profundidad = busqueda(arbol, nota, est);

        if (profundidad != -1) cout << est << ' ' << profundidad << ' ' << nota << endl;
        else cout << est << ' ' << -1 << endl;
    }
}