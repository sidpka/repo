#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int FindPivot(int* arr,int low,int high){

if(low==high){
return low;
}

if(low>high){
return -1;
}

int mid=(low+high)/2;

if(mid<high && arr[mid]>arr[mid+1]){
return mid;
}

if(mid>low && arr[mid-1]>arr[mid]){

return  mid-1;

}

if(arr[low]>=arr[mid]){
return FindPivot(arr,low,mid-1);
}else{
return FindPivot(arr,mid+1,high);
}


}

int BinarySearch(int* arr,int data,int low,int high){

if(low>high){
return 0;
}

int mid=(low+high)/2;

if(arr[mid]==data){
return 1;
}
if(data<arr[mid]){
return BinarySearch(arr,data,low,mid-1);
}else{
return BinarySearch(arr,data,mid+1,high);
}

}


int FindElm(int* arr,int data,int n){

int pivot=FindPivot(arr,0,n-1);
//printf("\nPivot is : %d",pivot);

if(pivot==-1){
return BinarySearch(arr,data,0,n-1);
}

if(arr[pivot]==data){
return 1;
}

if(data>=arr[0]){
return BinarySearch(arr,data,0,pivot-1);
}else{
return BinarySearch(arr,data,pivot+1,n-1);
}



}


int main(){

printf("\nEnter the number of elements : ");
int n;
scanf("%d",&n);

int* arr=(int*)malloc(sizeof(int)*n);

int i;
printf("\nEnter the elements of the array : \n\n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

int data;
printf("\nEnter the element you want to find : ");
scanf("%d",&data);

int result=FindElm(arr,data,n);

if(result){
printf("\nElement found");
}else{
printf("\nNot found");
}





return 0;
}
