#include<stdio.h>
#include<conio.h>


void FindAllGroupWithSum(int* arr,int n,int sum){

int i;
int j;
int l;
int r;

int tmpSum;

for(i=0;i<n-3;i++){
for(j=i+1;j<n-2;j++){

l=j+1;
r=n-1;

while(l<r){
tmpSum=arr[i]+arr[j]+arr[l]+arr[r];

if(tmpSum==sum){
printf("\n%d  %d  %d  %d",arr[i],arr[j],arr[l],arr[r]);
l++;
r--;
}else if(tmpSum<sum){
l++;
}else{
r--;
}
}
}
}
}



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


int main(){

int arr[]={10,2,3,4,5,9,7,8};

int n=sizeof(arr)/sizeof(arr[0]);

int sum=23;
QuickSort(arr,0,n-1);
/*
int i;
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
*/
//O(n^3) time complexity
FindAllGroupWithSum(arr,n,sum);

return 0;
}
