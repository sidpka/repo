#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindSum(char str[],int low,int high){

int sum=0;

int i;

for(i=low;i<=high;i++){
sum+=str[i]-'0';
}


return sum;
}

void FindMaxEvenLenSubstring(char str[]){

int n=strlen(str);

int i;

int sum;
int maxLen=0;
int j;
int mid;
int len;
int start;

for(i=0;i<n;i++){

for(j=i+1;j<n;j+=2){

len=j-i+1;

if(len%2==0){

mid=(i+j)/2;

if(FindSum(str,i,mid)==FindSum(str,mid+1,j)  && (len>maxLen)){
maxLen=len;
start=i;
}

}



}


}

printf("\nMax len : %d\nString : ",maxLen);
for(i=start;i<start+maxLen;i++){
printf("%c",str[i ]);
}

}

void FindMaxEvenLenSubstring_DP(char str[]){

int n=strlen(str);

int dp[n][n];

int i;

for(i=0;i<n;i++){
dp[i][i]=str[i]-'0';
}

int gap;

int j;

for(gap=1;gap<n;gap++){

for(i=0,j=gap;j<n;i++,j++){
dp[i][j]=dp[i][j-1]+dp[j][j];
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

int start;
int maxLen=0;
int mid;

for(i=0;i<n;i++){
for(j=i;j<n;j++){
mid=(i+j)/2;
if((j-i+1)%2==0 && dp[i][mid]==dp[mid+1][j]  && (j-i+1)>maxLen){
maxLen=j-i+1;
start=i;
}
}
}

printf("\nMax Len : %d\nString : ",maxLen);

for(i=start;i<start+maxLen;i++){
printf("%c",str[i]);
}


}

int main(){

char str[]="1538023";

//FindMaxEvenLenSubstring(str);
FindMaxEvenLenSubstring_DP(str);


return 0;
}
