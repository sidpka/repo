#include<stdio.h>
#include<conio.h>


int FindCatalan(int N){

if(N<=1){
return 1;
}

int result=0;

int i;

for(i=0;i<N;i++){
result+=FindCatalan(i)*FindCatalan(N-i-1);
}

return result;


}

int FindCatalan2(int N){

int dp[N+1];

dp[0]=1;
dp[1]=1;

//int result=0;
int i;


int n;
for(n=2;n<=N;n++){
dp[n]=0;
for(i=0;i<n;i++){
dp[n]+=dp[i]*dp[n-i-1];
}

}
return dp[N];




}

int main(){


int N=4;

//printf("\nCatalan Number for N : %d is : %d",N,FindCatalan(N));
printf("\nCatalan Number for N : %d is : %d",N,FindCatalan2(N));






return 0;
}
