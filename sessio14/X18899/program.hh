static void arbsuma_rec(node_arbreNari* node, node_arbreNari* &node_suma, int& suma) {
    if (node == nullptr) {
      suma = 0;
      return;
    }else {
      suma = node->info;
      node_suma = new node_arbreNari;
      node_suma->seg = vector<node_arbreNari*>(node->seg.size());

      for (int i = 0; i < node->seg.size(); ++i) {
        node_arbreNari* aux = nullptr;
        int suma_1 = 0;
        arbsuma_rec(node->seg[i], aux, suma_1);
        suma += suma_1;
        node_suma->seg[i] = aux;
      }

      node_suma->info = suma;
    }
  }

  void arbsuma(ArbreNari& asum) const {
    int suma = 0;
    asum.N = this->N;
    arbsuma_rec(primer_node, asum.primer_node, suma);
  }