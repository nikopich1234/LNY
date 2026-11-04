#include <iostream>
#include <string>
using namespace std;

#ifndef Converter
#define Converter

string InfixToPrefix(string infix);
string InfixToPostfix(string infix);
string PostfixToInfix(string postfix);
string PrefixToInfix(string prefix);

#endif