#include<stdio.h>
#include<conio.h>
#define rows 6
#define cols 5

int min(int a,int b){

return a<b?a:b;

}

void FindMaxSizeSquareSubMatrixWithAll1(int mat[rows][cols]){


int buffer[rows][cols];
int i;
int j;
for(i=0;i<cols;i++){
buffer[0][i]=mat[0][i];
}

for(i=0;i<rows;i++){
buffer[i][0]=mat[i][0];
}


int max=1;

for(i=1;i<rows;i++){
for(j=1;j<cols;j++){

if(mat[i][j]){
buffer[i][j]=min(min(buffer[i][j-1],buffer[i-1][j-1]),buffer[i-1][j])+1;
if(max<buffer[i][j]){
max=buffer[i][j];
}
}else{
buffer[i][j]=0;
}




}
}

printf("\nMax : %d",max);


}

int main(){

int mat[rows][cols]={ {0,1,1,0,1},
                      {1,1,0,1,0},
                      {0,1,1,1,0},
                      {1,1,1,1,0},
                      {1,1,1,1,1},
                      {0,0,0,0,0} };



FindMaxSizeSquareSubMatrixWithAll1(mat);





return 0;
}
