#include <stdio.h>
#include <math.h>

double s(double a, double b, double c){

    double p = (a+b+c)/2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));

    return s;
}

int main(){

    const double eps = 0.0001;

    double x1,x2,x3,x4,y1,y2,y3,y4;
    double a,b,c,d,e,f;

    printf("input 3 coordinates as a pair x y\r\n");
    scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3);

    printf("input additional dot coordinates x y\r\n");
    scanf("%lf %lf", &x4 , &y4);

    a = sqrt(pow(fabs(x3-x1),2) + pow(fabs(y3-y1),2));
    b = sqrt(pow(fabs(x3-x2),2) + pow(fabs(y3-y2),2));
    c = sqrt(pow(fabs(x2-x1),2)+ pow(fabs(y2-y1),2));

    d = sqrt(pow(fabs(x4-x1),2)+ pow(fabs(y4-y1),2));
    e = sqrt(pow(fabs(x4-x2),2)+ pow(fabs(y4-y2),2));
    f = sqrt(pow(fabs(x4-x3),2)+ pow(fabs(y4-y3),2));

    double s_main = s(a, b, c);
    double s1 = s(d, f, a);
    double s2 = s(f, e, b);
    double s3 = s(d, e, c);

    double diff = fabs(s_main - (s1 + s2 + s3));

    if (diff > eps) {
        printf("Точка лежить поза трикутником\r\n");
    } 
    else if (s1 < eps || s2 < eps || s3 < eps) {
        printf("Точка лежить близько до межі трикутника\r\n");
    } 
    else {
        printf("Точка лежить в трикутнику\r\n");
    }

    return 0;
}