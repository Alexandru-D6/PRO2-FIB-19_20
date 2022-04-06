Llista  reorganitzar_out(const T& x) const {
    Llista l;
    
    if (longitud == 0) return l;
    l.longitud = longitud;
    l.primer_node = l.act = l.ultim_node = NULL;

    node_llista* aux = NULL;
    node_llista* act1 = primer_node;

    while (act1 != NULL) {

      if (act1->info <= x) {

        if (l.primer_node == NULL) {
          aux = l.primer_node = new node_llista;
          l.primer_node -> ant = NULL;
        }else {
          aux->seg = new node_llista;
          aux -> seg -> ant = aux;
          aux = aux->seg;
        }
        aux -> info = act1 -> info; 

      }else {

        if (l.act == NULL) {
          l.act = l.ultim_node = new node_llista;
          l.act -> ant = NULL;
        }else {
          l.ultim_node -> seg = new node_llista;
          l.ultim_node ->seg ->ant = l.ultim_node;
          l.ultim_node = l.ultim_node -> seg;
        }
        l.ultim_node->info = act1->info;

      }
      act1 = act1->seg;
    }

    if (l.primer_node == NULL) l.primer_node = l.act;
    else if (l.act == NULL) l.ultim_node = aux;
    else {
      aux ->seg = l.act;
      l.act -> ant = aux;
    }

    l.ultim_node -> seg = NULL;
    return l;

  }