#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct{
    int row;
    int col;
    int value;
}sparse;

void inMatrix(char* filename, sparse* list);
void printMatrix(sparse* list);
void transpose(sparse* list , sparse* st);

int main(void){
    char in[MAX_SIZE];
    sparse A[MAX_SIZE],B[MAX_SIZE];
    sparse tA[MAX_SIZE],tB[MAX_SIZE];
    
    printf("Matrix A <<");
    scanf("%s",in);
    inMatrix(in,A);

    printf("Matrix B <<");
    scanf("%s",in);
    inMatrix(in,B);

    printf("[Matrix A]\n");
    printMatrix(A);
    
    printf("\n[Matrix B]\n");
    printMatrix(B);

    transpose(A,tA);
    transpose(B,tB);

    printf("[Transpose A]\n");
    printMatrix(tA);

    printf("[Transpose B]\n");
    printMatrix(tB);

}
void inMatrix(char* filename, sparse* list){
    FILE *fp = fopen(filename,"r");
    int row_s=-1,col_s=0;
    int col_l;
    int index= 1;
    int val;
    char buf[MAX_SIZE];
    char* tok = NULL;
    char* div = " ";


    while(!feof(fp)){
        fgets(buf,MAX_SIZE,fp);
        row_s++;
        tok = strtok(buf,div);
        col_l = 0;
        while(tok != NULL){
            val = atoi(tok);
            if(atoi(tok) != 0){
                list[index].row = row_s;
                list[index].col = col_l;
                list[index].value = val;
                index ++;
            }
            tok = strtok(NULL,div);
            col_l += 1;
        }
        col_s = col_l;
    }
    fclose(fp);

    list[0].col = col_s;
    list[0].row = row_s+1;
    list[0].value = index-1;
}
void printMatrix(sparse* list){
    int count= list[0].value;

    for(int i=0;i<=count;i++){
        printf("(%2d %2d %2d)\n",list[i].row,list[i].col,list[i].value);
    }
}
void transpose(sparse* list ,sparse* st){
    int count=list[0].value;
    st[0].row = list[0].col;
    st[0].col = list[0].row;
    st[0].value = count;
    int transpose[MAX_SIZE],rowTerms[MAX_SIZE],j;

    if(count>0){
        for(int i =0;i<st[0].row;i++){
            rowTerms[i] = 0;
        }
        for(int i = 1;i<=count;i++){
            rowTerms[list[i].col]++;
        }
        transpose[0]= 1;
        for(int i=1;i<st[0].row;i++){
            transpose[i]= transpose[i-1]+rowTerms[i-1];
        }
        for(int i=1;i<=count;i++){
            j = transpose[list[i].col]++;
            st[j].row = list[i].col;
            st[j].col = list[i]. row;
            st[j].value = list[i].value;
        }
    }
}