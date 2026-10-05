#include <stdio.h>
#include <math.h>

double eps = 0.0001;
double d = 0.000001;

double func(double num){
    return (pow(num,3) + cos(num));
}

double f1p(double num){
    return (func(num+d)-func(num))/d;
}

double f2p(double num){
    return (f1p(num+d)-f1p(num))/d;
}

double Newton_method(double a, double b){
    double c;
    int counter = 0;

    if(fabs(b-a) < eps){
        return (a+b)/2;
    } 
    else{
        if(func(a)*f2p(a)>0){
            c = a;
        }
        else if(func(b)*f2p(b) > 0){
            c = b;
        }
        else{
            printf("збіжність не гарантована\n");
            c = (a+b)/2;
        }
        for(int i = 0; i < 30; i++){
            if(fabs(func(c)) < eps){
                    break;
                }
            c = c - (func(c)/f1p(c));
            counter++;
        }
    }
    printf("iterations: %i\n", counter);
    return c;
}

int main(){

    double a,b,c;
    printf("input search range:\n");
    scanf("%lf %lf", &a,&b);
    printf("Newton method:\n");
    c = Newton_method(a,b);
            if(c >= a && c <= b){
            printf("root: %lf\n",c);

        }
        else{
            printf("root: %lf\n",c);
            printf("out of bounds\n");
        }

    return 0;
}