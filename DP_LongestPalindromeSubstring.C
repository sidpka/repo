#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindLongestPalindrome(char str[],int n){


int i;
int left;
int right;

int maxLen=1;
int tmpRight;
for(i=0;i<n;i++){

right=i+1;

while(right<n){

left=i;
tmpRight=right;
while(left<=tmpRight){

if(str[left]!=str[tmpRight]){
break;
}
left++;
tmpRight--;

}

if(left>=tmpRight && maxLen<(right-i+1) ){
maxLen=right-i+1;
}
right++;


}




}





return maxLen;

}


int max(int a,int b){

return a>b?a:b;
}


int FindLongestPalindrome_DP(char str[],int n){


int dp[n][n];
int i;
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
dp[i][j]=0;
}
}

for(i=0;i<n;i++){
dp[i][i]=1;
}

int maxLen;
int startIndex;
for(i=0;i<n-1;i++){
if(str[i]==str[i+1]){
dp[i][i+1]=1;
startIndex=i;
maxLen=2;
}
}

int gap;


for(gap=2;gap<n;gap++){

for(i=0,j=gap;j<n;j++,i++){


if(dp[i+1][j-1] && str[i]==str[j]){
dp[i][j]=1;
if(j-i+1>maxLen){
maxLen=j-i+1;
startIndex=i;
}
}




}


}

printf("\nLongest Panlindrome is : \n");

for(i=startIndex;i<startIndex+maxLen;i++){
printf("%c",str[i]);
}

return maxLen;
}

int main(){


char str[]="abaaba";
int n=strlen(str);

//printf("\nLongestPalindromic Substring : %d",FindLongestPalindrome(str,n));
printf("\nLongestPalindromic Substring : %d",FindLongestPalindrome_DP(str,n));





return 0;
}
