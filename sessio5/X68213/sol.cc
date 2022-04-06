#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<stack<string>> vec(n);

    int comd;
    while (cin >> comd and comd != -4) {
        if (comd == -1) {
            string book;
            int st;
            cin >> book >> st;
            vec[st-1].push(book);
        }else if (comd == -2) {
            int ref_books, st;
            cin >> ref_books >> st;

            for (int i = 0; i < ref_books; ++i) vec[st-1].pop();
        }else if (comd == -3) {
            stack<string> temp;
            int st;
            cin >> st;

            cout << "Pila de la categoria " << st << endl;
            
            temp = vec[st-1];

            while (not temp.empty()) {
                cout << temp.top() << endl;
                temp.pop();
            }
            cout << endl;
        }
    }
}
