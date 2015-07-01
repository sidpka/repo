#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int LargestSum(int* arr,int n){


int maxSum=0;
int tmpMax=0;

int i;
for(i=0;i<n;i++){
tmpMax=tmpMax+arr[i];
if(tmpMax<0){
tmpMax=0;
}else if(maxSum<tmpMax){
maxSum=tmpMax;
}
}

return maxSum;
}

int max(int a,int b){
return a>b?a:b;
}

int LargestSum_(int* arr,int n){

int i;
int maxSum=arr[0];
int tmpMax=arr[0];

for(i=1;i<n;i++){

tmpMax=max(tmpMax,tmpMax+arr[i]);
maxSum=max(maxSum,tmpMax);
}


return maxSum;

}

int main(){

int n;
printf("\nEnetr the number of elements in the array : ");
scanf("%d",&n);

int* arr=(int*)malloc(sizeof(int)*n);

printf("\nEnter the number of elements in array : ");

int i;

for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

//int largestSum=LargestSum(arr,n);

//if all numbers are negative
int largestSum=LargestSum_(arr,n);

printf("\nLargest sum contiguous sub array : %d",largestSum);
getch();

return 0;
}
