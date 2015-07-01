#include<stdio.h>
#include<conio.h>


int FindLongestBitonic(int a[],int n){

int leftLIS[n];
int rightLIS[n];

int i;

for(i=0;i<n;i++){
leftLIS[i]=1;
rightLIS[i]=1;
}

int j;

for(i=1;i<n;i++){

for(j=0;j<i;j++){
if(a[i]>a[j] && leftLIS[i]<leftLIS[j]+1){
leftLIS[i]=leftLIS[j]+1;
}
}

}

/*

for(i=0;i<n;i++){
printf("%d  ",leftLIS[i]);
}

*/

for(i=n-2;i>=0;i--){
for(j=n-1;j>i;j--){
if(a[i]>a[j] && rightLIS[i]<rightLIS[j]+1){
rightLIS[i]=rightLIS[j]+1;
}

}
}

/*
for(i=0;i<n;i++){
printf("%d  ",rightLIS[i]);
}
*/

int max=2;

for(i=0;i<n;i++){

if(max<leftLIS[i]+rightLIS[i]-1){
max=leftLIS[i]+rightLIS[i]-1;
}
}

return max;

}

int main(){

int arr[]={1,11,2,10,4,5,2,1};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nLength of longest bitonic subsequence : %d",FindLongestBitonic(arr,n));






return 0;
}
