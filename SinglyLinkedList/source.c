#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILENAME 20

typedef struct NODE{
    int element;
    struct NODE* next;
}node;

void INFILE(char * file1, char * file2);
node* makenode(int num);
node* appendnode(node* head, node* cur);
void printnode(node* head);
node* ANDnode(node* head1, node* head2);
node* freenode(node* head);
int COMPARE(int a,int b);

int main(){
    char file1[FILENAME];
    char file2[FILENAME];

    while(1){
        printf("A-FILENAME(if you want exit the program, INPUT \"exit\") >> ");
        scanf("%s",file1);
        if(!strcmp(file1,"exit")){
            printf("\n==Exit The Program==\n\n");
            break;
        }

        printf("B-FILENAME(if you want exit the program, INPUT \"exit\") >> ");
        scanf("%s",file2);
        if(!strcmp(file2,"exit")){
            printf("\n==Exit The Program==\n\n");
            break;
        }

        INFILE(file1,file2);
    }

}

void INFILE(char * file1, char * file2){
    node* A=NULL,*B=NULL,*cur=NULL,*C=NULL;
    FILE* fp=fopen(file1,"r");
    if(!fp){
        printf("==Cannot Find The File==\n\n");
        return;
    }
    int num;
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        cur = makenode(num);
        A= appendnode(A,cur);
    }
    fclose(fp);

    fp=fopen(file2,"r");
    if(!fp){
        printf("==Cannot Find The File==\n\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        cur = makenode(num);
        B=appendnode(B,cur);
    }
    fclose(fp);

    C=ANDnode(A,B);

    printf("[A - %s]\n",file1);
    printnode(A);
    printf("[B - %s]\n",file2);
    printnode(B);
    printf("[A AND B]\n");
    printnode(C);

    freenode(A);
    freenode(B);
    freenode(C);

    printf("\n\n");

}
node* makenode(int num){
    node* cur =malloc(sizeof(node));
    cur->element = num;
    cur->next = NULL;
    return cur;
}
node* appendnode(node* head, node* cur){
    node* p = head;
    if(head ==NULL){
        head = cur;
        return head;
    }
    while(p->next !=NULL){
        p=p->next;
    }
    p->next = cur;
    return head;
}

void printnode(node* head){
    node* p =head;
    if(head ==NULL){
        printf("NO ELEMENT!!\n");
        return;
    }
    while(p !=NULL){
        printf("%4d",p->element);
        p=p->next;
    }
    printf("\n");
    return;
}
node* ANDnode(node* head1, node* head2){
    node*p1 = head1, *p2 = head2;
    node*C =NULL;
    while(p1 && p2){
        switch (COMPARE(p1->element,p2->element))
        {
            case 1:
                p2=p2->next;
                break;
            case 0:
                C=appendnode(C,makenode(p1->element));
                p1=p1->next;
                p2=p2->next;
                break;
            case -1:
                p1=p1->next;

        }
    }
    return C;
}
node* freenode(node* head){
    if(head ==NULL){
        return head;
    }
    node* p =head->next;
    while(p!=NULL){
        free(head);
        head = p;
        p=p->next;
    }
    return head;
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
