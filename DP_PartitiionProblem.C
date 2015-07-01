#include<stdio.h>
#include<conio.h>



int FindExistence_Util(int arr[],int low,int high,int sum){
if(sum==0){
return 1;
}
if(low>high && sum!=0){
return 0;
}

return FindExistence_Util(arr,low+1,high,sum-arr[low])||FindExistence_Util(arr,low+1,high,sum);

}


int FindExistence(int arr[],int low,int high){


int sum=0;

int i;

for(i=low;i<=high;i++){
sum+=arr[i];
}
//printf("\nSum is : %d",sum);
if(sum&1){
return 0;
}

return FindExistence_Util(arr,low,high,sum/2);


}


int FindExistence_DP(int *arr,int n){


int sum=0;
int i;
for(i=0;i<n;i++){
sum+=arr[i];

}
if(sum&1){
return 0;
}

int dp[sum/2 +1][n+1];


for(i=0;i<n+1;i++){
dp[0][i]=1;
}

for(i=1;i<=sum/2;i++){
dp[i][0]=0;
}

int j;


for(i=1;i<=sum/2;i++){

for(j=1;j<=n;j++){

dp[i][j]=dp[i][j-1];

if(dp[i][j]!=1 && arr[j-1]<=i){
dp[i][j]=dp[i-arr[j-1]][j-1];
}


}

}


return dp[sum/2][n];
}


int main(){


int arr[]={1,5,11,5};

int n=sizeof(arr)/sizeof(arr[0]);



//int result=FindExistence(arr,0,n-1);

int result=FindExistence_DP(arr,n);

result==1?printf("\nYes"):printf("\No");


return 0;
}
