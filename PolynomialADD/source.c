#include <stdio.h>

#define MAX_SIZE 1000
#define FILE_SIZE 100
typedef struct poly
{
    float coef;
    int expon;
}poly;

void inPoly(char* filename, poly* p, int* count);
void printpoly(poly* p, int count);
void ADDpoly(poly* A, poly* B, poly* C,int a, int b,int* c);
int COMPARE(int a, int b);

int main(){
    int a=0,b=0,c=0;
    poly A[MAX_SIZE],B[MAX_SIZE],C[MAX_SIZE];
    char in[FILE_SIZE];

    printf("A(x) <=");
    scanf("%s",in);
    inPoly(in,A,&a);

    printf("B(x) <=");
    scanf("%s",in);
    inPoly(in,B,&b);

    printf("A(x):");
    printpoly(A,a);
    
    printf("B(x):");
    printpoly(B,b);

    ADDpoly(A,B,C,a,b,&c);
    printf("\nC(x):");
    printpoly(C,c);
    
}

void inPoly(char* filename, poly* p, int* count){
    FILE* fp = fopen(filename,"r");
    int i =0;
    while(!feof(fp)){
        fscanf(fp,"%f %d",&p[i].coef,&p[i].expon);
        i++;
    }
    *count = i;
}

void printpoly(poly* p, int count){
    if(count ==0){
        printf("0");
    }
    for(int i =0;i<count;i++){
        if(i != count-1){
            printf("%.fx^%d + ",p[i].coef,p[i].expon);
        }
        else{
            printf("%.fx^%d",p[i].coef,p[i].expon);
        }
    }
    printf("\n");
}

void ADDpoly(poly* A, poly* B,poly* C, int a, int b,int*c){
    int indexc =0;
    int indexa =0, indexb= 0;
    float sub;
    while(indexa<a && indexb<b){
        switch (COMPARE(A[indexa].expon,B[indexb].expon))
        {
            case 1:
                C[indexc].expon = B[indexb].expon;
                C[indexc++].coef = -B[indexb++].coef;
                break;
            case 0:
                sub = A[indexa].coef - B[indexb].coef;
                if(sub){
                    C[indexc].expon = B[indexb].expon;
                    C[indexc++].coef = sub;
                }
                indexa++;
                indexb++;
                break;
            case -1:
                C[indexc].expon = A[indexa].expon;
                C[indexc++].coef = A[indexa++].coef;

        }
    }
    for(;indexa<a;indexa++){
        C[indexc].expon = A[indexa].expon;
        C[indexc++].coef = A[indexa].coef;
    }
    for(;indexb<b;indexb++){
        C[indexc].expon = B[indexb].expon;
        C[indexc++].coef = B[indexb].coef;
    }
    *c = indexc; 
}



int COMPARE(int a, int b){
    if(a>b){
        return 1;
    }
    else if(a == b){
        return 0;
    }
    else{
        return -1;
    }
}


