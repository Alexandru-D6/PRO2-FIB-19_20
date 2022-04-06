#include <iostream>
#include "ParInt.hh"
#include "CuaIOParInt.hh"
#include <queue>
using namespace std;

int main() {
    queue<ParInt> total;
    llegirCuaParInt(total);

    int time_A = 0, time_B = 0;
    queue<ParInt> a;
    queue<ParInt> b;

    while (not total.empty()) {
        if (time_A <= time_B) {
            a.push(total.front());
            time_A += total.front().segon();
            total.pop();
        }else {
            b.push(total.front());
            time_B += total.front().segon();
            total.pop();
        }
    }

    escriureCuaParInt(a);
    cout << endl;
    escriureCuaParInt(b);

}