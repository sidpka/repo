#include<stdio.h>
#include<conio.h>


int GetLSeq(int* arr,int n){

int max=0;
int prevMost=-1;
int prev=-1;
int index;

int i;

for(i=0;i<n;i++){
if(arr[i]==0){

if(i-prevMost>max){
max=i-prevMost;
index=prev;
}

prevMost=prev;
prev=i;
}
}


if(n-prevMost>max){
index=prev;
max=n-prevMost;

}


return index;

}

int main(){

int arr[]={1,1,0,0,1,0,1,1,1,0,1,1,1};

int n=sizeof(arr)/sizeof(arr[0]);

int longestContinuousSeqOf1=GetLSeq(arr,n);

printf("\nLongest continuous seq : %d",longestContinuousSeqOf1);






return 0;
}
