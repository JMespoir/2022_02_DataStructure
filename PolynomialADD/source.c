#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Polynomial{
  int expon;
  float coef;
}P;

void inPoly(char* filename, P* p, int* count);
void printpoly(P* p, int count);
void ADDpoly(P* A, P* B, P* C,int a, int b,int* c);
int COMPARE(int a, int b);
void Minuspoly(P* A, P* B, P* C,int a, int b,int* c);

int main(void){
  char filename[MAX_SIZE];
  int a,b,c,d;
  P A[MAX_SIZE],B[MAX_SIZE],C[MAX_SIZE],D[MAX_SIZE];

  printf("Enter A FileName << ");
  scanf("%s",filename);
  inPoly(filename,A,&a);

  printf("Enter B FileName << ");
  scanf("%s",filename);
  inPoly(filename,B,&b);

  printf("Polynomial A >>\n");
  printpoly(A,a);

  printf("Polynomial B >>\n");
  printpoly(B,b);

  ADDpoly(A,B,C,a,b,&c);
  Minuspoly(A,B,D,a,b,&d);

  printf("Polynomial A+B >>\n");
  printpoly(C,c);

  printf("Polynomial A-B >>\n");
  printpoly(D,d);

  
}

void inPoly(char* filename, P* p, int* count){
  FILE* fp = fopen(filename,"r");
  int index=0,inExpon;
  float inCoef;
  if(!fp){
    printf("Not Find The File\n");
    exit(0);
  }
  while(!feof(fp)){
    fscanf(fp,"%f %d",&inCoef,&inExpon);
    if(inCoef!=0){
      p[index].coef = inCoef;
      p[index].expon = inExpon;
      index++;
    }
  }
  *count = index;
}
void printpoly(P* p, int count){
  if(count ==0){
    printf("0\n");
    return;
  }
  for(int i=0;i<count-1;i++){
    if(p[i].expon == 0){
      printf("%.f",p[i].coef);

      if(p[i+1].coef>0){
        printf(" + ");
      }
      continue;
    }

    printf("%.fx^%d",p[i].coef,p[i].expon);

    if(p[i+1].coef>0){
      printf(" + ");
    }
  }

  if(p[count-1].expon == 0){
      printf("%.f\n",p[count-1].coef);
      return;
  }
  printf("%.fx^%d\n",p[count-1].coef,p[count-1].expon);

}
void ADDpoly(P* A, P* B, P* C,int a, int b,int* c){
  int indexA=0,indexB=0,indexC=0;
  float temCoef;
  while(indexA!=a && indexB!=b){
    switch (COMPARE(A[indexA].expon,B[indexB].expon))
    {
    case 1://A>B
      C[indexC].coef = B[indexB].coef;
      C[indexC].expon = B[indexB].expon;
      indexB++;
      indexC++;
      break;
    case 0: // A==B
      temCoef = A[indexA].coef + B[indexB].coef;
      if(temCoef){
        C[indexC].coef = temCoef;
        C[indexC].expon = A[indexA].expon;
        indexC++;
      }
      indexB++;
      indexA++;
      break;
    case -1:// A<B
      C[indexC].coef = A[indexA].coef;
      C[indexC].expon = A[indexA].expon;
      indexA++;
      indexC++;
      break;
    }
  }
  while(indexA!=a){
    C[indexC].coef = A[indexA].coef;
    C[indexC].expon = A[indexA].expon;
    indexA++;
    indexC++;
  }
  while(indexB!=b){
    C[indexC].coef = B[indexB].coef;
    C[indexC].expon = B[indexB].expon;
    indexB++;
    indexC++;
  }
  *c = indexC;

}

void Minuspoly(P* A, P* B, P* C,int a, int b,int* c){
  int indexA=0,indexB=0,indexC=0;
  float temCoef;
  while(indexA!=a && indexB!=b){
    switch (COMPARE(A[indexA].expon,B[indexB].expon))
    {
    case 1://A>B
      C[indexC].coef = -B[indexB].coef;
      C[indexC].expon = B[indexB].expon;
      indexB++;
      indexC++;
      break;
    case 0: // A==B
      temCoef = A[indexA].coef - B[indexB].coef;
      if(temCoef){
        C[indexC].coef = temCoef;
        C[indexC].expon = A[indexA].expon;
        indexC++;
      }
      indexB++;
      indexA++;
      break;
    case -1:// A<B
      C[indexC].coef = A[indexA].coef;
      C[indexC].expon = A[indexA].expon;
      indexA++;
      indexC++;
      break;
    }
  }
  while(indexA!=a){
    C[indexC].coef = A[indexA].coef;
    C[indexC].expon = A[indexA].expon;
    indexA++;
    indexC++;
  }
  while(indexB!=b){
    C[indexC].coef = -B[indexB].coef;
    C[indexC].expon = B[indexB].expon;
    indexB++;
    indexC++;
  }
  *c = indexC;

}


int COMPARE(int a, int b){
  if(a>b){
    return 1;
  }
  if(a==b){
    return 0;
  }
  return -1;
}
