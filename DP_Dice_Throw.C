#include<stdio.h>
#include<conio.h>

void  FindCount_Util(int N,int M,int sum,int diceUsed,int currentSum,int* count){


if(diceUsed>=N){
return;
}

int i;

for(i=1;i<=M;i++){
if(currentSum-i==0 && diceUsed+1==N){
(*count)++;
}
FindCount_Util(N,M,sum,diceUsed+1,currentSum-i,count);
}

}

int FindCount(int N,int M,int sum){

int count=0;
int diceUsed=0;
int currentSum=sum;

FindCount_Util(N,M,sum,diceUsed,currentSum,&count);

return count;

}


int FindCount_DP(int N,int M ,int sum){

int dp[N+1][sum+1];

int i;
int j;
int k;

for(i=0;i<=N;i++){
for(j=0;j<=sum;j++){
dp[i][j]=0;
}
}

for(i=1;i<=sum && i<=M;i++){
dp[1][i]=1;
}

for(i=2;i<=N;i++){

for(j=1;j<=sum;j++){


for(k=1;k<=M && k<j;k++){
dp[i][j]+=dp[i-1][j-k];
}



}



}

return dp[N][sum];
}

int main(){


int N=6;
int M=3;
int sum=8;

//printf("\nNo of ways to get sum: %d\nfrom %d dice with %d faces : %d",sum,N,M,FindCount(N,M,sum));
printf("\nNo of ways to get sum: %d\nfrom %d dice with %d faces : %d",sum,N,M,FindCount_DP(N,M,sum));




return 0;
}
