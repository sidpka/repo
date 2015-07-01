#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void Swap(int* arr,int low,int high){

arr[low]+=arr[high];
arr[high]=arr[low]-arr[high];
arr[low]-=arr[high];

}


int Partition(int* arr,int low,int high){

int pivotElm=arr[low];
int left=low;
int right=high;

while(left<right){

while(arr[left]<=pivotElm){
left++;
}

while(arr[right]>pivotElm){
right--;
}

if(left<right){
Swap(arr,left,right);
}

}

arr[low]=arr[right];
arr[right]=pivotElm;
return right;

}

void QuickSort(int* arr,int left,int right){
if(right>left){
int pivot=Partition(arr,left,right);
QuickSort(arr,left,pivot-1);
QuickSort(arr,pivot+1,right);
}
}


void FindRM(int* arr,int n){

QuickSort(arr,0,n-1);

int i;

/*
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
*/

int x=0;

for(i=0;i<n;i++){
if(arr[abs(arr[i])]>=0){
    x=x^abs(arr[i]);
    //printf("\nEntering for : %d\n",i);
arr[abs(arr[i])]=-arr[abs(arr[i])];
}else{
printf("\nRepeated : %d",abs(arr[i]));
}
}
for(i=1;i<=n;i++){
x=x^i;
}
printf("\nMissing : %d",x);
}

int main(){

int arr[]={1,2,4,3,2};

int n=sizeof(arr)/sizeof(arr[0]);

FindRM(arr,n);

return 0;
}
