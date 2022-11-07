#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4 // 큐의 배열의 수

enum{
  X,Y,Z,W
};

typedef struct NODE{
  int element;
  struct NODE* next;
}node;

node* front[MAX_SIZE], *rear[MAX_SIZE];// 0,1,2,3 = X,Y,Z,W

void addQ(int i, int element);
int deleteQ(int i);
int isFull(int i);
int isEmpty(int i);
void printQ(int i);

int main(void){
  FILE* fp = fopen("in.txt","r");
  char tem[2];
  int ti;
  int q1,q2;
  int tem_c;
  if(!fp){
    printf("CANNOT FIND THE FILE!!\n");
    exit(0);
  }
  while(!feof(fp)){
    fscanf(fp, "%s",&tem);
    if(!strcmp(tem,"X")){
      fscanf(fp, "%d",&ti);
      printf("(Insert X %d) ==> ",ti);
      addQ(X,ti);
      printf("X: ");
      printQ(X);
    }
    else if(!strcmp(tem,"Y")){
      fscanf(fp, "%d",&ti);
      printf("(Insert Y %d) ==> ",ti);
      addQ(Y,ti);
      printf("Y: ");
      printQ(Y);
    }
    else if(!strcmp(tem,"Z")){
      fscanf(fp, "%d",&ti);
      printf("(Insert Z %d) ==> ",ti);
      addQ(Z,ti);
      printf("Z: ");
      printQ(Z);
    }
    else if(!strcmp(tem,"W")){
      fscanf(fp, "%d",&ti);
      printf("(Insert W %d) ==> ",ti);
      addQ(W,ti);
      printf("W: ");
      printQ(W);
    }
    else if(!strcmp(tem,"D")){
      fscanf(fp, "%s",&tem);
      if(!strcmp(tem,"X")){
        tem_c = X;
        printf("(Delete X) ==> ");
        if(isEmpty(X)){
          printf("Wating.Empty");
        }
        else{
          q1=deleteQ(X);
          printf("Person %d",q1);
          if(isEmpty(X)){
            printf(" Served.");
          }
          else{
            q2 = deleteQ(X);
            printf(" %d served.",q2);
          }
        }
      }
      else if(!strcmp(tem,"Y")){
        tem_c = Y;
        printf("(Delete Y) ==> ");
        if(isEmpty(Y)){
          printf("Wating.Empty");
        }
        else{
          q1=deleteQ(Y);
          printf("Person %d",q1);
          if(isEmpty(Y)){
            printf(" Served.");
          }
          else{
            q2 = deleteQ(Y);
            printf(" %d served.",q2);
          }
        }
      }
      else if(!strcmp(tem,"Z")){
        tem_c = Z;
        printf("(Delete Z) ==> ");
        if(isEmpty(Z)){
          printf("Wating.Empty");
        }
        else{
          q1=deleteQ(Z);
          printf("Person %d",q1);
          if(isEmpty(Z)){
            printf(" Served.");
          }
          else{
            q2 = deleteQ(Z);
            printf(" %d served.",q2);
          }
        }
      }
      else if(!strcmp(tem,"W")){
        tem_c = W;
        printf("(Delete W) ==> ");
        if(isEmpty(W)){
          printf("Wating.Empty");
        }
        else{
          q1=deleteQ(W);
          printf("Person %d",q1);
          if(isEmpty(W)){
            printf(" Served.");
          }
          else{
            q2 = deleteQ(W);
            printf(" %d served.",q2);
          }
        }
      }
      if(isEmpty(tem_c)){
        printf(" Empty");
      }
      else{
        printQ(tem_c);
      }
      }
      printf("\n");
    }
}

void addQ(int i, int k){
  node* temp = malloc(sizeof(node));
  temp->element = k;
  temp->next = NULL;
  if(front[i]){
    rear[i]->next = temp;
  }
  else{
    front[i] = temp;
  }
  rear[i] = temp;
}

int deleteQ(int i){
  node* temp = front[i];
  int num;
  num = temp->element;
  front[i] = temp->next;
  free(temp);
  return num;
}
int isEmpty(int i){
  if(NULL== front[i]){
    return 1;
  }
  return 0;
}
void printQ(int i){
  for(node* j=front[i];j != NULL; j=j->next){
        printf("[%2d]",j->element);
  }

}