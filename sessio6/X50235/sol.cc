//#include <iostream>
#include "BinTree.hh"
//#include "BinTreeIOint.hh"
//using namespace std;

bool poda_subarbre(BinTree<int> &a, int x) {
    if (not a.empty()) {
        if (a.value() == x) {
            a = BinTree<int> ();
            return true;
        }

        BinTree<int> aux = a.left();
        BinTree<int> aux2 = a.right();

        int left = poda_subarbre(aux, x);
        int right = poda_subarbre(aux2,x);

        a = BinTree<int> (a.value(), aux, aux2); 

        if (left or right) return true;
        else return false;

    }return false;
}
/*
int main() {
    BinTree<int> a;

    read_bintree_int(a, 0);
    int x;
    cin >> x;
    cout << poda_subarbre(a, x) << endl;
    write_bintree_int(a);
}*/