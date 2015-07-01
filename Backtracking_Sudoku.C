#include<stdio.h>
#include<conio.h>
#define V 9


void PrintBoard(int buffer[V][V]){

int i;
int j;

for(i=0;i<V;i++){
for(j=0;j<V;j++){
printf("%d  ",buffer[i][j]);
}
printf("\n");
}

}




int IsSafeFix(int buffer[V][V],int x,int y,int val){

int i;

for(i=0;i<V;i++){
if(buffer[x][y]==val){
return 0;
}
}

for(i=0;i<V;i++){
if(buffer[i][y]==val){
return 0;
}
}


return 1;

}

int IsSafePrevFix(int buffer[V][V],int x,int y){

int i;

for(i=0;i<y;i++){
if(buffer[x][i]==buffer[x][y]){
return 0;
}
}

for(i=0;i<x;i++){
if(buffer[i][y]==buffer[x][y]){
return 0;
}
}

return 1;



}


int IsEmptyCell(int buffer[V][V],int* row,int* col){



for((*row)=0;(*row)<V;(*row)++){

for((*col)=0;(*col)<V;(*col)++){

if(buffer[(*row)][(*col)]==0){
return 1;
}


}


}

return 0;

}


int IsSafe(int buffer[V][V],int row,int col,int value){

int i;

for(i=0;i<V;i++){
if(buffer[row][i]==value){
return 0;
}
}

for(i=0;i<V;i++){
if(buffer[i][col]==value){
return 0;
}
}

int j;

int rowStart=row-row%3;
int colStart=col-col%3;

for(i=0;i<3;i++){
for(j=0;j<3;j++){
if(buffer[i+ rowStart][j+colStart]==value){
return 0;
}

}
}


return 1;


}

int FindSudoku_Util(int buffer[V][V]){

int row;
int col;

if(!IsEmptyCell(buffer,&row,&col)){
return 1;
}

int i;


for(i=1;i<=9;i++){
if(IsSafe(buffer,row,col,i)){

buffer[row][col]=i;
if(FindSudoku_Util(buffer)){
return 1;
}else{
buffer[row][col]=0;
}
}


}


return 0;

}



void FindSudoku(int board[V][V]){


int buffer[V][V];

int i;
int j;

for(i=0;i<V;i++){
for(j=0;j<V;j++){

buffer[i][j]=board[i][j];

}
}

if(FindSudoku_Util(buffer)){
PrintBoard(buffer);
}else{
printf("\nThis sudoku cant be solved");
}





}

int main(){

int board[V][V]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};




FindSudoku(board);









return 0;
}
