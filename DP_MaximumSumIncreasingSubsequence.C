#include<stdio.h>
#include<conio.h>


int FindMSIS(int arr[],int n){


int dp[n];

int i;
for(i=0;i<n;i++){
dp[i]=0;
}

int j;

dp[0]=arr[0];

for(i=1;i<n;i++){


for(j=0;j<i;j++){
if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i]){
dp[i]=dp[j]+arr[i];
}
}
}

/*
for(i=0;i<n;i++){
printf("%d  ",dp[i]);
}
*/

int max=0;

for(i=0;i<n;i++){
if(dp[i]>max){
max=dp[i];
}
}

return max;


}

int main(){

int arr[]={1,101,2,3,100,4,5};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nMaximum sum increasing subsequence : %d",FindMSIS(arr,n));



return 0;
}
