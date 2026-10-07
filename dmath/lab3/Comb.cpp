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
    int i;
    
    for(i = end-1; i > start; i--){
        if(arr[i-1] < arr[i]){
            break;
        }
    }
    if(i == start){
        return;
    }
    
    int j;
    
    for(j = end-1; j >=i; j--){
        if(arr[j]>arr[i-1]){
            break;
        }
    }

    myswap(arr[i-1],arr[j]);

    SortSelection(arr, i, end, 0);
}

void GenComb(vector<datatype>& arr, int start, int end, int n, int k){
    int i;
    for(i = end-1; i >= start; i--){
        if(arr[i] != (n-k+i+1)){
            arr[i]++;
            break;
        }
    }
    if(i < start){
        return;
    }
    int j;
    for(j = i+1; j < end; j++){
        arr[j] = arr[j-1]+1;
    }
}