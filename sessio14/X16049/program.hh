void  reorganitzar_in(const T& x) {
    if (longitud == 0) return;

    node_llista* aux = primer_node;
    node_llista* itp = primer_node;
    node_llista* ita = act;
    primer_node = act = ultim_node = NULL;

    while (aux != NULL) {

      if (aux->info <= x) {

        if (primer_node == NULL) {
          primer_node = itp = aux;
          itp ->ant = NULL;
        }else {
          itp->seg = aux;
          itp->seg->ant = itp;
          itp = itp->seg;
        }

      }else {
        
        if (act == NULL) {
          act = ita = aux;
          ita -> ant = NULL;
        }else {
          ita->seg = ultim_node = aux;
          ita->seg->ant = ita;
          ita = ita->seg;
        }

      }
      aux = aux->seg;

    }

    if (primer_node == NULL) primer_node = act;
    else if (act == NULL) ultim_node = itp;
    else {
      itp->seg = act;
      act->ant = itp;
    }

    ultim_node->seg = NULL;
  }