
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_FILENAME 20

typedef struct{
    int row;
    int col;
    int dir; //0,1,2,3(N,E,S,W)
}element;

typedef struct{
    int row;
    int col;
}location;

enum{
    O = 0, X
};

enum{
    N,E,S,W,NO
};

enum{
    FALSE, TRUE
};

element stack[MAX_STACK_SIZE];
int top = -1;
int** makemaze(FILE*,int*,int*,location*,location*);
void printmaze(int**,int,int);
void pathprintmaze(char **,int ,int);
char** pathmaze(int**,int,int,location,location);
void push(element);
element pop();
int isEmpty();
int isFinish(location,location);
void MAZE(char []);

int main(){

    MAZE("maze1.txt");
    MAZE("maze2.txt");
    MAZE("maze3.txt");
    MAZE("maze4.txt");
        
    return 0;
}
int** makemaze(FILE* file_point, int* row_size, int* col_size, location* start_point, location* finish_point){
    int** maze;
    int tem;
    fscanf(file_point,"%d %d",row_size,col_size);
    maze = (int**)malloc(sizeof(int*)*(*(row_size)+2));
    for(int i=0;i<*row_size+2;i++){
        maze[i] = (int*)malloc(sizeof(int)*((*col_size)+2));
    }
    for(int i=0;i<(*row_size)+2;i++){  
        for(int j= 0;j<(*col_size)+2;j++){
            maze[i][j] = X;
        }
    }
    for(int i =1;i<=(*row_size);i++){
        for(int j=1;j<=(*col_size);j++){
            fscanf(file_point,"%d",&tem);
            if(tem == 0){
                maze[i][j] = O;
            }
        }
    }
    fscanf(file_point,"%d %d %d %d",&start_point->row,&start_point->col,&finish_point->row,&finish_point->col);
    start_point->col++;
    start_point->row++;
    finish_point->col++;
    finish_point->row++;
    return maze;
}
void printmaze(int** maze,int row_size,int col_size){
    for(int i =1;i<=row_size;i++){
        for(int j=1;j<=col_size;j++){
            printf("%3d",maze[i][j]);
        }
        printf("\n");
    }
}
char** pathmaze(int** maze,int row_size,int col_size,location start_point,location finish_point){

    char **MAZE;
    MAZE = (char**)malloc(sizeof(char*)*(row_size+3));
    for(int i=0;i<row_size+3;i++){
        MAZE[i]=(char*)malloc(sizeof(char)*(col_size+3));
    }
    for(int i=0;i<row_size+2;i++){
        for(int j=0;j<col_size+2;j++){
            if(maze[i][j]==X){
                MAZE[i][j] = '1';
            }
            else{
                MAZE[i][j] = '0';
            }
        }
    }
    
    location ary[4]={{-1,0},{0,1},{1,0},{0,-1}};
    element loc={start_point.row,start_point.col,N};
    maze[loc.row][loc.col] = X;
    location next;
    next.row = loc.row + ary[loc.dir].row;
    next.col = loc.col + ary[loc.dir].col;
    MAZE[start_point.row][start_point.col] = 'S';
    MAZE[finish_point.row][finish_point.col] = 'F';
    while(!(isFinish(next,finish_point))){
        
        if(loc.dir >= NO){
            if(isEmpty()==TRUE){
                return MAZE;
            }
            loc = pop();              
            
        }        
        else{
            if(maze[next.row][next.col] == O){
                maze[next.row][next.col] = X;
                loc.dir++;
                push(loc);
                loc.col = next.col;
                loc.row = next.row;
                loc.dir = N;              
            }
            else{
                loc.dir++;
            }
        }
        next.row = loc.row + ary[loc.dir].row;
        next.col = loc.col + ary[loc.dir].col;                      
    }

    push(loc);
    loc.row = finish_point.row;
    loc.col = finish_point.col;
    loc.dir = N;
    push(loc);
    for(int i =1;i<top;i++){
        MAZE[stack[i].row][stack[i].col]='X';
    }

    return MAZE;
}

void pathprintmaze(char** maze,int row_size,int col_size){
    for(int i =1;i<=row_size;i++){
        for(int j=1;j<=col_size;j++){
            printf("%3c",maze[i][j]);
        }
        printf("\n");
    }
}

void push(element item){
    stack[++top]= item;
    
}
element pop(){
    return stack[top--];
}

int isEmpty(){
    if(top<=-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int isFinish(location next,location finish){
    if((next.col==finish.col)&&(next.row==finish.row)){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void MAZE(char filename[]){
    int rowsize,colsize;
    location start,finish;
    int ** maze;
    char **MAZE;
    FILE* fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Cannot find the file\n");
        exit(0);
    }
    maze = makemaze(fp,&rowsize,&colsize,&start,&finish);
    printf("%s\n",filename);
    printmaze(maze,rowsize,colsize);
    MAZE = pathmaze(maze,rowsize,colsize,start,finish);
    printf("\nThe path is:\n");
    pathprintmaze(MAZE,rowsize,colsize);
    fclose(fp);
    printf("\n\n");
    top = -1;
}

