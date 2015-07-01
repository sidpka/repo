#include<stdio.h>
#include<conio.h>

int inf=99999;
const int V=3;

int min(int a,int b){

return a<b?a:b;
}

int FindMinCostPath(int arr[V][V],int i,int j,int m,int n){

if(i>m || j>n){
return inf;
}

if(i==m && j==n){

return arr[i][j];
}

return arr[i][j]+ min(FindMinCostPath(arr,i+1,j,m,n),min(FindMinCostPath(arr,i,j+1,m,n),FindMinCostPath(arr,i+1,j+1,m,n)) );

}

int FindMinCostPath_DP(int arr[V][V],int m,int n){

int dp[m+1][n+1];

int i;
int j;



for(i=0;i<=m;i++){

for(j=0;j<=n;j++){

if(i==0 && j==0){
dp[i][j]=arr[i][j];
}
else if(i==0){
dp[i][j]=dp[i][j-1]+arr[i][j];
}else if(j==0){
dp[i][j]=dp[i-1][j]+arr[i][j];
}else{

dp[i][j]=arr[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
}

}

}

/*
for(i=0;i<=m;i++){

for(j=0;j<=n;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");


}

*/

return dp[m][n];



}

int main(){

int arr[V][V]={{1,2,3},{4,8,2},{1,5,3}};

int m=2;
int n=2;

//printf("\nMin cost path : %d",FindMinCostPath(arr,0,0,m,n));

printf("\nMin cost path : %d",FindMinCostPath_DP(arr,m,n));






return 0;
}
