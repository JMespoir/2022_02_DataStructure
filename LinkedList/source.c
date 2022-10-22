#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 20

typedef struct NODE{
    int element;
    struct NODE* next;
}node;

void FILEIN(char* filename);
node* Insertnode(node* head, node* cur);
node* makenode(int num);
node* freenode(node* head);
void printnode(node* head);

int main(void){

    char file[MAX_FILE_NAME];

    while(1){
        printf("FILENAME(if you want exit program, Input the \"exit\") >>  ");
        scanf("%s",file);
        if(!strcmp(file,"exit")){
            printf("\n--Exit The Program--\n");
            return;
        }
        printf("[%s]\n",file);
        FILEIN(file);
    }

}

void FILEIN(char* filename){
    int num;
    FILE* fp = fopen(filename,"r");
    node* head =NULL, *cur=NULL;
    if(!fp){
        printf("--Cannot find the file!!--\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        cur = makenode(num);
        head = Insertnode(head, cur);
    }
    printnode(head);
    head = freenode(head);
    printnode(head);//free check

}
node* Insertnode(node* head, node* cur){
    node*p=head,*q;
    while(p != NULL){
        if(cur->element==p->element){
            free(cur);
            return head;
        }
        else if(cur->element<p->element){
            break;
        }
        else{
            q=p;
            p=p->next;
        }
    }
    if(p==head){
        cur->next=p;
        head = cur;
    }
    else if(p==NULL){
        head = cur;
    }
    else{
        q->next = cur;
        cur->next = p;
    }

    return head;
}
node* makenode(int num){
    node* cur = malloc(sizeof(node));
    cur->element = num;
    cur->next = NULL;
    return cur;
}
node* freenode(node* head){
    node* p = head->next;
    while(p->next!=NULL){
        free(head);
        head = p;
        p=p->next;
    }
    free(p);
    return NULL;
}
void printnode(node* head){
    node* p = head;
    if(head ==NULL){
        printf("\nCannot Finde The Linkdelist\n\n");
    }
    while(p!=NULL){
        printf("%4d",p->element);
        p=p->next;
    }
}