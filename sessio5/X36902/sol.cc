#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;

    char inp;
    bool todo_correcto = true;
    while (cin >> inp and todo_correcto and inp != '.') {
        if (inp == '(' or inp == '[') s.push(inp);
        else if (inp == ')') {
            if (s.empty() or s.top() != '(') todo_correcto = false;
            else s.pop();
        }else if (inp == ']') {
            if (s.empty() or s.top() != '[') todo_correcto = false;
            else s.pop();
        }
    }

    if (todo_correcto and s.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}