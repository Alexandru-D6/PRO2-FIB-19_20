#include "utils.PRO2"
#include <list>

/* Pre: l no es vacia, sol es vacia */
/* Post: sel es el resultado de extraer de l los elementos debiles en media */
void seleccio(const list<double>& l, list<double>& sel) {
    list<double>::const_iterator itl = l.begin();

    int elementos_media = 1;
    double media = *itl;
    sel.insert(sel.end(), *itl);
    ++itl;

    while (itl != l.end()) {
        if (*itl >= media/double(elementos_media)) {
            sel.insert(sel.end(), *itl);
        }
        media += *itl;
        ++elementos_media;

        ++itl;
    }
}
/*
int main() {
    list<double> l;

    double inp;

    while (cin >> inp and inp != 0.00) {
        l.push_back(inp);
    }

    list<double> sel;

    seleccio(l, sel);

    for (list<double>::const_iterator it = sel.begin(); it != sel.end(); ++it) cout << *it << ' ' << endl;
}*/