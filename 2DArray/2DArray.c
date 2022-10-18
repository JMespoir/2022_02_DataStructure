// 파일에서 2차원배열을 입력받아와서 동적할당으로 2차원 배열 생성. 표준 출력 후 전치행렬 파일출력 후  동적메모리 해제
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 100
void printList(int**,int, int);
int** make2Darray(char*,int*,int*);
void makeTheFile(char*,int**,int , int);


int main(){
    int** ary; 
    int row, col;
    char filename[MAX_BUF_SIZE];
    printf("What's the ReadFilename? => ");
    scanf("%s",filename);

    ary = make2Darray(filename,&row,&col);

    printf("[in1.txt]\n");
    printList(ary,row,col);

    printf("What's the WriteFilename? => ");
    scanf("%s",filename);
    makeTheFile(filename,ary,row, col);

    return 0;
}

void printList(int** aray,int row, int col){
    for(int i = 0;i<row;i++){
        for(int j =0;j<col;j++){
            printf("%4d",aray[i][j]);
        }
        printf("\n");
    }
}
int** make2Darray(char * filename,int* row, int *col){  //O(n^2)
    FILE* fp=fopen(filename,"r");
    int** ary;
    int num;
    fscanf(fp,"%d %d",*row,*col);
    ary = (int**)malloc(sizeof(int*)*(*row));
    for(int i=0;i<*row;i++){
        ary[i]= (int*)malloc(sizeof(int)*(*col));
    }

    for(int i =0;i<*row;i++){
        for(int j=0;j<*col;j++){
            fscanf(fp,"%d",ary[i][j]);
        }
    }
    fclose(fp);
    return ary;
}

void makeTheFile(char* filename,int** array,int row, int col){
    FILE* fp = fopen(filename,"w");
    
}