#include <stdio.h>
#include <math.h>

int main(){

    int x = 2;
    int product = x*x;
    printf("Hello, World!\r\n");
    printf("2 * 2 = %i\r\n", product);


    double a, b, c, d, x1, x2;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    d = b * b - 4 * a * c;
    if (d > 0) {
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    printf("Two different real roots: x1 = %.2lf %.2lf\n", x1, x2);
    } else if (d < 0) {
    printf("There are no real roots\n");
    } else {
    x1 = x2 = -b / (2 * a);
    printf("Roots are real and the same: x1, x2 = %.2lf\n", x1);
    }


    return 0;
}