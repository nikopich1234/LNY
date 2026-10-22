#include <stdio.h>
#include <math.h>

double func(double n){
    return sin(n);
}

double sum(double a, int k, double h, double *func(double)){
    
}

double integrate(double a, double b, int N, int method, double func(double)){
    double res = 0;
    switch(method){
        case 1:
            printf("rectangle method:\n");

            break;
        case 2:

            break;
        case 3:

            break;
        default:
            printf("Error");
            break;
    }
    return res;
}

int main(){

    double a,b;
    int N,method;
    double h = (b-a)/N;

    integrate(a,b,N,method,sum);

    return 0;
}