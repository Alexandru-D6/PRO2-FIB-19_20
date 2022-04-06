#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a){
    ParInt inp;

    if (inp.llegir()) {
        BinTree<ParInt> l;
        read_bintree_parint(l);
        BinTree<ParInt> r;
        read_bintree_parint(r);
        a = BinTree<ParInt>(inp, l, r);
    }
}

void write_bintree_parint(const BinTree<ParInt>& a);
