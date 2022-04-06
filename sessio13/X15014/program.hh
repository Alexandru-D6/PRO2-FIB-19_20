void arb_suma_rec(node_arbre* &primer, node_arbre* node, int &suma) const{
    if (node == NULL) {
        suma = 0;
    }else {
        suma = node->info;

        int suma_i, suma_d;
        node_arbre *arD, *arI;
        arD = arI = NULL;
        arb_suma_rec(arI, node->segE, suma_i);
        arb_suma_rec(arD, node->segD, suma_d);

        primer = new node_arbre;
        suma += suma_i + suma_d;
        primer->info = suma;
        primer->segE = arI;
        primer->segD = arD;


    }
}

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    int suma;
    node_arbre* primer = NULL;
    arb_suma_rec(primer, primer_node, suma);
    asum.primer_node = primer;
}

