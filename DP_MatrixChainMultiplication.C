#include<stdio.h>
#include<conio.h>
#include<limits.h>

int FindMinCost(int arr[],int i,int j){


if(i==j){
return 0;
}

int k;

int min=INT_MAX;
int result;

for(k=i;k<j;k++){
result=FindMinCost(arr,i,k)+FindMinCost(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
if(min>result){
min=result;
}
}

return result;


}

int  min(int a,int b){

return a<b?a:b;
}
int FindMinCost_DP(int arr[],int n){

int dp[n][n];

int i;

for(i=1;i<n;i++){
dp[i][i]=0;
}

int j;

int k;

int gap;

for(gap=2;gap<n;gap++){

for(i=1,j=gap;j<n;i++,j++){

dp[i][j]=INT_MAX;

for(k=i;k<j;k++){
dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]  );
}


}




}



return dp[1][n-1];
}

int main(){


int arr[]={1,2,3,4,3};

int n=sizeof(arr)/sizeof(arr[0]);

//printf("\nMin cost of multiplication : %d",FindMinCost(arr,1,n-1));

printf("\nMin cost of multiplication : %d",FindMinCost_DP(arr,n));

return 0;
}
