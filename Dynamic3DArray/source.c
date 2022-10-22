#include <stdio.h>
#include <stdlib.h>

int main(void){
    int*** A;
    int I,J,K;
    printf("Input I:");
    scanf("%d",&I);
    printf("Input J:");
    scanf("%d",&J);
    printf("Input K:");
    scanf("%d",&K);

    A = (int***)malloc(sizeof(int**)*I);
    for(int i=0;i<I;i++){
        A[i] = (int**)malloc(sizeof(int*)*J);
    }
    for(int i=0;i<I;i++){
        for(int j=0;j<J;j++){
            A[i][j] = (int*)malloc(sizeof(int)*K);
        }
    }

    for(int i=0;i<I;i++){
        for(int j=0;j<J;j++){
            for(int k=0;k<K;k++){
                A[i][j][k] = i+j+k;
                printf("A[%d][%d][%d]=%d ",i,j,k,A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i =0;i<I;i++){
        for(int j=0;j<J;j++){
            free(A[i][j]);
        }
    }

    for(int i=0;i<I;i++){
        free(A[i]);
    }
    free(A);



}