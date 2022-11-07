#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct node{
  int data;
  struct node* leftChild, *rightChild;
}node;

node* makeTree(int num);
void inorder(node* root);

int main(void){
  int n;
  node* root;
  printf("Input number : ");
  scanf("%d",&n);
  root = makeTree(n);
  inorder(root);
}

node* makeTree(int num){
  node* head = NULL;
  if(num<=1000){
    head=(node*)malloc(sizeof(node));
    head->data = num;
    head->leftChild=makeTree(num*num);
    head->rightChild =makeTree(num*5);
  }
  return head;
}

void inorder(node* root){
  if(root){
    inorder(root->leftChild);
    printf("[%d]",root->data);
    inorder(root->rightChild);
  }
}