#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double func(double num){
    return cos(num);
}

int main(){
    int counter = 0;
    bool found = true;
    double a,b;
    double eps = 0.0001;
    
    scanf("%lf %lf", &a,&b);
    double c = (a+b)/2;
    while(fabs(func(c)) > eps){
        counter++;
        if(func(a)*func(c) < 0){
            b = c;
            c = (a+b)/2;
        }
        else{
            a = c;
            c = (a+b)/2;
        }
        if(counter > 1000){
            found = false;
            break;
        }
    }
    if(found){
        printf("%f\n", c);
    }
    else{
        printf("no roots\n");
    }
    return 0;
}