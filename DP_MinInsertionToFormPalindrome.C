#include<stdio.h>
#include<conio.h>
#include<string.h>


int min(int a,int b){

return a<b?a:b;
}

int FindInsertion(char X[],int low,int high){

if(low>=high){
return 0;
}


if(X[low]==X[high]){
return FindInsertion(X,low+1,high-1);
}


return min(FindInsertion(X,low+1,high),FindInsertion(X,low,high-1))+1;



}

int FindInsertion2(char X[],int len){

int dp[len][len];



int low;
int high;

for(low=0;low<len;low++){
for(high=0;high<len;high++){

if(low==high){
dp[low][high]=0;
}

}
}

int gap;


for(gap=1;gap<len;gap++){

for(low=0,high=gap;high<len;high++){


if(X[low]==X[high]){
dp[low][high]=dp[low+1][high-1];
}else{
dp[low][high]=min(dp[low+1][high],dp[low][high-1])+1;
}
low++;
}



}


for(low=0;low<len;low++){

for(high=0;high<len;high++){
printf("%d  ",dp[low][high]);
}

printf("\n");

}

getch();


return dp[0][len-1];

}



int main(){


char X[]="abcd";

int len=strlen(X);

printf("\nMinimum insertion required to form palindrome : %d",FindInsertion2(X,len));
//printf("\nMinimum insertion required to form palindrome : %d",FindInsertion(X,0,len-1));








return 0;
}
