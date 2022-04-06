#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    int num;
    cin >> num;

    bool impar = num%2;
    int mitad = num/2;
    bool palindromo = true;

    int i = 0;
    while (palindromo and i < num) {
        int inp;
        cin >> inp;
        if (!impar or i != mitad) {
            if (i >= mitad) {
                if (inp == s.top()) s.pop();
                else palindromo = false;
            }else s.push(inp);
        }
        ++i;
    }

    if(palindromo) cout << "SI" << endl;
    else cout << "NO" << endl;
}