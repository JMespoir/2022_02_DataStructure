#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct{
  char name[20];
  int value;
}element;

element heap[MAX_ELEMENTS];

int n =0;
void push(element item);
element pop();
void printheap();

int main(void){
  element tem;
  int num;
  FILE* fp = fopen("in1.txt","r");
  while(!feof(fp)){
    fscanf(fp,"%s %d",&tem.name,&tem.value);
    push(tem);
  }
  fclose(fp);
  printf("Before deleting:\n");
  printheap();
  printf("\nInput number:");
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    tem = pop();
    printf("item(served): (%s, %d)\n",tem.name,tem.value);
  }
  printf("After deleting:\n");
  printheap();
}


void push(element item){
  int i;
  if(HEAP_FULL(n)){
    fprintf(stderr,"The Heap Is Full. \n");
    exit(EXIT_FAILURE);
  }
  i = ++n;
  while((i!=1)&&(item.value)<heap[i/2].value){
    heap[i] = heap[i/2];
    i= i/2;
  }
  heap[i] = item;
}

element pop(){
  int parent,child;
  element item,temp;
  if(HEAP_EMPTY(n)){
    fprintf(stderr,"The heap is Empty\n");
    exit(EXIT_FAILURE);
  }
  item = heap[1];
  temp= heap[n--];
  parent = 1;
  child = 2;
  while(child<=n){
    if((child<n)&& (heap[child].value > heap[child+1].value)){
      child++;
    }
    if(temp.value <= heap[child].value){
      break;
    }
    heap[parent] = heap[child];
    parent = child;
    child *=2;
  }
  heap[parent] = temp;
  return item;
}

void printheap(){
  for(int i =1;i<=n;i++){
    printf("[%s,%d]",heap[i].name,heap[i].value);
  }
  printf("\n");
}