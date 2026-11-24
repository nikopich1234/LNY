#include <stdio.h>
#include <string.h>
#include <math.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int find_char(char* str, char target){
    char* ptr = strchr(str, target);

    if(ptr == NULL || *ptr == '\0'){
        return -1;
    }
    return (int)(ptr-str);
}

unsigned int decimal_convert(char* number, char* base, int basein){
    unsigned int decimal_number = 0;
    for(int i = 0; i < strlen(number)-1; i++){
        if(find_char(base, number[i]) == -1){
            printf("invalid digit\n");
            return -1;
        }
        else{
            if(find_char(base,number[i]) >= basein){
                printf("invalid digit\n");
                return -1;
            }
            decimal_number += pow(basein, (strlen(number)-i-2)) * find_char(base,number[i]);
        }
    }

    return decimal_number;
}

void universal_convert(char* base,unsigned int decimal, int baseout){
    if(decimal == 0){
        printf("0");
        return;
    }
    char number[40];
    int i = 0;
    while(decimal > 0){
        number[i] = base[decimal%baseout];
        decimal /= baseout;
        i++;
    }
    number[i] = '\0';
    for(int j = 0; j < i/2; j++){
        swap(&number[j],&number[i-j-1]);
    }
    printf("%i-base number: %s\n", baseout, number);
    return;
}

int main(){
    char base[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int basein = 9;
    const int baseout = 22;
    char number[20];
    
    printf("input number in 7-base system: ");
    fgets(number, sizeof(number), stdin);

    unsigned int decimal_number = decimal_convert(number, base, basein);
    printf("decimal number: %u\n", decimal_number);
    universal_convert(base, decimal_number, 2);
    universal_convert(base, decimal_number, 8);
    universal_convert(base, decimal_number, baseout);
    universal_convert(base, decimal_number, 16);

    return 0;
}