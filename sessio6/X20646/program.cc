#include <iostream>
#include "BinTreeIOParInt.hh"
using namespace std;

int busqueda_Tree(const int& x, int& acompanante, const BinTree<ParInt> a) {
    if (not a.empty()) {
        if (a.value().primer() == x) {
            acompanante = a.value().segon();
            return 0;
        }else {
            int left = busqueda_Tree(x, acompanante, a.left());
            if (left != -1) return 1 + left;
            int right = busqueda_Tree(x, acompanante, a.right());
            if (right != -1) return 1 + right;
        }
    }
    return -1;
}

int main() {
    BinTree<ParInt> arbol;

    read_bintree_parint(arbol);

    int inp; 

    while (cin >> inp) {
        int acompanante;
        int profundidad = busqueda_Tree(inp, acompanante, arbol);

        if (profundidad != -1) cout << inp << ' ' << acompanante << ' ' << profundidad << endl;
        else cout << -1 << endl;
    }
}