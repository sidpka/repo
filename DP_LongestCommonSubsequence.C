#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<limits.h>

int max(int a,int b){

return a>b?a:b;
}

int FindLCS(char a[],int a_low,int n,char b[],int b_low,int m){

if(a_low>=n || b_low>=m){

return 0;
}


int i;
int j;

if(a[a_low]==b[b_low]){

return max(1+FindLCS(a,a_low+1,n,b,b_low+1,m), max( FindLCS(a,a_low+1,n,b,b_low,m),FindLCS(a,a_low,n,b,b_low+1,m) ) );
}

return max( FindLCS(a,a_low+1,n,b,b_low,m),FindLCS(a,a_low,n,b,b_low+1,m) );

}

int FindLCS2(char a[],int n,char b[],int m){

if(n<=0 || m<=0){

return 0;
}

if(a[n-1]==b[m-1]){
return max(1+FindLCS2(a,n-1,b,m-1),max(FindLCS2(a,n-1,b,m),FindLCS2(a,n,b,m-1)) );
}

return max(FindLCS2(a,n-1,b,m),FindLCS2(a,n,b,m-1));


}


int FindLCS_DP(char a[],int n,char b[],int m){


int dp[n+1][m+1];

int i;

for(i=0;i<=n;i++){
dp[i][0]=0;
}

for(i=1;i<=m;i++){
dp[0][i]=0;
}

int j;

for(i=1;i<=n;i++){
for(j=1;j<=m;j++){

if(a[i-1]==b[j-1]){

dp[i][j]=dp[i-1][j-1]+1;

}else{
dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
}

}
}


return dp[n][m];

}

int main(){


char a[]="ABCDGH";
char b[]="AEDFHR";

int n=strlen(a);
int m=strlen(b);

//printf("\nLongest Common Subsequence : %d",FindLCS(a,0,n,b,0,m));

//printf("\nLongest Common Subsequence : %d",FindLCS2(a,n,b,m));

printf("\nLongest Common Subsequence : %d",FindLCS_DP(a,n,b,m));


return 0;
}
