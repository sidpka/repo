#include<stdio.h>
#include<conio.h>
#include<limits.h>




int FindLLAP(int arr[],int n){

int i;
int j;
int k;

int maxLen=0;
int d;
int currentLength=0;
int lastElm;
for(i=0;i<n;i++){

for(j=i+1;j<n;j++){
d=arr[j]-arr[i];
currentLength=2;
lastElm=arr[j];
for(k=j+1;k<n;k++){

if(arr[k]-lastElm==d){
currentLength++;
lastElm=arr[k];
}else if(arr[k]-lastElm>d){
break;
}

}
if(currentLength>maxLen){
maxLen=currentLength;
}
}

}

return maxLen;
}


int FindLLAP_DP(int arr[],int n){

int i;
int min=INT_MAX;
int max=INT_MIN;

for(i=0;i<n;i++){
if(arr[i]<min){
min=arr[i];
}
if(arr[i]>max){
max=arr[i];
}
}

int dp[max-min+1];

int j;

for(i=0;i<=(max-min);i++){
dp[i]=0;
}

for(i=0;i<n;i++){
for(j=i+1;j<n;j++){

dp[arr[j]-arr[i]]++;

}
}

//max=0;

int maxElm=0;

for(i=0;i<=(max-min);i++){
if(dp[i]>maxElm){
maxElm=dp[i];
}
}

return maxElm+1;

}

int max(int a,int b){
return a>b?a:b;
}

int FindLLAP2(int arr[],int n){

int dp[n][n];

int i;

for(i=0;i<n;i++){
dp[i][n-1]=2;
}

int j;
int k;
int llap=2;
for(j=n-1;j>=1;j--){


i=j-1;
k=j+1;

while(i>=0 && k<=n-1){

if(arr[i]+arr[k]>2*arr[j]){

dp[i][j]=2;
i--;

}else if(arr[i]+arr[k]<2*arr[j]){
k++;
}else{
dp[i][j]=dp[j][k]+1;
llap=max(llap,dp[i][j]);
i--;
k++;
}



}
while(i>=0){
dp[i][j]=2;
i--;
}






}




return llap;

}

int main(){

int arr[]={1,7,10,15,27,29};
//int arr[]={5, 10, 15, 20, 25, 30};
int n=sizeof(arr)/sizeof(arr[0]);

//printf("\nLength of LLAP : %d",FindLLAP(arr,n));
//printf("\nLength of LLAP : %d",FindLLAP_DP(arr,n));

printf("\nLength of LLAP : %d",FindLLAP2(arr,n));




return 0;
}
