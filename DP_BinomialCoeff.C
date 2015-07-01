#include<stdio.h>
#include<conio.h>

int FindBinomial(int n,int k){


if(n==k){
return 1;
}

if(k==0){
return 1;
}

return FindBinomial(n-1,k-1)+FindBinomial(n-1,k);
}

int FindBinomial_DP(int n,int k){

int dp[n+1][k+1];

int i;

for(i=0;i<=n;i++){
dp[i][0]=1;
}

for(i=1;i<=k;i++){
dp[0][i]=0;
}

int j;

for(i=1;i<=n;i++){
for(j=1;j<=k;j++){

if(i==j){
dp[i][j]=1;
}else{
dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
}


}
}

return dp[n][k];


}

int main(){


int n=5;
int k=2;

//printf("\nBinomial COeff : %d",FindBinomial(n,k));

printf("\nBinomial COeff : %d",FindBinomial_DP(n,k));




return 0;
}
