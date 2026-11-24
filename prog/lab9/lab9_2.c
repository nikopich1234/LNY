#include <stdio.h>
#include <stdint.h>

#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE  "\x1b[34m"
#define RESET "\x1b[0m"

void print_bits(uint64_t bits){
    printf(RED "%d" RESET " ", (int)(bits >> 63));

    printf(GREEN);
    for(int i = 62; i >= 52; i--)
        putchar('0' + (int)((bits >> i) & 1ULL));
    printf(RESET " ");

    printf(BLUE);
    for(int i = 51; i >= 0; i--)
        putchar('0' + (int)((bits >> i) & 1ULL));
    printf(RESET "\n");
}

int main(){
    double num;
    if(scanf("%lf", &num) != 1) return 1;
    uint64_t* p = (uint64_t*)&num;

    printf("Original: %g\n", num);
    print_bits(*p);

    *p ^= 1ULL << 63;
    printf("Sign flipped: %g\n", num);
    print_bits(*p);

    *p |= 3ULL << 50;
    printf("Two top mantissa bits set to 1: %g\n", num);
    print_bits(*p);

    *p += 2ULL << 52;
    printf("Exponent + 2: %g\n", num);
    print_bits(*p);

    return 0;
}