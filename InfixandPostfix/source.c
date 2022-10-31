//very hard hard hard

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

enum{
    left,right,plus,minus,mult,divide,modul,num,err
};

enum{
    False, True
};
int isp[]= {0,19,12,12,13,13,13,0,0};
int icp[] = {20,19,12,12,13,13,13,0,0};

int isFull(int* stack,int top);
int isEmpty(int* stack, int top);
void push(int* stack, int element,int *top);
int pop(int* stack,int *top);
void Infile(char* filename, char** infix,int* count);
int ChangePostfix(char* infix, char* postfix);
void value(char* postfix);
void printnotaion(char* notaion);
int checkNum(char n);
int checkOp_num(char n);
char checknum_Op(int n);

int main(){
    char in[20];
    char **infix;
    char ** postfix;
    int count;
    infix= (char**)malloc(sizeof(char*)*MAX_SIZE);
    for(int i =0;i<MAX_SIZE;i++){
        infix[i] = (char*)malloc(sizeof(char)*MAX_SIZE);
    }
    printf("Infix File >>");
    scanf("%s",in);
    Infile(in,infix,&count);

    postfix= (char**)malloc(sizeof(char*)*count);
    for(int i =0;i<count;i++){
        postfix[i] = (char*)malloc(sizeof(char)*MAX_SIZE);
    }

    for(int i =0;i<count;i++){
        printf("Infix: ");
        printnotaion(infix[i]);

        printf("Postfix: ");
        if(ChangePostfix(infix[i],postfix[i])){
            value(postfix[i]);
        }
        
    }
}

int isEmpty(int* stack, int top){
    if(top ==-1){
        return True;
    }
    return False;
}

void push(int* stack, int element,int *top){
    stack[++(*top)] = element;
}

int pop(int* stack,int *top){
    return stack[(*top)--];
}

void Infile(char* filename, char** infix,int* count){
    FILE* fp = fopen(filename, "r");
    int cnt = 0;
    while(!feof(fp)){
        fscanf(fp,"%s",infix[cnt]);
        cnt++;
    }

    *count = cnt;
}

int ChangePostfix(char* infix, char* postfix){
    int i=0,op,index = 0;

    int stack[MAX_SIZE];
    int top =0;
    stack[top] = err;
    char operation;
    while(strlen(infix)>i){
        op= checkOp_num(infix[i]);
        if(op == num){
            postfix[index++]=infix[i];
            i++;
        }
        else if(op == right){
            while(stack[top]!= left){
                if(isEmpty(stack,top-1)){
                    postfix[index] = 0;
                    printnotaion(postfix);
                    printf("...Parentheses mismatch!!\n\n");
                    return False;
                }
                postfix[index++]= checknum_Op(pop(stack,&top));
            }
            pop(stack,&top);
            i++;
        }
        else{
            while(isp[stack[top]]>=icp[op]){
                postfix[index++]= checknum_Op(pop(stack,&top));
            }
            push(stack,op,&top);
            i++;
        }
    }
    
    while(top != 0){
        postfix[index++]= checknum_Op(pop(stack,&top));
    }
    postfix[index] = 0;
    printnotaion(postfix);
    return True;
}

char checknum_Op(int n){
    switch (n)
        {
            case plus:
                return '+';
            case minus:
                return '-';
            case mult:
                return '*';
            case divide:
                return '/';
            case modul:
                return '%';
            case right:
                return ')';
            case left:
                return '(';
            default:
                return err;
        }
}

int checkOp_num(char n){
    switch (n)
    {
        case '+':
            return plus;
        case '-':
            return minus;
        case '*':
            return mult;
        case '/':
            return divide;
        case '%':
            return modul;
        case '(':
            return left;
        case ')':
            return right;
        default:
            return num;
    }
}

void value(char* postfix){
    int op1,op2;
    int stack[MAX_SIZE];
    int top = -1;
    int index = 0;
    while(strlen(postfix)>index){
        if(checkNum(postfix[index]) == True){
            push(stack,postfix[index]-'0',&top);
        }
        else{

            if(!isEmpty(stack,top)){
                op2 = pop(stack,&top);
            }
            if(!isEmpty(stack,top)){
                op1 = pop(stack,&top);
            }

            switch (postfix[index])
            {
                case '+':
                    push(stack,op1+op2,&top);
                    break;
                case '-':
                    push(stack,op1-op2,&top);
                    break;
                case '*':
                    push(stack,op1*op2,&top);
                    break;
                case '/':
                    push(stack,op1/op2,&top);
                    break;
                case '%':
                    push(stack,op1%op2,&top);
                    break;
                case '(':
                    printf("...Parentheses mismatch!!\n\n");
                    return;

            }
        }
        index++;
    }

    printf("Result: %d\n\n",stack[top]);
}

void printnotaion(char* notaion){
    for(int i =0;i<strlen(notaion);i++){
        printf("%c",notaion[i]);
    }
    printf("\n");
}

int checkNum(char n){
    if('0'<=n && n<='9'){
        return True;
    }
    return False;
}