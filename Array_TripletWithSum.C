#include<stdio.h>
#include<conio.h>

void Swap(int* arr,int left,int right){

arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];

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

void QuickSort(int* arr,int low,int high){

if(high>low){
int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);
}
}

int FindTripletSums(int* arr,int n,int sum){

QuickSort(arr,0,n-1);

int i;
/*
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
*/

int left;
int right;

for(i=0;i<n-2;i++){
left=i+1;
right=n-1;
while(left<right){
if(sum==arr[i]+arr[left]+arr[right]){
return 1;
}else if(sum< arr[i]+arr[left]+arr[right]){
right--;
}
else{
left++;
}
}
}
return 0;
}

int main(){


int arr[]={2,1,4,6,8,3};

int n=sizeof(arr)/sizeof(arr[0]);

int sum=14;

int result=FindTripletSums(arr,n,sum);

if(result){
printf("\nYes exists");
}else{
printf("\nDoesn't exist");
}

return 0;
}
