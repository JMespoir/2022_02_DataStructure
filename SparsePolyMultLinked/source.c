#include <stdio.h>
#include <stdlib.h>

#define FILENAME 20

typedef struct NODE{
    float coef;
    int expon;
    struct NODE* next;
}node;

void INFILE(char* A, char* B);
node* Append(node* head, node* cur);
node* MakeNode(float coeff, int exponn);
int COMPARE(int a, int b);
void PrintNode(node* head);
node* MultNode(node* headA,node* headB,node* headC);
node* InsertNode(node* head, node* cur);

int main(){
    char A[FILENAME],B[FILENAME];
    while(1){
        printf("POLY A FILE(IF YOU WANT EXIT PROGRAM, INPUT \"exit\") >> ");
        scanf("%s",A);
        if(!strcmp(A,"exit")){
            printf("==EXIT PROGRAM==\n");
            exit(0);
        }
        printf("POLY B FILE(IF YOU WANT EXIT PROGRAM, INPUT \"exit\") >> ");
        scanf("%s",B);
        if(!strcmp(B,"exit")){
            printf("==EXIT PROGRAM==\n");
            exit(0);
        }
        INFILE(A,B);
    }
}


void INFILE(char* A, char* B){
    node* polyA=NULL,*polyB=NULL,*polyC=NULL;
    FILE* fp = fopen(A,"r");
    float tem_coef;
    int tem_expon;
    if(!fp){
        printf("Cannot Find The File ==> %s",A);
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%f %d", &tem_coef,&tem_expon);
        polyA = Append(polyA,MakeNode(tem_coef,tem_expon));
    }
    fclose(fp);

    fp = fopen(B,"r");
    if(!fp){
        printf("Cannot Find The File ==> %s",B);
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%f %d", &tem_coef,&tem_expon);
        polyB = Append(polyB,MakeNode(tem_coef,tem_expon));
    }

    printf("[%s]\n",A);
    PrintNode(polyA);
    printf("[%s]\n",B);
    PrintNode(polyB);

    polyC= MultNode(polyA,polyB,polyC);
    printf("[%s * %s ]\n",A,B);
    PrintNode(polyC);
}

node* MultNode(node* headA,node* headB,node* headC){
    node* a= headA, *b = headB;
    node* cur=NULL;
    int mult_exp;
    float mult_coef;
    while(a !=NULL){
        while(b != NULL){
            mult_exp = a->expon + b->expon;
            mult_coef = a->coef * b->coef;
            if(mult_coef!=0){
                cur = MakeNode(mult_coef,mult_exp);
                headC = InsertNode(headC, cur);
            }
            b=b->next;
        }
        a=a->next;
        b = headB;
    }
    return headC;
}
node* InsertNode(node* head, node* cur){
    node *p=head,*q;
    float sum =0;
    if(head == NULL){
        head = cur;
        return cur;
    }
    while(p!=NULL){
        if(COMPARE(p->expon,cur->expon)==1){
            q=p;
            p=p->next;
            continue;
        }
        else if(COMPARE(p->expon, cur->expon)==0){
            sum = p->coef + cur->coef;
            if(sum){
                p->coef = sum;
                return head;
            }
            q->next = p->next;
            free(p);
            return head;
        }
        else{
            break;
        }
    }
    if(p==head){
        cur->next = p;
        head = cur;
        return head;
    }
    else{
        cur->next = p;
        q->next = cur;
        return head;
    }

}
node* Append(node* head, node* cur){
    node* p = head;
    if(head ==NULL){
        head = cur;
        return head;
    }
    while(p->next !=NULL){
        p=p->next;
    }
    p->next=cur;
    return head;
}
node* MakeNode(float coeff, int exponn){
    node* cur = malloc(sizeof(node));
    cur->coef = coeff;
    cur->expon = exponn;
    cur->next = NULL;
    return cur;
}
void PrintNode(node* head){
    if(head == NULL){
        printf("HEAD NULL!!");
    }
    node* p = head;
    while(p != NULL){
        printf("(%2.f,%2d)",p->coef,p->expon);
        p=p->next;
    }
    printf("\n");
}
int COMPARE(int a, int b){
    if(a>b){
        return 1;
    }
    else if( a==b){
        return 0;
    }
    else{
        return -1;
    }
}