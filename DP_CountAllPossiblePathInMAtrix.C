#include<stdio.h>
#include<conio.h>

#define rows 3
#define cols 3

int FindCount(int i,int j){

if(i>=rows || j>=cols){
return 0;
}

if(i==rows-1 && j==cols-1){
return 1;
}

return FindCount(i+1,j)+FindCount(i,j+1);



}


int FindCount_DP(){

int dp[rows][cols];

int i;
int j;

for(i=0;i<rows;i++){
dp[i][0]=1;
}

for(j=0;j<cols;j++){
dp[0][j]=1;
}

for(i=1;i<rows;i++){
for(j=1;j<cols;j++){
dp[i][j]=dp[i-1][j]+dp[i][j-1];
}
}

return dp[rows-1][cols-1];


}

void PrintAllPath(int buffer[],int i,int j,int index){
if(i==rows-1){
int k;

for(k=j;k<cols;k++){
buffer[(index)++]=i*cols+k;
}
for(k=0;k<(index);k++){
printf("%d  ",buffer[k]);
}
printf("\n");
return;
}

if(j==cols-1){
int k;

for(k=i;k<rows;k++){
buffer[(index)++]=k*cols+j;
}

for(k=0;k<(index);k++){
printf("%d  ",buffer[k]);
}

printf("\n");
return;
}

buffer[(index)++]=i*cols+j;

PrintAllPath(buffer,i+1,j,index);
PrintAllPath(buffer,i,j+1,index);

}

int main(){

//printf("\nAll possible Path in a matrix[%d][%d] : %d",rows,cols,FindCount(0,0));
printf("\nAll possible Path in a matrix[%d][%d] : %d",rows,cols,FindCount_DP());

printf("\nPress enter to print all paths : \n");
getch();
int buffer[rows+cols];
int index=0;
PrintAllPath(buffer,0,0,index);



return 0;
}
