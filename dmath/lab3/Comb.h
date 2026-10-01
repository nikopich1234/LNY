#include <iostream>
#include <cmath>

using namespace std;

#ifndef COMB
#define COMB

typedef int datatype;

long long int factorial(int n);
long long int A(int n, int k);
long long int _A(int n, int k);
long long int C(int n, int k);
long long int _C(int n, int k);
void GenPerm(vector<datatype>& arr, int start, int end);

#endif