static bool buscar_rec(node_arbreGen* nodo, const T& x) {
    if (nodo != nullptr) {
        if (nodo->info == x) return true;
        else {
            for (int i = 0; i < nodo->seg.size(); ++i) {
                bool res = buscar_rec(nodo->seg[i], x);
                if (res) return true;
            }
        }
    }
    return false;
}

bool buscar(const T& x) const {
    return buscar_rec(primer_node, x);
}