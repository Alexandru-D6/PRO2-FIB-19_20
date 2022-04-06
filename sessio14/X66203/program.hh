static void searching_max_rec(node_arbreNari* main, T& max, const int& N) {
    if (main == nullptr) return;
    else {
        if (main->info > max) max = main->info;

        for (int i = 0; i < N; ++i) {
            searching_max_rec(main->seg[i], max, N);
        }
    }
}

T maxim() const {
    T max = primer_node->info;

    searching_max_rec(primer_node, max, N);

    return max;
}