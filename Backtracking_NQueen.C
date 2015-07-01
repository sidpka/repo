#include<stdio.h>
#include<conio.h>

#define N 4

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

int IsValidPlacement(int buffer[N][N],int x,int y){



int i;

for(i=0;i<y;i++){
if(buffer[x][i]==1){
return 0;
}
}



int j;

for(i=x,j=y;i<N && j>=0 ;i++,j--){
if(buffer[i][j]==1){
return 0;
}
}

for(i=x,j=y;i>=0 && j>=0 ;i--,j--){
if(buffer[i][j]==1){
return 0;
}
}


return 1;

}

int FindNQueen_Util(int buffer[N][N],int col){

if(col>=N){
return 1;
}


int i;


for(i=0;i<N;i++){

if(IsValidPlacement(buffer,i,col)){
buffer[i][col]=1;
if(FindNQueen_Util(buffer,col+1)){
return 1;
}else{
buffer[i][col]=0;
}


}

}






return 0;

}


void FindNQueen(){


int buffer[N][N];

int i;
int j;

for(i=0;i<N;i++){
for(j=0;j<N;j++){
buffer[i][j]=0;
}
}

if(FindNQueen_Util(buffer,0)){
PrintSolution(buffer);
}else{
printf("\nNo solution");
}

}


int main(){


printf("\nPress enter to see N Queen positioning\n\n");
getch();

FindNQueen();







return 0;
}
