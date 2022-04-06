#include <iostream>
#include <map>
using namespace std;

int main() {
    char codi;
    string palabra;

    map<string, int> mapa;

    while (cin >> codi >> palabra) {
        if (codi == 'a') {
            mapa[palabra] += 1;
        }else if (codi == 'f') {
            cout << mapa[palabra] << endl;
        }
    }
}