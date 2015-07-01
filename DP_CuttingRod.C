#include<stdio.h>
#include<string.h>


int max(int a,int b){

return a>b?a:b;
}

int FindMaxPrice(int arr[],int size,int n){


int i;

int result=arr[size-1];

for(i=size/2;i>=1;i--){
result=max(result,FindMaxPrice(arr,i,n)+FindMaxPrice(arr,size-i,n));
}


return result;
}

int FindMaxPrice_DP(int arr[],int n){


int dp[n+1];

int i;
int j;

for(i=1;i<=n;i++){

dp[i]=arr[i-1];
}

for(i=2;i<=n;i++){


for(j=i/2;j>=1;j--){
dp[i]=max(dp[i],dp[j]+dp[i-j]);
}

}


return dp[n];
}

int main(){

int prices[]={1,5,8,9,10,17,17,20};

int n=8;

//printf("\nMax price obtained by cutting rod : %d",FindMaxPrice(prices,n,n));

printf("\nMax price obtained by cutting rod : %d",FindMaxPrice_DP(prices,n));





return 0;
}
