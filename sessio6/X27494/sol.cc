#include <iostream>
#include <list>
using namespace std;

bool eliminar_inp(const int& inp, list<int>& l) {
    list<int>::iterator it = l.begin();

    bool acabado = false;
    while (it != l.end() and not acabado) {
        if (*it == inp) {
            it = l.erase(it);
            acabado = true;
        }else ++it;
    }

    return acabado;
}

void recalcular_max_min(int& min, int& max, const list<int>& l) {
    list<int>::const_iterator it = l.begin();

    min = *it;
    max = *it;
    ++it;

    while (it != l.end()) {
        if (*it < min) min = *it;
        if (*it > max) max = *it;
        ++it;
    }
}

void escribir_datos(const int& min, const int& max, const double& media, const int& l_size) {
    cout << min << ' ' << max << ' ' << media/l_size << endl;
}

int main() {
    list<int> l;
    int min, max;
    double media;

    int cmd;
    while (cin >> cmd and cmd != 0) {
        if (cmd == -1) {
            int inp; cin >> inp;

            if (l.empty()) {
                min = max = inp;
            }else {
                if (inp < min) min = inp;
                if (inp > max) max = inp;
            }

            l.push_back(inp);

            media += inp;
            escribir_datos(min, max, media, l.size());
        }else if (cmd == -2) {
            int inp; cin >> inp;
            int borrado = eliminar_inp(inp, l);
            if (borrado and not l.empty())  {
                media -= inp;
                recalcular_max_min(min, max, l);
            }
            if (not l.empty()) escribir_datos(min, max, media, l.size());
            else cout << '0' << endl;
        }
    }
    cin >> cmd;
}