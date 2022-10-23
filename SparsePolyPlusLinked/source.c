#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME 20

typedef struct NODE{
    float coef;
    int expon;
    struct NODE* next;
}node;

node* makenode(float co, int ex);
node* append(node* head, node* cur);
node* freenode(node* head);
void printnode(node* head);
void INFILE(char* fileA, char* fileB);
int COMPARE(int a, int b);
node* addnode(node* A, node* B,node* C);


int main(){
    char fileA[FILENAME], fileB[FILENAME];
    while(1){
        printf("POLY A FILE(if you want EXIT program, INPUT \"exit\") >> ");
        scanf("%s",fileA);
        if(!strcmp(fileA,"exit")){
            printf("==EXIT PROGRAM==\n");
            return 0;
        }
        printf("POLY B FILE(if you want EXIT program, INPUT \"exit\") >> ");
        scanf("%s",fileB);
        if(!strcmp(fileB,"exit")){
            printf("==EXIT PROGRAM==\n");
            return 0;
        }
        INFILE(fileA,fileB);
    }
}

node* makenode(float co, int ex){
    node* cur = malloc(sizeof(node));
    cur->coef=co;
    cur->expon =ex;
    cur->next =NULL;
    return cur;
}

node* append(node* head, node* cur){
    node* p =head;
    if(head ==NULL){
        head = cur;
        return head;
    }
    while(p->next != NULL){
        p=p->next;
    }
    p->next = cur;
    return head;
}

node* freenode(node* head){
    node* hed = head;
    node* p = head->next;
    node* q = head;
    if(head == NULL){
        printf("Empty List Error!!\n");
        return head;
    }
    while(p != NULL){
        free(q);
        q = p;
        p=p->next;
    }
    free(q);
    return NULL;
}

void printnode(node* head){
    node* p = head;
    if(head ==NULL){
        printf("empty list!");
    }
    while(p !=NULL){
        printf("<%4.f,%5d> ",p->coef,p->expon);
        p = p->next;
    }
    printf("\n");
}

void INFILE(char* fileA, char* fileB){
    node* A=NULL,*B=NULL,*C =NULL;
    FILE* fp = fopen(fileA, "r");
    float coef;
    int exp;
    if(!fp){
        printf("== Cannot Find The File ==\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%f %d",&coef ,&exp);
        A = append(A,makenode(coef,exp));
    }
    fclose(fp);


    fp=fopen(fileB,"r");
    if(!fp){
        printf("== Cannot Find The File ==\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%f %d",&coef ,&exp);
        B = append(B,makenode(coef,exp));
    }
    fclose(fp);

    printf("%10s","poly A:");
    printnode(A);

    printf("%10s","poly B:");
    printnode(B);


    C = addnode(A,B,C);
    printf("%10s","poly(A+B):");
    printnode(C);


    printf("after erasing...\n");

    A=freenode(A);
    printnode(A);

    B=freenode(B);
    printnode(B);

    C=freenode(C);
    printnode(C);

}

node* addnode(node* A, node* B, node* C){
    node* pa =A, *pb=B;
    float sum;
    while(pa && pb){
        switch (COMPARE(pa->expon,pb->expon))
        {
            case 1:
                C = append(C, makenode(pa->coef,pa->expon));
                pa = pa->next;
                break;
            case 0:
                sum = pa->coef + pb->coef;
                if(sum){
                    C = append(C, makenode(sum,pb->expon));
                }
                pa = pa->next;
                pb = pb->next;
                break;
            case -1:
                C = append(C, makenode(pb->coef,pb->expon));
                pb = pb->next;
        }
    }
    for(; pa;pa = pa->next){
        C = append(C, makenode(pa->coef,pa->expon));
    }
    for(; pb;pb = pb->next){
        C = append(C, makenode(pb->coef,pb->expon));
    }
    return C;
}

int COMPARE(int a, int b){
    if(a>b){
        return 1;
    }
    else if(a==b){
        return 0;
    }
    else{
        return -1;
    }
}

