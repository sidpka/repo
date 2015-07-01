#include<stdio.h>
#include<conio.h>


int max(int a,int b){

return a>b?a:b;
}


int FindMaxProd(int N){

if(N==1 || N==0){
return 0;
}


int result=0;

int i;

for(i=1;i<N;i++){
result=max(result,max(i*FindMaxProd(N-i),i*(N-i) ) );
}

return result;
}

int FindMaxProd2(int N){

int dp[N+1];

dp[0]=0;
dp[1]=0;

int i;
int j;

for(i=2;i<=N;i++){

int result=0;
for(j=1;j<i;j++){
result=max(result,max(j*(i-j),j*dp[i-j]));
}
dp[i]=result;

}

return dp[N];

}

int main(){

int N=10;

//printf("\nMax product obtained by optimally cutting\n rod of length : %d is : %d",N,FindMaxProd(N));
printf("\nMax product obtained by optimally cutting\n rod of length : %d is : %d",N,FindMaxProd2(N));






return 0;
}
