#include "Comb.h"
#include "Sort.h"

long long factorial(int n){
    long long int res = 1;
    for(int i = 1; i <=n; i++){
        res *= i;
    }
    return res;
}

long long A(int n, int k){
    return factorial(n) / factorial(n-k);
}

long long _A(int n, int k){
    return pow(n,k);
}

long long C(int n,int k){
    return A(n,k) / factorial(k);
}

long long _C(int n, int k){
    return factorial(n+k-1) / (factorial(k)*factorial(n-1));
}

void GenPerm(vector<datatype>& arr, int start, int end){
    
}