#include <stdio.h>

int* equal(int*, int* ,int ,int,int*);
int COMPARE(int,int);
void printList(int*, int);

int main(){
    FILE* fp = fopen("in1.txt","r");
    int i=0,j=0;
    int a[100],b[100];
    int count=0;
    while(!feof(fp)){
        fscanf(fp,"%d",&a[i]);
        i++;
    }
    fclose(fp);

    fp = fopen("in2.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%d",&b[j]);
        j++;
    }
    fclose(fp);

    int* L = equal(a,b,i,j,&count);
    printList(L,count);

}

int* equal(int* a, int* b, int index1,int index2,int* count){
    int *L = (int*)malloc(sizeof(int)*(index1 + index2));
    int i=0,j=0,l=0;

    while(i<index1 && j < index2){
        switch (COMPARE(a[i],b[j]))
        {
            case 1:
                L[l] = b[j];
                j++;
                l++;
                break;

            case 0:
                L[l] = b[j];
                j++;
                l++;
                i++;
                break;

            case -1:
                L[l] = a[i];
                i++;
                l++;
        }
    }
    for(;i<index1;i++){
        L[l] = a[i];
        l++;
    }
    for(;j<index2;j++){
        L[l] = b[j];
        l++;
    }
    *count = l;
    return L;
}

int COMPARE(int a,int b){
    if(a>b){
        return 1;
    }
    if(a==b){
        return 0;
    }
    return -1;
}

void printList(int * list,int count){
    for(int i =0;i<count;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}