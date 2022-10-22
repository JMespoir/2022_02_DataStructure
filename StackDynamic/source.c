#include <stdio.h>
#include <stdlib.h>

enum{
    False, True
};


int* stack;
int capacity = 1;
int top = -1;

int isEmpty();
int isFull();
void Push(int element);
void pop();
void doubling();
void reducing();
void printstack();
int main(){
    stack = (int*)malloc(sizeof(int)*capacity);
    FILE* fp = fopen("inin.txt","r");
    int num;
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        if(num != -1){
            printf("push item: %d ==>",num);
            Push(num);
            printf("\n");
        }
        else{
            printf("pop ==>");
            pop();
            printf("\n");
        }
    }

    printf("Final Stack Print\n");
    for(int i=top;i>=0;i--){
        printf("<%3d>\n",stack[i]);
    }
}

int isEmpty(){
    if(top == -1){
        return True;
    }
    return False;
}
int isFull(){
    if(top == capacity-1){
        return True;
    }
    return False;
}
void Push(int element){
    if(isFull()){
        doubling();
        stack[++top]= element;
    }
    else{
        stack[++top]= element;
    }
    printstack();
}
void pop(){
    if(isEmpty()){
        printstack();
        printf(":  cannot pop");
    }
    else{
        top--;
        if(top+1 <= capacity/2){
            reducing();
        }
        printstack();
    }
}
void doubling(){
    capacity *= 2;
    stack = (int*)realloc(stack, sizeof(int)*capacity);
    printf("doubling: %d",capacity);
}
void reducing(){
    if(capacity !=1){
        capacity /= 2;
        printf("reducing size(/2): %d",capacity);
    }
}

void printstack(){
    if(top == -1){
        printf("stack empty");
    }
    for(int i=0;i<=top;i++){
        printf("[%2d]",stack[i]);
    }
}