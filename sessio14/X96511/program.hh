static void freq_rec(node_arbreGen* node, const T& x, int& suma) {
    if (node != nullptr) {
        if (node->info == x) ++suma;
        for (int i = 0; i < node->seg.size(); ++i) {
            freq_rec(node->seg[i], x, suma);
        }
    }
}

int freq(const T& x) const {
    int suma = 0;
    freq_rec(primer_node, x, suma);
    return suma;
}