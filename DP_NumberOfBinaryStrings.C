#include<stdio.h>
#include<conio.h>


int FindCount(int N,int flag){
if(N==0){
return 1;
}

if(N==1){

return flag==0?2:1;

}

int inc=0;
int exc=0;

if(flag==0){
inc=FindCount(N-1,1);
}
exc=FindCount(N-1,0);

return inc+exc;
}



int FindCount2(int N){


int dp[N+1];

dp[0]=1;
dp[1]=2;

int i;

for(i=2;i<=N;i++){
dp[i]=dp[i-1]+dp[i-2];
}

return dp[N];






}


int main(){


int N=0;

//int inc=FindCount(N-1,1);
//int exc=FindCount(N-1,0);
//printf("\nNo of binary string of length : %d without consecutive\n 1 : %d",N,inc+exc);

printf("\nNo of binary string of length : %d without consecutive\n 1 : %d",N,FindCount2(N));





return 0;
}
