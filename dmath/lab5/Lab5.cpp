#include "List.h"
#include "Converter.h"

int main(){
    string infix;
    getline(cin,infix);
    cout << "Infix to postfix: " << InfixToPostfix(infix) << "\n" << "Infix to prefix: " << InfixToPrefix(infix) << "\n" << "Postfix to infix: " << PostfixToInfix(InfixToPostfix(infix)) << "\n" << "Prefix to infix: " << PrefixToInfix(InfixToPrefix(infix)) << "\n";
    return 0;
}