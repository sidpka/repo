#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

int FindMinDistance(int* arr,int n,int x,int y){

int indexX=-1;
int indexY=-1;

int minDistance=INT_MAX;

int i;

for(i=0;i<n;i++){
if(indexX==-1 && arr[i]==x){
indexX=i;
if(indexY!=-1){
minDistance=abs(indexX-indexY);
}
}else if(arr[i]==x){
if(abs(i-indexY)<minDistance){
indexX=i;
minDistance=abs(i-indexY);
}
}


if(indexY==-1 && arr[i]==y){
indexY=i;
if(indexX!=-1){
minDistance=abs(indexX-indexY);
}
}else if(arr[i]==y){
if(abs(i-indexX)<minDistance){
indexY=i;
minDistance=abs(indexX-i);
}
}
}
return abs(indexX-indexY);
}

int main(){

int arr[]={2,1,4,2,4,9,7};

int n=sizeof(arr)/sizeof(arr[0]);

int x=2;
int y=4;

//O(n)
int minDistance=FindMinDistance(arr,n,x,y);

printf("\nMinimum distance between %d and %d is : %d",x,y,minDistance);


return 0;
}
