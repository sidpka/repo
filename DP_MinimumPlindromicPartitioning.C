#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<limits.h>

int min(int a,int b){

return a<b?a:b;
}

int FindMinCut(char str[],int n){

int dp[n][n];
int cut[n][n];

int i;

for(i=0;i<n;i++){
dp[i][i]=1;
cut[i][i]=0;
}

for(i=1;i<n;i++){
if(str[i-1]==str[i]){
dp[i-1][i]=1;
cut[i-1][i]=0;
}else{
dp[i-1][i]=0;
cut[i-1][i]=1;
}
}

int gap;
int j;
for(gap=2;gap<n;gap++){


for(i=0,j=gap;j<n;j++,i++){

dp[i][j]=(str[i]==str[j] && dp[i+1][j-1]);

if(dp[i][j]){
cut[i][j]=0;
}else{

int k;

cut[i][j]=INT_MAX;

for(k=i;k<j;k++){
cut[i][j]=min(cut[i][j],cut[i][k]+cut[k+1][j]+1);
}


}


}


}


return cut[0][n-1];
}

int main(){

char str[]="ababbbabbababa";

int n=strlen(str);
printf("\nMinimum cuts needed for palindromic partitioning : %d",FindMinCut(str,n));




return 0;
}
