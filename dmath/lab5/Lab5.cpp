#include "List.h"
#include "Converter.h"

int main(){
    string infix;
    getline(cin,infix);
    cout << InfixToPostfix(infix) << "\n" << InfixToPrefix(infix) << "\n" << PostfixToInfix(InfixToPostfix(infix)) << "\n" << PrefixToInfix(InfixToPrefix(infix)) << "\n";
    return 0;
}