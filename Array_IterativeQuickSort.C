#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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

void IQuickSort(int* arr,int low,int high){
int size=high-low+1;
int* stack=(int*)malloc(sizeof(int)*size);

int top=-1;
stack[++top]=low;
stack[++top]=high;

while(top>=0){
high=stack[top--];
low=stack[top--];
int pivot=Partition(arr,low,high);

if(pivot-1>low){
stack[++top]=low;
stack[++top]=pivot-1;
}

if(pivot+1<high){
stack[++top]=pivot+1;
stack[++top]=high;
}



}


}

int main(){

int arr[]={2,1,6,3,4,0};
int n=sizeof(arr)/sizeof(arr[0]);

IQuickSort(arr,0,n-1);


printf("\nSOrted array :\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}



return 0;
}
