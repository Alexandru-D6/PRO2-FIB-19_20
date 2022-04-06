#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void retorna_valors(const vector<double>& datos) {
    cout << "min " << datos[0] << "; "
         << "max " << datos[1] << "; "
         << "media " << datos[2] << endl;
}

void recalcular_valors_sub(queue<int>& a, vector<double>& datos) {
    datos[2] *= a.size();
    datos[2] -= a.front();

    a.pop();

    datos[2] /= a.size();

    queue<int> aux = a;

    datos[0] = aux.front();
    datos[1] = aux.front();
    aux.pop();

    while (not aux.empty()) {
        if (datos[0] > aux.front()) datos[0] = aux.front();
        else if (datos[1] < aux.front()) datos[1] = aux.front();
        aux.pop();
    }
}

void recalcular_valors_add(queue<int>& a, vector<double>& datos, const int& inp) {
    if (not a.empty()) {
        if (datos[0] > inp) datos[0] = inp;
        else if (datos[1] < inp) datos[1] = inp;
    }else {
        datos[0] = inp;
        datos[1] = inp;
    }

    datos[2] *= a.size();
    datos[2] += inp;

    a.push(inp);

    datos[2] /= a.size();

}

int main() {
    queue<int> cola;
    vector<double> datos(3, 0.00);

    int inp;
    while (cin >> inp and inp >= -1001 and inp <= 1000) {
        if (inp == -1001) {
            if (not cola.empty() and cola.size() > 1) {
                recalcular_valors_sub(cola, datos);
                retorna_valors(datos);
            }else if (not cola.empty()) {
                cola.pop();
                cout << '0' << endl;
            }else cout << '0' << endl;
        }else {
            recalcular_valors_add(cola, datos, inp);
            retorna_valors(datos);
        }
    }
}