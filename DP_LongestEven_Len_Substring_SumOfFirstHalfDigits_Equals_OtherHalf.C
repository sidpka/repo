#include<stdio.h>
#include<conio.h>
#include<string.h>

int FindMaxLen(char arr[]){
int len=strlen(arr);
//printf("%d",len);

int maxLen=0;

int i;
int j;
int k;
int tmpLen;
int leftSum;
int rightSum;

for(i=0;i<len;i++){

for(j=i+1;j<len;j+=2){

tmpLen=j-i+1;
leftSum=0;
rightSum=0;
for(k=i;k<tmpLen/2;k++){
leftSum+=arr[k]-'0';
rightSum+=arr[k+tmpLen/2]-'0';
}
if( (leftSum==rightSum) && (tmpLen>maxLen) ){
maxLen=tmpLen;
}


}

}
return maxLen;


}


int FindMaxLen2(char arr[]){

int n=strlen(arr);

int sum[n][n];
int i;
int j;
for(i=0;i<n;i++){
sum[i][i]=arr[i]-'0';
}
int maxLen=0;
int len;
int k;
for(len=2;len<=n;len++){

for(i=0;i<n-len+1;i++){

j=i+len-1;
k=len/2;

sum[i][j]=sum[i][j-k]+sum[j-k+1][j];

if(len%2==0 && sum[i][j-k]==sum[j-k+1][j] && len>maxLen){
maxLen=len;
}

}

}


return maxLen;

}

int main(){


char arr[]="1538023";


//int maxLen=FindMaxLen(arr);


//DP
int maxLen=FindMaxLen2(arr);
printf("\nMax even length substring such that sum of first half \ndigits equals sum of second half : %d",maxLen);



return 0;
}
