#include<stdio.h>
#include<conio.h>
#include<string.h>


int max(int a,int b){

return a>b?a:b;
}

int FindLPS(char str[],int low,int high){

if(low>high){
return 0;
}

if(low==high){

return 1;
}


if(str[low]==str[high]){
return max(2+FindLPS(str,low+1,high-1), max(FindLPS(str,low+1,high),FindLPS(str,low,high-1)) );
}

return max(FindLPS(str,low+1,high),FindLPS(str,low,high-1));
}




int FindLPS_DP(char str[],int n){

int dp[n][n];

int i;
int j;

for(i=0;i<n;i++){
dp[i][i]=1;
}

for(i=1;i<n;i++){
if(str[i-1]==str[i]){
dp[i-1][i]=2;
}else{
dp[i-1][i]=1;
}
}


int gap;

for(gap=2;gap<n;gap++){

for(i=0,j=gap;j<n;j++,i++){

if(str[i]==str[j]){
dp[i][j]= 2+dp[i+1][j-1];
}else{
dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
}


}



}

/*
for(i=0;i<n;i++){
for(j=i;j<n;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");
}
*/

return dp[0][n-1];



}


int main(){

char str[]="BBABCBCAB";

int n=strlen(str);

//printf("\nLongest Palindromic Subsequence is of length : %d",FindLPS(str,0,n-1));

printf("\nLongest Palindromic Subsequence is of length : %d",FindLPS_DP(str,n));






return 0;
}
