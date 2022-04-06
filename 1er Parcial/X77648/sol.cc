#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"
using namespace std;

int diferentes_nodos(const BinTree<int> &a, const BinTree<int> &b) {
    if (not a.empty() and not b.empty()) {
        int l = 0 + diferentes_nodos(a.left(), b.left());
        int r = 0 + diferentes_nodos(a.right(), b.right());
        return l + r;
    }else if (a.empty() and b.empty()) {
        return 0;
    }else{
        if (a.empty()) {
            if (b.left().empty() and b.right().empty()) return 1;
            else return 2;
        }else{
            if (a.left().empty() and a.right().empty()) return 1;
            else return 2;
        }
    }
}

bool quasi_coincidents (const BinTree<int> &a, const BinTree<int> &b) {
    int contador = diferentes_nodos(a,b);
    return not (contador - 1);
}

/*int main() {
    BinTree<int> a;
    BinTree<int> b;

    read_bintree_int(a, 99);
    read_bintree_int(b, 99);

    cout << quasi_coincidents(a,b) << endl;
}*/

/*
7 6 -2 99 99 -3 99 99 -2 -1 99 99 3 99 99

4 9 -1 99 99 3 99 99 6 8 99 99 -3 1 99 99 99

10 -1 -2 99 99 99 -2 -1 99 99 3 99 99

-4 6 -1 99 99 3 99 99 -2 8 99 99 99

*/