#include<stdio.h>
#include<conio.h>
#include<limits.h>


int min(int a,int b){

return a<b?a:b;
}

int FindMinJump(int arr[],int n){


if(n<=1){
return 0;
}

int result=INT_MAX;

int i;

for(i=n-1;i>=1;i--){

if(arr[i-1]>=(n-i)){

result=min(result,1+FindMinJump(arr,i));
}

}

return result;

}


int FindMinJump_DP(int arr[],int n){

int dp[n];

dp[0]=0;

int i;
int j;

for(i=1;i<n;i++){
dp[i]=INT_MAX;
for(j=i-1;j>=0;j--){
if(arr[j]>=(i-j)){
dp[i]=min(dp[i],dp[j]+1);
}

}

}

/*
for(i=0;i<n;i++){
printf("%d  ",dp[i]);
}
getch();
*/
return dp[n-1];
}


int FindMinJump_DP2(int arr[],int n){

int dp[n];

int i;
int j;
dp[n-1]=0;

for(i=n-2;i>=0;i--){

if(arr[i]>=(n-i-1)){
dp[i]=1;
}else{
dp[i]=INT_MAX;
for(j=1;j<=arr[i] && j<n-1;j++){
dp[i]=min(dp[i],dp[i+j]+1);
}


}


}




return dp[0];
}

int main(){


int arr[]={1,3,5,8,9,2,6,7,6,8,9};
int n=sizeof(arr)/sizeof(arr[0]);

//printf("\nMin Jump : %d",FindMinJump(arr,n));

//printf("\nMin Jump : %d",FindMinJump_DP(arr,n));

printf("\nMin Jump : %d",FindMinJump_DP2(arr,n));



return 0;
}
