/* Pre: parametre implicit = P */
/* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
referenciava a una aparicio d'x, passa a referenciar al primer element
diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
a la dreta el tot); en cas contrari, el punt d'interes no canvia */

void esborrar_tots(const T& x) {
    node_llista* aux = primer_node;

    while (aux != nullptr) {
        if (aux->info == x) {
            if (act == aux) act = act->seg;

            if (aux == primer_node) {
                if (aux == ultim_node) {
                    ultim_node = nullptr;
                    primer_node = nullptr;
                }else {
                    primer_node = aux->seg;
                    primer_node->ant = nullptr;
                }

                delete aux;
                aux = primer_node;

            }else if (aux == ultim_node) {
                if (aux == primer_node)  {
                    primer_node = nullptr;
                    ultim_node = nullptr;
                }else {
                    ultim_node = aux->ant;
                    ultim_node->seg = nullptr;
                }

                delete aux;
                aux = nullptr;

            }else {
                node_llista* aux2 = aux->seg;
                aux->ant->seg = aux->seg;
                aux->seg->ant = aux->ant;
                delete aux;
                aux = aux2;
                
            }
            --longitud;

        }else aux = aux->seg;
    }
}

static int salta(node_llista* p, int k) {
    if (p == nullptr and k != 0) return -1;
    else if (k == 0) return p->info;
    else {
        return salta(p->seg, --k);
    }
}