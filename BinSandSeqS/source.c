#include <stdio.h>


void binsearch(int *, int,int);
void seqsearch(int *, int,int);

int main(void){
    FILE* fp = fopen("in.txt","r");
    int ary[100];
    int i =0,search;
    while(!feof(fp)){
        fscanf(fp,"%d",&ary[i]);
        i++;
    }
    ary[i--]=0;
    fclose(fp);

    printf("search number? :");
    scanf("%d",&search);
    printf("iterative binary search >>");
    binsearch(ary,i,search);
    printf("sequential search >>");
    seqsearch(ary,i,search);
}

void binsearch(int * ary, int n,int search){
    int low = 0, high = n,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(ary[mid] == search){
            printf("success\n");
            return;
        }
        else{
            if(ary[mid]<search){
                low= mid+1;
            }
            else{
                high = mid -1;
            }
        }
    }
    printf("fail\n");
}
void seqsearch(int * ary, int n,int search){
    for(int i=0;i<n;i++){
        if(search == ary[i]){
            printf("success\n");
            return;
        }
    }
    printf("fail\n");
}

