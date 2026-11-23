#include "List.h"
#include "Converter.h"

int main(){
    int n;
    string str;
    cout << "1: Infix to postfix\n"
    << "2: Infix to prefix\n"
    << "3: Postfix to infix\n"
    << "4: Prefix to infix\n"
    << "5: Postfix eval\n"
    << "6: Prefix eval\n";
    cin >> n;
    cin.ignore();
    getline(cin,str);
    switch(n){
        case 1:
        cout << InfixToPostfix(str);
        break;
        case 2:
        cout << InfixToPrefix(str);
        break;
        case 3:
        cout << PostfixToInfix(str);
        break;
        case 4:
        cout << PrefixToInfix(str);
        break;
        case 5:
        cout << PostfixEvaluate(str);
        break;
        case 6:
        cout << PrefixEvaluate(str);
        break;
        default:
        return 1;
    }
    return 0;
}