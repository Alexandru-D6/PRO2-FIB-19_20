#include <iostream>
#include <map>
using namespace std;

int main() {
    char codigo;
    string palabra;
    map<string,int> mapa;

    while (cin >> codigo >> palabra) {
        if (codigo == 'a') {
            ++mapa[palabra];
        }else if (codigo == 'e') {
            --mapa[palabra];
            if (mapa[palabra] < 0) mapa[palabra] = 0;
        }else if (codigo == 'f') {
            cout << mapa[palabra] << endl;
        }
    }
}