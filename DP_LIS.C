#include<stdio.h>
#include<conio.h>


int FindLIS(int arr[],int n,int* maxRef){


int max=1;

int i;


int res;
//int max=1;

for(i=1;i<n;i++){
res=FindLIS(arr,i,maxRef);

if(arr[i-1]<arr[n-1] && res+1>max){
max=res+1;
}


}

if(max>(*maxRef)){
(*maxRef)=max;
}

return max;



}


int FindLIS_DP(int arr[],int n){

int dp[n];

int i;

for(i=0;i<n;i++){
dp[i]=1;
}

int j;

for(i=1;i<n;i++){
for(j=0;j<i;j++){
if(arr[j]<arr[i] && dp[i]<dp[j]+1){
dp[i]=dp[j]+1;
}
}
}

int max=0;

for(i=0;i<n;i++){
if(max<dp[i]){
max=dp[i];
}
}

return max;


}


int main(){


int arr[]={1,101,2,3,100,4,5};

int n=sizeof(arr)/sizeof(arr[0]);
int max=1;
//printf("\nLongest increasing subsequence : %d",FindLIS(arr,n,&max));
printf("\nLIs : %d",FindLIS_DP(arr,n));



return 0;
}
