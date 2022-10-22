#include <stdio.h>

#define FILENAME 20

enum{
    False, True
};

void FILESTART(char *filename);
void printQ(int* Q,int rear, int front,int size);
int isFull(int rear, int front,int size);
int isEmpty(int rear, int front);
void addQ(int *Q, int *rear,int element,int size);
int deQ(int *Q, int* front,int size);
int main(){
    char file[FILENAME];
    while(1){
        printf("FILENAME( if you input \"exit\", program EXIT ) >>  ");
        scanf("%s",file);
        if(!strcmp(file,"exit")){
            break;
        }
        printf("[%s]\n",file);
        FILESTART(file);
        printf("\n\n");
    }
    
}

void FILESTART(char *filename){
    int size, rear = 0, front =0,num;
    FILE* fp = fopen(filename,"r");
    if(!fp){
        printf("--Cannot find the File--\n");
        exit(0);
    }
    int* queue;
    char buf;

    fscanf(fp,"%d",&size);
    queue = (int*)malloc(sizeof(int)*size);
    printf("Queue size: %d\n",size);
    while(!feof(fp)){
        fscanf(fp,"%c",&buf);
        fscanf(fp,"%c",&buf);
        if(buf == 'a'){
            fscanf(fp,"%d",&num);
            if(isFull(rear,front,size)){
                printf("queue full: cannot add\n");
                break;
            }
            addQ(queue,&rear,num,size);
            printQ(queue,rear,front,size);
        }
        else{
            if(isEmpty(rear,front)){
                printf("queue empty: cannot delete\n");
                free(queue);
                fclose(fp);
                return;
            }
            deQ(queue,&front,size);
            if(isEmpty(rear,front)){
                printf("Circular queue is empty\n");
            }
            else{
                printQ(queue,rear,front,size);
            }
        }
    }
    free(queue);
    fclose(fp);
}
void printQ(int* Q,int rear, int front,int size){
    printf("Circular queue: ");
    for(int i = (front+1)%size; i != rear; i = (i+1)%size){
        printf("%d ",Q[i]);
    }
    printf("%d",Q[rear]);
    printf("\n");
}
int isFull(int rear, int front,int size){
    if((rear+1)%size == front){
        return True;
    }
    return False;
}
int isEmpty(int rear, int front){
    if(rear == front){
        return True;
    }
    return False;
}
void addQ(int *Q, int *rear,int element,int size){
    *rear = (*rear+1)%size;
    Q[*rear] = element;
}
int deQ(int* Q, int* front,int size){
    *front = (*front+1)%size;
    return Q[*front];
}