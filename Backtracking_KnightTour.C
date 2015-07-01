#include<stdio.h>
#include<conio.h>
#define N 8


int IsSafeMove(int buffer[N][N],int row,int col){

if(row>=0 && row<N && col>=0 && col< N && buffer[row][col]==-1){
//printf("\nHere");
return 1;
}
//printf("\nHere");
return 0;

}

int FindKnightTour_Util(int buffer[N][N],int x,int y,int numberOfMoves,int row[N],int col[N]){

if(numberOfMoves==N*N){
return 1;
}

int i;

for(i=0;i<N;i++){

int rowNumber=x+row[i];
int colNumber=y+col[i];
if(IsSafeMove(buffer,rowNumber,colNumber)){
buffer[rowNumber][colNumber]=numberOfMoves;
if(FindKnightTour_Util(buffer,rowNumber,colNumber,numberOfMoves+1,row,col)){
return 1;
}else{
buffer[rowNumber][colNumber]=-1;
}
}
}

return 0;

}


int PrintSolution(int buffer[N][N]){

int i;
int j;

for(i=0;i<N;i++){

for(j=0;j<N;j++){

printf("%d  ",buffer[i][j]);

}

printf("\n");

}

}

int FindKnightTour(){


//int Row[N]={2,2,-2,-2,1,1,-1,-1};
//int Col[N]={1,-1,1,-1,2,-2,2,-2};

int Row[]={ 2, 1, -1, -2, -2, -1,  1,  2 };
int Col[]={1, 2,  2,  1, -1, -2, -2, -1};

int buffer[N][N];

int i;
int j;

for(i=0;i<N;i++){
for(j=0;j<N;j++){
buffer[i][j]=-1;
}
}

buffer[0][0]=0;
int x=0;
int y=0;
int numberOfMoves=1;
//printf("\nHey");
if(FindKnightTour_Util(buffer,x,y,numberOfMoves,Row,Col)){
    //printf("\nHere");

//if(solveKTUtil(0,0,1,buffer,Row,Col)){
PrintSolution(buffer);
}else{
printf("\nNo result");
}

}


int main(){


printf("\nPress enter to see knight's tour \n");
getch();
FindKnightTour();

return 0;
}
