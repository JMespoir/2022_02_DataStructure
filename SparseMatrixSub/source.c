#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int row;
    int col;
    int value;
}sparse;


int COMPARE(int a,int b);
void sub(sparse* A, sparse* B, sparse* C);
void inSparse(char* filename, sparse* S);
void printList(sparse* L);
int main(void){
    char in[MAX_SIZE];
    sparse A[MAX_SIZE],B[MAX_SIZE],C[MAX_SIZE];
    printf("Matirx A <<");
    scanf("%s",in);
    inSparse(in,A);

    printf("Matirx B <<");
    scanf("%s",in);
    inSparse(in,B);

    printf("\n[Matrix A]\n");
    printList(A);
    printf("\n[Matrix B]\n");
    printList(B);

    
    sub(A,B,C);

    printf("\n[Matrix A - Matrix B]\n");
    printList(C);

}

int COMPARE(int a,int b){
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
void sub(sparse* A, sparse* B,sparse* C){
    int valA = A[0].value, valB= B[0].value;
    int a=1, b=1, c=1, sub;
    C[0].row = A[0].row;
    C[0].col = A[0].col;
    while(a<=valA&& b<=valB){
        switch (COMPARE(A[a].row,B[b].row))
        {
            case 1:
                C[c].row = B[b].row;
                C[c].col = B[b].col;
                C[c].value = -B[b].value;
                c++;
                b++;
                break;
            case 0:
                switch (COMPARE(A[a].col,B[b].col))
                {
                    case 1:
                        C[c].row = B[b].row;
                        C[c].col = B[b].col;
                        C[c].value = -B[b].value;
                        c++;
                        b++;
                        break;
                    case 0:
                        sub = A[a].value - B[b].value;
                        if(sub){
                            C[c].row = A[a].row;
                            C[c].col = A[a].col;
                            C[c].value = sub;
                            c++;
                        }
                        a++;
                        b++;
                        break;
                    case -1:
                        C[c].row = A[a].row;
                        C[c].col = A[a].col;
                        C[c].value = A[a].value;
                        c++;
                        a++;
                }
                break;
            case -1:
                C[c].row = A[a].row;
                C[c].col = A[a].col;
                C[c].value = A[a].value;
                c++;
                a++;
        }
    }

    for(;a<=valA;a++){
        C[c].row = A[a].row;
        C[c].col = A[a].col;
        C[c].value = A[a].value;
        c++;
    }
    for(;b<=valB;b++){
        C[c].row = B[b].row;
        C[c].col = B[b].col;
        C[c].value = -B[b].value;
        c++;
    }
    C[0].value = c-1;

}
void inSparse(char* filename, sparse* S){
    FILE* fp = fopen(filename,"r");
    char* tok =NULL;
    char * div = " ";
    int index =1, row_f = -1, col_s=0,col_l;
    char tem[MAX_SIZE];
    while(!feof(fp)){
        fgets(tem, MAX_SIZE, fp);
        row_f ++;
        tok = strtok(tem, div);
        col_s = 0;
        while(tok != NULL){
            if(atoi(tok) != 0){
                S[index].col = col_s;
                S[index].row = row_f;
                S[index].value = atoi(tok);
                index++;
            }
            tok = strtok(NULL,div);
            col_s ++;
        }
        col_l= col_s; 
    }

    fclose(fp);
    S[0].value = index-1;
    S[0].row = row_f+1;
    S[0].col = col_l;
}

void printList(sparse* L){
    int count = L[0].value;
    for(int i =0;i<=count;i++){
        printf("(%2d %2d %2d)\n",L[i].row,L[i].col,L[i].value);
    }
    printf("\n");
}