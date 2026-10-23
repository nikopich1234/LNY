#include <stdio.h>
#include <math.h>

double func(double n){
    return sin(n);
}

double sum(double a, int k, double h, int var, double (*func)(double)){
    double res = 0;
    switch(var){
        case 1:
        for(int i = 0; i < k; i++){
        res+=func((a+i*h+h/2));
        }
        return res;
        case 2:
        for(int i = 1; i < k; i++){
            res+=func((a+i*h));
        }
        return res;
        default:
        return 0;
    }
    
}

double integrate(double a, double b, int N, int method, double (*func)(double)){
    double res = 0;
    double h = (b-a)/N;
    switch(method){
        case 1:
            printf("rectangle method:\n");
            res = h*sum(a,N,h,method,func);
            break;
        case 2:
            printf("trapezoid method:\n");
            res = (h/2)*(func(a)+func(b))+h*sum(a,N,h,method,func);
            break;
        case 3:
            printf("Simpson`s method:\n");
            res = (h/6)*(func(a)+func(b)+4*sum(a,N,h,1,func)+2*sum(a,N,h,2,func));
            break;
        default:
            printf("Error\n");
            res = -1;
            break;
    }
    return res;
}

int main(){

    double a,b, res;
    int N;
    printf("a, b, N:\n");
    scanf("%lf %lf %i", &a,&b,&N);
    double h = (b-a)/N;
    for(int i = 1; i <=3; i++){
        res = integrate(a,b,N,i,func);
        printf("%lf\n", res);
    }

    return 0;
}