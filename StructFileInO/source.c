#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 100
#define MAX_NAME_SIZE 20

typedef struct{
    char id[4];
    char name[MAX_NAME_SIZE];
    char Phone[14];
    int year;
}student;

void InandOut(char *inname, char*outname);

int main(){
    char inname[MAX_BUF_SIZE],outname[MAX_BUF_SIZE];
    printf("InFileName =>");
    scanf("%s",inname);
    printf("OutFileName =>");
    scanf("%s",outname);
    InandOut(inname,outname);
}

void InandOut(char *inname, char*outname){
    FILE* fp= fopen(inname,"r");
    student* list;
    int num,i=0,age;
    fscanf(fp,"%d",&num);
    list =(student*)malloc(sizeof(student)*num);
    while(i<num){
        fscanf(fp,"%s %s %s %d",list[i].id,list[i].name,list[i].Phone,&list[i].year);
        i++;
    }
    fclose(fp);

    fp = fopen(outname,"w");
    printf("Input age:");

    scanf("%d",&age);
    for(int j=0;j<i;j++){
        if(list[j].year >= age){
            printf("%s, %s, %s, %d\n",list[j].id,list[j].name,list[j].Phone,list[j].year);
            fprintf(fp,"%s, %s, %s, %d\n",list[j].id,list[j].name,list[j].Phone,list[j].year);
        }
    }
    fclose(fp);
    free(list);

    

}