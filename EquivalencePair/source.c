#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

enum{
  FALSE,TRUE
};

typedef struct node{
  int num;
  struct node* next;
}node;

int main(void){
  char filename[MAX_SIZE];
  printf("FILE NAME==>");
  scanf("%s",filename);
  int i,j,n;
  node* x, *y,*top;
  node* seq[MAX_SIZE];
  int out[MAX_SIZE];
  FILE* fp = fopen(filename,"r");
  if(!fp){
    printf("CANNOT FIND THE FILE!!\n");
    exit(0);
  }
  fscanf(fp,"%d",&n);
  for(i=0;i<=n;i++){
    out[i]= TRUE;
    seq[i]= NULL;
  }
  while(!feof(fp)){
    fscanf(fp,"%d %d",&i,&j);
    x=(node*)malloc(sizeof(node));
    x->num=j;
    x->next = seq[i];
    seq[i] = x;
    x=(node*)malloc(sizeof(node));
    x->num=i;
    x->next = seq[j];
    seq[j] = x;
  }
  for(i=0;i<=n;i++){
    printf("[%d]",i);
    for(y=seq[i];y != NULL; y=y->next){
      printf(" <%d>",y->num);
    }
    printf("\n");
  }

  

  for(i=0;i<=n;i++){
    if(out[i]){
      printf("\nNew class: %5d",i);
      out[i] = FALSE;
      x=seq[i];
      top = NULL;
      for(;;){
        while(x){
          j=x->num;
          if(out[j]){
            printf("%5d",j);
            out[j] = FALSE;
            y=x->next;
            x->next = top;
            top = x;
            x=y;
          }
          else{
            x=x->next;
          }
        }
        if(!top){
          break;
        }
        x = seq[top->num];
        top=top->next;
      }
    }
  }
  printf("\n");
  return 0;
}