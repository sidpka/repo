#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindMaxEvenLenString(char str[],int len){

int i;
int j;
int k;
int m;
int leftSum;
int rightSum;
int maxLen=0;
for(i=0;i<len;i++){

for(j=i+1;j<len;j++){

if( (j-i+1)%2==0 ){

leftSum=0;
rightSum=0;
int mid=(i+j)/2;
for(k=i;k<=mid;k++){
leftSum+=str[k]-'0';
}

for(k=mid+1;k<=j;k++){
rightSum+=str[k]-'0';
}

if(leftSum==rightSum){
if(j-i+1 > maxLen){
maxLen=j-i+1;
}
}



}


}





}



return maxLen;

}



int FindMaxEvenLenString2(char sr[],int n){

int sum[n][n];

int i;
int j;
sum[0][0]=sr[0]-'0';
for(i=1;i<n;i++){
sum[0][i]=sum[0][i-1]+sr[i]-'0';
}


for(i=1;i<n;i++){
for(j=i;j<n;j++){
sum[i][j]=sum[i-1][j]-sum[i-1][i-1];
}
}

/*
for(i=0;i<n;i++){
for(j=i;j<n;j++){
printf("%d  ",sum[i][j]);
}
printf("\n");
}
*/

int maxLen=0;
int len;
int mid;

for(i=0;i<n;i++){

for(j=i+1;j<n;j++){
len=j-i+1;
if(len%2==0){

mid=(i+j)/2;

if(sum[i][mid]==sum[mid+1][j]){
if(len>maxLen){
maxLen=len;
}

}


}

}



}



return  maxLen;

}

int main(){

char str[]="1538023";
int n=strlen(str);

//printf("\n%d",n);

//printf("\nSize of  max even length string : %d",FindMaxEvenLenString(str,n));
printf("\nSize of  max even length string : %d",FindMaxEvenLenString2(str,n));



return 0;
}
