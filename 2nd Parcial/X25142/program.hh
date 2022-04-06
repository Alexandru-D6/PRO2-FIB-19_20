static void suma_rec(node_arbreGen* n, T suma, T& suma_max, const node_arbreGen* primer) {

    if (n != 0) {
        if (n != primer) suma += n->info;
        for (int i = 0; i < n->seg.size(); ++i) {
            suma_rec(n->seg[i], suma, suma_max, primer);
        }
        if (suma >= suma_max) suma_max = suma;
    }
}

  T max_suma_cami() const {
    T suma = primer_node->info;
    T suma_max = primer_node->info;
    suma_rec(primer_node, suma, suma_max, primer_node);
    return suma_max;
  }