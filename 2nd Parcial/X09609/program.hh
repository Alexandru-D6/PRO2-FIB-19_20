/*void bus_arbol_rec(node_arbre* node, node_arbre* &nodo_dist_min, int& dist_min, int dist, const int& x) {
    if (node != nullptr) {
        if (node->info == x and (dist <= dist_min or dist_min == -1)) {
            dist_min = dist;
            nodo_dist_min = node; 
        }

        bus_arbol_rec(node->segE, nodo_dist_min, dist_min, ++dist, x);
        bus_arbol_rec(node->segD, nodo_dist_min, dist_min, ++dist, x);
    }
}

void sub_arrel(Arbre& asub, const T& x) {
    node_arbre* asub_node = new node_arbre;
    asub_node = nullptr;
    int dist_min = -1;
    int dist = 0;

    bus_arbol_rec(primer_node, asub_node, dist_min, dist, x);

    asub.primer_node = copia_node_arbre(asub_node);
}*/

static T max(const T& x, const T& y, const T& z) {
    if (x >= y) {
        if (x >= z) return x;
        else return z;
    }else {
        if (y >= z) return y;
        else {
            return z; 
        }
    }
}

static void max_rec(node_arbre* node, node_arbre* node_max) {
    if (node != nullptr) {
        node_max = new node_arbre;

        max_rec(node->segD, node_max->segD);
        max_rec(node->segE, node_max->segE);

        if (node->segE != nullptr and node->segD != nullptr) {
            T temp = max(node->info, node_max->segD->info, node_max->segE->info);
            node_max->info = temp;
            cout << temp << endl;
        }else {
            node_max->info = node->info;
        }
    }
}

void arbre_maxims () {
    Arbre<T> a;
    max_rec(primer_node, a.primer_node);
}
    