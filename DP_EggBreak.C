#include<stdio.h>
#include<conio.h>
#include<limits.h>

int max(int a,int b){

return a>b?a:b;
}

int FindMinTrials(int n,int k){


if(k==1||k==0){

return k;
}

if(n==1){

return k;
}

int min=INT_MAX;

int i;
int res;
for(i=1;i<=k;i++){
res=max(FindMinTrials(n-1,i-1),FindMinTrials(n,k-i));
if(res<min){
min=res;
}
}

return min+1;
}


int FindMinTrials_DP(int n,int k){


int dp[n+1][k+1];
int i;
for(i=1;i<=k;i++){
dp[1][i]=i;
}

for(i=0;i<=n;i++){
dp[i][1]=1;
dp[i][0]=0;
}

int j;
int x;

for(i=2;i<=n;i++){

for(j=2;j<=k;j++){

dp[i][j]=INT_MAX;
int res;
for(x=1;x<j;x++){
res=max(dp[i-1][x-1],dp[i][j-x])+1;
if(res<dp[i][j]){
dp[i][j]=res;
}
}


}

}

for(i=1;i<=n;i++){

for(j=1;j<=k;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");

}


return dp[n][k];

}


int main(){

int n=2;
int k=36;

//printf("\nMinimum number of trials needed : %d",FindMinTrials(n,k));

printf("\nMinimum number of trials needed : %d",FindMinTrials_DP(n,k));



return 0;
}
