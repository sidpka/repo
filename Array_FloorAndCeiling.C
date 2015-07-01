#include<stdio.h>
#include<conio.h>


void FindFC(int* arr,int n,int x){

int i;

int tmpCeil=-1;
int tmpFloor=-1;
for(i=0;i<n;i++){
if(arr[i]>=x){
tmpCeil=arr[i];
}

if(arr[i]<=x && tmpFloor==-1){
tmpFloor=arr[i];
}

}

if(tmpCeil==-1){
printf("\nNo ceil");
}else{
printf("\nCeil : %d",tmpCeil);
}

if(tmpFloor==-1){
printf("\nNo Floor");
}else{
printf("\nFloor : %d",tmpFloor);
}

}


int BinarySearchCeil(int* arr,int low,int high,int x){

if(x>arr[high]){
return -1;
}

if(x<=arr[low]){
return low;
}


int mid=(low+high)/2;


if(arr[mid]==x){
return mid;
}else if(arr[mid]<x){
if(mid<high && arr[mid+1]>=x){
return mid+1;
}else{
return BinarySearchCeil(arr,mid+1,high,x);
}

}else{

if(mid>low && arr[mid-1]<x){
return mid;
}else{
return BinarySearchCeil(arr,low,mid-1,x);
}

}
}

int FindCeil(int* arr,int n,int x){

int index=BinarySearchCeil(arr,0,n-1,x);
//printf("\nIndex is : %d\n",index);

if(index==-1){
return -1;
}else{
return arr[index];
}
}


int BinarySearchFloor(int* arr,int low,int high,int x){

if(x<arr[low]){
return -1;
}

if(x>=arr[high]){
return high;
}


int mid=(low+high)/2;

if(arr[mid]==x){
return mid;
}else if(arr[mid]<x){
if(mid<high && arr[mid+1]>x){
return mid;
}else{
return BinarySearchFloor(arr,mid+1,high,x);
}

}else{

if(mid>low && arr[mid]<=x){
return mid-1;
}else{
return BinarySearchFloor(arr,low,mid-1,x);
}


}
}


int FindFloor(int* arr,int n,int x){


int index=BinarySearchFloor(arr,0,n-1,x);

//printf("\nIndex is : %d",index);

if(index!=-1){
return arr[index];
}

return -1;




}

int main(){

int arr[]={1,2,3,4,6,8};

int n=sizeof(arr)/sizeof(arr[0]);

int x=2;

/*
printf("\nPress enter to find floor and ceiling of %d \n",x);
getch();
FindFC(arr,n,x);
*/

int ceil=FindCeil(arr,n,x);
ceil==-1?printf("\nNo ceil"):printf("\nCeil : %d",ceil);

int floor=FindFloor(arr,n,x);
floor==-1?printf("\nNo floor"):printf("\nFloor : %d",floor);

return 0;
}
