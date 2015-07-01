#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
void Swap(int* arr,int left,int right){

arr[left]=arr[left]+arr[right];
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

int FindIfConsecutive(int* arr,int n){
QuickSort(arr,0,n-1);
int i;
int tmp=arr[0];
for(i=1;i<n;i++){
if(arr[i]!=arr[i-1]+1){
return 0;
}
}
return 1;
}


int FindIfConsecutive2(int* arr,int n){
int min=INT_MAX;
int max=INT_MIN;

int i;

for(i=0;i<n;i++){
if(arr[i]<min){
min=arr[i];
}
if(arr[i]>max){
max=arr[i];
}
}
//printf("\nMin : %d max : %d",min,max);


if(max-min+1==n){

int* visited=(int*)calloc(n,sizeof(int));
// its for strings --- memset(visited,0,sizeof(int));
for(i=0;i<n;i++){
if(visited[arr[i]-min]){
return 0;
}else{
visited[arr[i]-min]=1;
}
}
return 1;
}else{
return 0;
}



}

int FindIfConsecutive3(int* arr,int n){
int max=INT_MIN;
int min=INT_MAX;

int i;

for(i=0;i<n;i++){
if(arr[i]<min){
min=arr[i];
}

if(arr[i]>max){
max=arr[i];
}

}
int j;
if(max-min+1==n){

for(i=0;i<n;i++){


if(arr[abs(arr[i])-min]>0){
arr[abs(arr[i])-min]=-arr[abs(arr[i])-min];
}else{
return 0;
}
}
/*
if(arr[i]<0){
j=-arr[i]-min;
}else{
j=arr[i]-min;
}

if(arr[j]>0){
arr[j]=-arr[j];
}else{
return 0;
}

}
*/
return 1;
}else{
return 0;
}






}

int main(){

int arr[]={2,1,4,5,3};

int n=sizeof(arr)/sizeof(arr[0]);

/* O(nlogn)
int result=FindIfConsecutive(arr,n);

*/

/*O(n) Space
int result=FindIfConsecutive2(arr,n);
*/

//O(n) time but O(1) space

int result=FindIfConsecutive3(arr,n);

if(result){
printf("\nYes\n Arrat contains consecutive elements");
}else{
printf("\nNo\n Array doesnot contain consecutive el");
}




return 0;
}
