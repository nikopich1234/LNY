#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define N 10

int main(){
    int size = 0;
    int temp = 0;
    int MIN,MAX;
    int arr1[N], arr2[N];
    char str[50];
    int res = 0;
    srand(time(NULL));
    scanf("%i %i", &MIN, &MAX);

    printf("Random array:\n");
    for(int i = 0; i < N; i++){
        arr1[i] = MIN + rand() %(MAX-MIN+1);
        arr2[i] = arr1[i];
        printf("%i ", arr1[i]);
    }
    printf("\n");
    for(int i = 1; i < N; i++){
        int key = arr1[i];
        int j = i - 1;
        while(j >= 0 && arr1[j] > key){
            arr1[j+1] = arr1[j];
            j -= 1;
        }
        arr1[j+1]=key;
    }
    printf("Sorted array: \n");
    for(int i = 0; i < N; i++){
        printf("%i ", arr1[i]);
    }
    printf("\n");
    for(int i = 0; i < N-1; i++){
        if(arr2[i] < arr2[i+1]){
            temp++;
        }
        else{
            if(temp > size){
                size = temp;
            }
            temp = 0;
        }
    }
    if(temp > size){
        size = temp;
    }

    printf("length of longest increasing sub array:\n%i\n", size+1);

    getchar();
    printf("input number\n");
    fgets(str, 50, stdin);
    printf("%s",str);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    int neg = 0;

    for(int i = 0; i < len; i++){
        switch(str[i]){
            case '1':
                res += 1*pow(10,(len-i-1));
                break;
            case '2':
                res += 2*pow(10,(len-i-1));
                break;
            case '3':
                res += 3*pow(10,(len-i-1));
                break;
            case '4':
                res += 4*pow(10,(len-i-1));
                break;
            case '5':
                res += 5*pow(10,(len-i-1));
                break;
            case '6':
                res += 6*pow(10,(len-i-1));
                break;
            case '7':
                res += 7*pow(10,(len-i-1));
                break;
            case '8':
                res += 8*pow(10,(len-i-1));
                break;
            case '9':
                res += 9*pow(10,(len-i-1));
                break;
            case '0':
                break;
            case '-':
                neg = 1;
                break;
            default:
                return -1;
        }
    }
    if(neg == 1){
        res *= -1;
    }
    printf("%i\n",res+1234);

    return 0;
}