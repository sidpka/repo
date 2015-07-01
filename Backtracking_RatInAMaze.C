#include<stdio.h>
#include<conio.h>
#define N 4


int IsSafeMove(int buffer[N][N],int x,int y){

if(x>=0 && x<N && y>=0 && y<N && buffer[x][y]==0){
return 1;
}else{
return 0;
}


}

int FindMazePath_Util(int buffer[N][N],int x,int y,int move){


if(x==N-1 && y==N-1){
return 1;
}

if(IsSafeMove(buffer,x,y+1)){
buffer[x][y+1]=move;
if(FindMazePath_Util(buffer,x,y+1,move+1)){
return 1;
}else{
buffer[x][y+1]=0;
}
}

if(IsSafeMove(buffer,x+1,y)){
buffer[x+1][y]=move;
if(FindMazePath_Util(buffer,x+1,y,move+1)){
return 1;
}else{
buffer[x+1][y]=0;
}
}

return 0;

}

void PrintSolution(int buffer[N][N]){

int i;
int j;

for(i=0;i<N;i++){
for(j=0;j<N;j++){
printf("%d  ",buffer[i][j]);
}
printf("\n");
}


}

void FindMazePath(int maze[N][N]){


int buffer[N][N];

int i;
int j;

for(i=0;i<N;i++){

for(j=0;j<N;j++){
buffer[i][j]=maze[i][j]==0?-1:0;
}

}
buffer[0][0]=1;
if(FindMazePath_Util(buffer,0,0,2)){
PrintSolution(buffer);
}else{
printf("\No solution");
}
}


int main(){


int maze[N][N]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};

FindMazePath(maze);

return 0;
}
