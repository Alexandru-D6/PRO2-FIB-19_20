/* Pre: p.i. = C1, c = C2 */
/* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */

void trenat(Cua &c) {
    longitud += c.longitud;

    if (primer_node == nullptr) {
        primer_node = c.primer_node;
        ultim_node = c.ultim_node;
        longitud = c.longitud;
    }else if (c.primer_node == nullptr) {
        return;
    }else {
        node_cua* m = primer_node;
        node_cua* n = c.primer_node;
        node_cua* aux = nullptr;
        node_cua* aux2 = nullptr;

        while (m != nullptr and n != nullptr) {
            
            aux = m->seguent;
            aux2 = n->seguent;

            if (m->seguent == nullptr)  {
                m->seguent = n;
                ultim_node = c.ultim_node;
            }else {
                n->seguent = m->seguent;
                m->seguent = n;
            }

            m = aux;
            n = aux2;
        }
    }
}

static node_cua* salta(node_cua* p, int k) {
    while (p!=nullptr and k>0) {
        p = p->seguent;
        --k;
    }
    return p;
}

Cua galopar() {
    Cua<T> a;

    if (primer_node != nullptr) {
        a.demanar_torn(primer_node->info);
    }

    node_cua* aux = primer_node;
    aux = aux->seguent;
    int saltador = 2;

    while (aux != nullptr) {
        a.demanar_torn(aux->info);

        aux = salta(aux, saltador);
        saltador = saltador * 2;
    }    
    return a;
}
