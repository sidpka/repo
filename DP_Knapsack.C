#include<stdio.h>
#include<conio.h>

int max(int a,int b){

return a>b?a:b;
}

int FindKnapsack(int value[],int weight[],int n,int W){
if(n==0 || W==0){
return 0;
}

if(weight[n-1]>W){
return FindKnapsack(value,weight,n-1,W);
}


return max(value[n-1]+FindKnapsack(value,weight,n-1,W-weight[n-1]),FindKnapsack(value,weight,n-1,W));




}

int FindKnapsack_DP(int value[],int weight[],int n,int W){

int dp[W+1][n+1];

int i;

for(i=0;i<=n;i++){

dp[0][i]=0;
}

for(i=1;i<=W;i++){
dp[i][0]=0;
}

int j;

for(i=1;i<=W;i++){
for(j=1;j<=n;j++){

dp[i][j]=dp[i][j-1];

if(weight[j-1]<=i){
dp[i][j]=max(dp[i][j], value[j-1]+dp[i-weight[j-1]][j-1]);
}

}
}


return dp[W][n];
}

int main(){

int value[]={60,100,120};
int weight[]={10,20,30};

int n=sizeof(value)/sizeof(value[0]);

int W=50;

//printf("\nMax Value subset within limit : %d",FindKnapsack(value,weight,n,W));

printf("\nMax Value subset within limit : %d",FindKnapsack_DP(value,weight,n,W));


return 0;
}
