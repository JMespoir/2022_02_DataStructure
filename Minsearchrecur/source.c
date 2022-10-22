#include <stdio.h>
#include <stdlib.h>


int findmin(int*, int);

int main(){
    FILE* fp=fopen("in.txt","r");
    int *ary;
    int size;

    fscanf(fp,"%d",&size);
    ary = (int*)malloc(sizeof(int)*size);

    printf("Numbers: ");
    for(int i=0;i<size;i++){
        fscanf(fp,"%d",&ary[i]);
        printf("%3d",ary[i]);
    }
    
    int min_recur = findmin(ary,size);
    printf("\nMin : %d",min_recur);
}

int findmin(int *ary, int size){
    int min;
    if(size==0){
        return ary[0]; 
    }
    min = findmin(ary,size-1);
    if(min>ary[size-1]){
        return ary[size-1];
    }
    else{
        return min;
    }
}