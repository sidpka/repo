#include<stdio.h>
#include<conio.h>

int GetPath(int blocks[3][3]){

int i;
int j;

int S[3][3];

for(i=0;i<3;i++){
for(j=0;j<3;j++){
S[i][j]=blocks[i][j];

}

}

for(i=0;i<3;i++){
for(j=0;j<3;j++){
 if(S[i][j]==-1){
 S[i][j]=0;
 continue;
 }
if(i>0 && j>0){
S[i][j]=S[i-1][j]+S[i][j-1];
}else if(i>0 || j>0){
S[i][j]=1;
}else{
S[i][j]=0;
}

}
}


return S[2][2];
}

int main(){


int blocks[3][3]={{0,0,0},{0,-1,0},{0,0,0}};



printf("\nNo of distinct path from src to dest : %d",GetPath(blocks));









return 0;
}
