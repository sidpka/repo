#include<stdio.h>
#include<conio.h>

int GetLargestSum(int* arr,int n){

int Sum[n];

if(arr[0]>0){
Sum[0]=arr[0];
}else{
Sum[0]=0;
}

int i;

for(i=1;i<n;i++){
if(Sum[i-1]+arr[i]>0){
Sum[i]=Sum[i-1]+arr[i];
}else{
Sum[i]=0;
}
}

int max=0;

for(i=0;i<n;i++){
if(Sum[i]>max){
max=Sum[i];
}
}

return max;


}

int main(){

int arr[]={-2,11,-4,13,-5,2};

int largestSum=GetLargestSum(arr,sizeof(arr)/sizeof(arr[0]));

printf("\nLargest Sum : %d",largestSum);






return 0;
}
