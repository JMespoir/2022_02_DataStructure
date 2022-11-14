#include <stdio.h>
#include <stdlib.h>

typedef struct threadedTree{
	short int leftThread; // 쓰레드를 가리키는지 알려주는 것
	struct threadedTree* leftChild;
	char data;
	struct threadedTree* rightChild;
	short int rightThread;//쓰레드를 가리키는지 알려주는 것

}node;

node* insucc(node* tree){
	node* temp;
	temp=tree->rightChild;
	if(!tree->rightChild){
		while(!temp->leftThread){
			temp = temp->leftChild;
		}
	return temp;
	}
}

void tinorder(node* tree){
	node* temp = tree;
	while(temp->leftChild){
    temp=temp->leftChild;
  }
  do{
    printf("%3c",temp->data);
  }while(temp);
}

int main(void){

  node* A = malloc(sizeof(node));
  A->data = 'A';
  A->leftChild=NULL;
  A->rightChild=NULL;
  node* B = malloc(sizeof(node));
  B->data = 'B';
  B->leftChild=NULL;
  B->rightChild=NULL;
  node* C = malloc(sizeof(node));
  C->data = 'C';
  C->leftChild=NULL;
  C->rightChild=NULL;
  node* D = malloc(sizeof(node));
  D->data = 'D';
  D->leftChild=NULL;
  D->rightChild=NULL;
  node* E = malloc(sizeof(node));
  E->data = 'E';
  E->leftChild=NULL;
  E->rightChild=NULL;

  A->leftChild = B;
  B->leftChild=C;
  A->rightChild=D;
  D->rightChild=E;
  C->leftThread=1;
  E->rightThread=1;
  C->rightThread=1;
  E->rightThread=1;
  B->rightThread=1;
  D->leftThread=1;
  A->leftThread=0;
  A->rightThread=0;
  B->leftThread=0;
  D->rightThread=0;
  C->rightChild =B;
  C->rightChil
  


  tinorder(A);

}