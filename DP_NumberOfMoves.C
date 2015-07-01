#include<stdio.h>
#include<conio.h>



int GetNoOfMoves(int size,int startX,int startY,int endX,int endY,int noOfMoves){

int row[]={0,0,-1,-1,-1,-1,-1,-2,-2,1,1,1,1,1,2,2};
int col[]={1,-1,0,1,2,-1,-2,1,-1,0,1,2,-1,-2,1,-1};

int i;
int j;
int k;
int S[size][size][noOfMoves+1];

for(i=0;i<size;i++){
for(j=0;j<size;j++){
  for(k=0;k<=noOfMoves;k++){
  S[i][j][k]=0;
  }

}
}

//int k=0;
S[startX][startY][0]=1;
int n;

for(n=1;n<=noOfMoves;n++){

for(i=0;i<size;i++){
for(j=0;j<size;j++){

   for(k=0;k<16;k++){
   if(row[k]+i<size && row[k]+i>=0  && col[k]+j<size && col[k]+j>=0){
   S[row[k]+i][col[k]+j][n]+=S[i][j][n-1];
   }

   }




}
}
}



return S[endX][endY][noOfMoves];

}

int main(){

int size=3;
int startX=0;
int startY=0;
int endX=0;
int endY=0;
int noOfMoves =2;


printf("\nNo of ways to go from start to end : %d",GetNoOfMoves(size,startX,startY,endX,endY,noOfMoves));






return 0;
}
