#include <stdio.h>

#define MAX 10

double det(double M[MAX][MAX], int n){
    double A[MAX][MAX];
    double d = 0;
    if(n == 1){
        d = M[0][0];
    }
    else if(n == 2){
        d = (M[0][0]*M[1][1] - M[0][1]*M[1][0]);
    }
    else{
        double C[MAX][MAX];
        for(int k = 0; k < n; k++){
            for(int i = 1; i < n; i++){
                for(int j = 0; j < k; j++){
                    C[i-1][j] = M[i][j];
                }
                for(int j = k+1; j < n; j++){
                    C[i-1][j-1]=M[i][j];
                }
            }
            if(k%2 == 0){
                d+=M[0][k]*det(C,n-1);
            }
            else{
                d-=M[0][k]*det(C,n-1);
            }
        }
    }
    return d;
}

int main(){
    double A[MAX][MAX], B[MAX];
    int n;
    scanf("%i", &n);
    double T[MAX][MAX];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &B[i]);
    }
    printf("main det: %lf\n",det(A,n));

    if(det(A,n) == 0){
        printf("det(A) = 0, no solutions\n");
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(k == i){
                    T[j][k] = B[j];
                }
                else{
                    T[j][k] = A[j][k];
                }
            }
        }
        printf("%lf ", det(T,n)/det(A,n));
    }
    printf("\n");
    return 0;
}