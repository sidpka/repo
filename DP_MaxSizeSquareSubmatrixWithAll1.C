#include<stdio.h>
#include<conio.h>
#define R 6
#define C 5


int min(int a,int b){

return a<b?a:b;
}


int FindMaxSquareSubmatrix(int arr[R][C]){


int dp[R][C];

int i;
int j;

int max=1;

for(i=0;i<R;i++){
dp[i][0]=arr[i][0];
}


for(i=1;i<C;i++){
dp[0][i]=arr[0][i];
}

for(i=1;i<R;i++){
for(j=1;j<C;j++){
if(arr[i][j]==1){
dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;

if(dp[i][j]>max){
max=dp[i][j];
}

}else{
dp[i][j]=0;
}
}
}




return max;

}


int main(){

int arr[R][C]= {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};




printf("\nMax size square submatrix with all 1 : %d",FindMaxSquareSubmatrix(arr));







return 0;
}
