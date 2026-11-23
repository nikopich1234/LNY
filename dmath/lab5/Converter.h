#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#ifndef Converter
#define Converter

string InfixToPrefix(string infix);
string InfixToPostfix(string infix);
string PostfixToInfix(string postfix);
string PrefixToInfix(string prefix);
double PostfixEvaluate(string postfix);
double PrefixEvaluate(string prefix);
#endif