#include<stdio.h>
#include<conio.h>


int SearchFirstIndex(int* arr,int low,int high,int elm){

if(high>=low){

if(arr[low]==elm){
return low;
}

int mid=(low+high)/2;

if(arr[mid]==elm){
if(mid>low && arr[mid-1]<elm){
return mid;
}else if(mid==low){
return mid;
}else if(mid>low && arr[mid-1]==elm){
return SearchFirstIndex(arr,low,mid-1,elm);
}
}else if(arr[mid]>elm){
return SearchFirstIndex(arr,low,mid-1,elm);
}else{
return SearchFirstIndex(arr,mid+1,high,elm);
}
}
}

int SearchLastIndex(int* arr,int low,int high,int elm){

if(high>=low){
if(arr[high]==elm){
return high;
}

int mid=(low+high)/2;

if(arr[mid]==elm){

if(mid<high && arr[mid+1]>elm){
return mid;
}else if(mid<high && arr[mid+1]==elm){
return SearchLastIndex(arr,mid+1,high,elm);
}else if(mid==high){
return mid;
}

}else if(arr[mid]>elm){
return SearchLastIndex(arr,low,mid-1,elm);
}else{
return SearchLastIndex(arr,mid+1,high,elm);
}

}

}

int FindCount(int* arr,int n,int x){
if(x>=arr[0] && x<=arr[n-1]){
int firstIndex=SearchFirstIndex(arr,0,n-1,x);
//printf("\nFirst index of %d is : %d",x,firstIndex);

int lastIndex=SearchLastIndex(arr,0,n-1,x);
//printf("\nLast index of %d is : %d",x,lastIndex);
//getch();
return lastIndex-firstIndex+1;
}
return -1;
}


int main(){

int arr[]={1,2,3,4,4,4,5,6,7,7,7,8};
int n=sizeof(arr)/sizeof(arr[0]);
int x=1;
int count=FindCount(arr,n,x);
if(count!=-1){
printf("\n%d occurs in the array for %d times",x,count);
}else{
printf("\nDoesnot exist");
}

return 0;
}
