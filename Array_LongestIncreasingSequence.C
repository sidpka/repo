#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int FindLongestIncreasingSeq(int* arr,int n){

int i;
int j;

int* tmp=(int*)malloc(sizeof(int)*n);

for(i=0;i<n;i++){
tmp[i]=1;
}

for(i=1;i<n;i++){
for(j=0;j<i;j++){
if(arr[i]>arr[j] && tmp[i]<tmp[j]+arr[i]){
tmp[i]=tmp[j]+1;
}
}
}

int max=0;

for(i=0;i<n;i++){
if(tmp[i]>max){
max=tmp[i];
}
}

return max;
}


int main(){

int arr[]={1,2,101,4,100,6,7};

int n=sizeof(arr)/sizeof(arr[0]);

int longestSeq=FindLongestIncreasingSeq(arr,n);
printf("\nMax sum Increasing Subarray is :%d",longestSeq);

return 0;
}
