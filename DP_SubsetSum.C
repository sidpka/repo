#include<stdio.h>
#include<conio.h>


int FindSubsetSum(int arr[],int sum,int n){

if((sum>0 && n==0) || sum<0 ){
return 0;
}

if(sum==0){
return 1;
}

return FindSubsetSum(arr,sum,n-1)||FindSubsetSum(arr,sum-arr[n-1],n-1);

}


int FindSubsetSum_DP(int arr[],int sum,int n){

int dp[sum+1][n+1];
int i;

for(i=0;i<=n;i++){
dp[0][i]=1;
}

for(i=1;i<=sum;i++){
dp[i][0]=0;
}




int j;


for(i=1;i<=sum;i++){

for(j=1;j<=n;j++){
dp[i][j]=0;
if(arr[j-1]<=i && dp[i-arr[j-1]][j-1]){
dp[i][j]=1;
}

if(dp[i][j-1]){
dp[i][j]=1;
}


}


}



/*
for(i=0;i<=sum;i++){

for(j=0;j<=n;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");
}




getch();
*/

return dp[sum][n];


}


int main(){


int arr[]={3,34,4,12,5,2};

int n=sizeof(arr)/sizeof(arr[0]);

int sum=9;

//int result=FindSubsetSum(arr,sum,n);
int result=FindSubsetSum_DP(arr,sum,n);
if(result==1){
printf("\nYes exists");
}else{
printf("\nNo doesn't exist");
}








return 0;
}
