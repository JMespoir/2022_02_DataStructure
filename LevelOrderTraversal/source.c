#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef struct node{
  char data;
  struct node* leftChild, *rightChild;
}node;

int front=0,rear= 0;
node* queue[MAX_QUEUE_SIZE];


node* levelOrder(node* head,char ch);
void postorder(node* ptr);
void preorder(node* ptr);
void inorder(node* ptr);
void addq(node* nod);
node* deleteq();

int main(void){
  char ch;
  node* Tree=NULL;
  printf("Input character:");
  scanf("%c",&ch);
  printf("level order :");
  for(char inchar = 'a'; inchar <= ch;inchar++){
    printf("%3c",inchar);
    Tree = levelOrder(Tree,inchar);
  }
  printf("\ninorder:");
  inorder(Tree);
  printf("\npreorder:");
  preorder(Tree);
  printf("\npostorder:");
  postorder(Tree);
}

node* levelOrder(node* head,char ch){
  node* temp = malloc(sizeof(node));
  front=0;
  rear=0;
  temp->data=ch;
  temp->leftChild=NULL;
  temp->rightChild=NULL;
  node* ptr=head;
  if(head ==NULL){
    head = temp;
    return head;
  }
  else{
    addq(ptr);
    for(;;){
      ptr = deleteq();
      if(!(ptr->leftChild)){
        ptr->leftChild = temp;
        return head;
      }
      if(!(ptr->rightChild)){
        ptr->rightChild = temp;
        return head;
      }
      if(ptr->leftChild){
        addq(ptr->leftChild);
      }
      if(ptr->rightChild){
        addq(ptr->rightChild);
      }
    }
  }
}

void postorder(node* ptr){
  if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%3c",ptr->data);
	}
}
void preorder(node* ptr){
  if(ptr){
		printf("%3c",ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void inorder(node* ptr){
  if(ptr){
		inorder(ptr->leftChild);
		printf("%3c",ptr->data);
		inorder(ptr->rightChild);
	}
}
void addq(node* nod){
  rear = (rear+1)%MAX_QUEUE_SIZE;
  if(front==rear){
    printf("Queue Full");
    return;
  }
  queue[rear] = nod;
}
node* deleteq(){
  if(front==rear){
    printf("Queue Empty");
    return NULL;
  }
  front=(front+1)%MAX_QUEUE_SIZE;
  return queue[front];
}