#include <stdio.h>
#include <stdlib.h>

#define FILENAME 20

typedef struct NODE{
    int element;
    struct NODE* next;
}node;

enum{
    False,True
};

node* INFILE(node* origin, char* infile);
int isODD(int num);
node* OriginNode(char* origin);
node* makenode(int num);
node* deletenode(node* list, int num);
node* freenode(node* list);
node* appendnode(node* head, node* cur);
void printnode(node* head);
node* Insertnode(node* head, node* cur);
int COMPARE(int a, int b);

int main(void){
    char file[FILENAME],origin[FILENAME];
    printf("ORIGIN FILE(if you want EXIT, INPUT \"exit\") >> ");
    scanf("%s",origin);
    if(!strcmp(origin,"exit")){
        printf("\nEXIT PROGRAM\n");
        return 0;
    }
    node* O = OriginNode(origin);
    while(1){
        printf("\nINFILE(if you want EXIT, INPUT \"exit\") >> ");
        scanf("%s",file);
        if(!strcmp(file,"exit")){
            printf("\nEXIT PROGRAM\n");
            break;
        }
        O=INFILE(O,file);
    }
    freenode(O);

}

node* INFILE(node* origin, char* infile){
    FILE* fp = fopen(infile,"r");
    int num;
    printf("[original]\n");
    printnode(origin);
    if(!fp){
        printf("== Cannot Find The File ==\n");
        return origin;
    }
    
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        if(isODD(num)){
            printf("Insert %d==>",num);
            origin = Insertnode(origin,makenode(num));
            printnode(origin);
        }
        else{
            printf("Delete %d==>",num);
            deletenode(origin,num);
            printnode(origin);
        }
    }

    fclose(fp);
    return origin;
}

int isODD(int num){
    if(num %2== 0){
        return True;
    }
    return False;
}

node* OriginNode(char* origin){
    node* head =NULL;
    FILE* fp = fopen(origin,"r");

    int num;
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        head = appendnode(head,makenode(num));
    }
    return head;
}

node* makenode(int num){
    node* cur= malloc(sizeof(node));
    cur->element = num;
    cur->next = NULL;
    return cur;
}

node* deletenode(node* list, int num){
    node* p=list->next;
    node* q =list;
    int compare;

    if(list == NULL){
        printf("%4d NO DELETE!!",num);
        return list;
    }

    if(list->element == num){
        list = list->next;
        free(p);
        return list;
    }

    while(p !=NULL){
        compare = COMPARE(p->element,num);
        if(compare==1){
            break;
        }
        if(compare == 0){
            q->next = p->next;
            free(p);
            return list;
        }
        if(compare == -1){
            q = p;
            p = p->next;
        }
    }
    printf("%4d NO DELIETE!!",num);
    return list;
}

node* freenode(node* list){
    node* p = list;
    if(list == NULL){
        return list;
    }
    while(p !=NULL){
        p=p->next;
        free(list);
        list = p;
    }
    return list;
}

node* appendnode(node* head, node* cur){
    node*p = head;
    if(head ==NULL){
        head = cur;
        return head;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = cur;
    return head;
}

void printnode(node* head){
    node* p=head;
    if(head == NULL){
        printf("NO ELEMENT!!\n");
        return;
    }
    while(p !=NULL){
        printf("%4d",p->element);
        p=p->next;
    }
    printf("\n");
}

node* Insertnode(node* head, node* cur){
    node* p=head->next;
    node* q =head;
    int compare;
    
    if(head == NULL){
        head = cur;
        return head;
    }
    if(head->element == cur->element){
        printf("%4d NO INSERT!!", cur->element);
        free(cur);
        return head;
    }

    while(p !=NULL){
        compare = COMPARE(p->element,cur->element);
        if(compare==1){
            break;
        }
        if(compare == 0){
            printf("%4d NO INSERT!!", cur->element);
            free(cur);
            return head;
        }
        if(compare == -1){
            q = p;
            p = p->next;
        }
    }
    

    if(p ==NULL){
        q->next=cur;
    }
    else if(q== head){
        cur->next = head;
        head = cur;
    }
    else{
        q->next=cur;
        cur->next=p;
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