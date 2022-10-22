#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 100

void filesearch(char *, char *);
void printlist(int*,int);
void equal(int*,int*,int,int);
int COMPARE(int,int);

int main(){
    char file1name[MAX_BUF_SIZE];
    char file2name[MAX_BUF_SIZE];
    printf("what's The File Name 1 ==>>");
    scanf("%s",file1name);
    printf("what's The File Name 2 ==>>");
    scanf("%s",file2name);

    filesearch(file1name,file2name);
}

void filesearch(char * in1, char *in2){
    int out1[MAX_BUF_SIZE],out2[MAX_BUF_SIZE];
    FILE* fp = fopen(in1,"r");
    int tem,i=0,j=0;
    while(!feof(fp)){
        fscanf(fp,"%d",&tem);
        out1[i] = tem;
        i++;
    }
    i--;
    fclose(fp);

    fp = fopen(in2,"r");
    while(!feof(fp)){
        fscanf(fp,"%d",&tem);
        out2[j] = tem;
        j++;
    }
    j--;
    fclose(fp);


    printf("File1:");
    printlist(out1,i);
    printf("File2:");
    printlist(out2,j);
    printf("EQUAL:");
    equal(out1,out2,i,j);


}
void printlist(int* list, int num){
    for(int c=0;c<num;c++){
        printf(" %d",list[c]);
    }
    printf("\n");
}
void equal(int* list1,int* list2,int index1,int index2){
    int i = 0, j = 0;
    while(i<=index1 && j<=index2){
        switch(COMPARE(list1[i],list2[j]))
        {
            case -1:
                i++;
                break;
            case 0:
                printf(" %d",list1[i]);
                i++;
                j++;
                break;
            case 1:
                j++;
        }
    }
    printf("\n");
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