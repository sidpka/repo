#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>




void FindSortedSubseq(int* arr,int n){

int* smaller=(int*)malloc(sizeof(int)*n);
int* greater=(int*)malloc(sizeof(int)*n);

int i;


for(i=0;i<n;i++){
smaller[i]=-1;
greater[i]=-1;
}

int min=INT_MAX;
int max=INT_MIN;

min=arr[0];
int minIndex=0;

for(i=1;i<n;i++){
if(arr[i]>min){
smaller[i]=minIndex;
}else{
min=arr[i];
minIndex=i;
}
}

/*
printf("\nMin_____\n\n");


for(i=0;i<n;i++){
printf("%d  ",smaller[i]);
}
*/

max=arr[n-1];
int maxIndex=n-1;

for(i=n-2;i>=0;i--){

if(arr[i]<max){
greater[i]=maxIndex;
}else{
max=arr[i];
maxIndex=i;
}
}

/*

printf("\nMax_____\n\n");

for(i=0;i<n;i++){
printf("%d   ",greater[i]);
}

*/

for(i=0;i<n;i++){

if(smaller[i]!=-1 && greater[i]!=-1){
printf("\nTriplet : %d ,%d ,%d",arr[smaller[i]],arr[i],arr[greater[i]]);
}

}

}


int main(){


    int arr[]={12, 11, 10, 5, 6, 2, 30};

    int n=sizeof(arr)/sizeof(arr[0]);


printf("\nPress enter to find sorted subsequence of size 3 :\n");
FindSortedSubseq(arr,n);






return 0;
}
