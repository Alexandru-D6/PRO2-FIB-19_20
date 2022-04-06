#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a){
    Estudiant x;
    x.llegir();

    if (x.consultar_DNI() != 0 or (x.te_nota() and x.consultar_nota() != 0)) {
        BinTree<Estudiant> l;
        read_bintree_est(l);
        BinTree<Estudiant> r;
        read_bintree_est(r);
        a = BinTree<Estudiant> (x, l, r);
    }
}

void write_bintree_est(const BinTree<Estudiant>& a); //(opcional)