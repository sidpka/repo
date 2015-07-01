#include<stdio.h>
#include<conio.h>

int BS(int* arr,int low,int high){

if(low==high){
return low;
}

if(high==low+1){
if(arr[low]>arr[high]){
return low;
}else if(arr[high]>arr[low]){
return high;
}
}

int mid=(low+high)/2;

if(arr[mid+1] < arr[mid] && arr[mid]>arr[mid-1]){
return mid;
}

if(arr[mid+1]<arr[mid] && arr[mid]<arr[mid-1]){
return BS(arr,low,mid-1);
}

if(arr[mid+1]>arr[mid] && arr[mid]>arr[mid-1]){
return BS(arr,mid+1,high);
}

}

int FindMaxElm(int* arr,int n){

int index=BS(arr,0,n-1);
//printf("\n\nIndex : %d",index);
return arr[index];


}



int main(){

int arr[]={4,78,90,45,32};
int n=sizeof(arr)/sizeof(arr[0]);

int max=FindMaxElm(arr,n);

printf("\nMax Element in array : %d",max);




return 0;
}
