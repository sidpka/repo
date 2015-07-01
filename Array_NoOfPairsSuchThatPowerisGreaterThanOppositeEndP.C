#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

void FindPair(int* arr1,int n,int* arr2,int m){

int i;
int j;

int count=0;

for(i=0;i<n;i++){

for(j=0;j<m;j++){
if((int)pow(arr1[i],arr2[j])>(int)pow(arr2[j],arr1[i]) ){
count++;
}
}

}
printf("%d",count);


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


int FindCeil(int* arr,int low,int high,int key){

if(arr[low]>key){
return low;
}
if(arr[high]<key){
return -1;
}

int mid=(low+high)/2;

if((mid==0 || arr[mid-1]<=key)&& (mid==high || arr[mid]>key) ){
return mid;
}

if(mid-1>=low && arr[mid-1]>key){
return FindCeil(arr,low,mid-1,key);
}else{
return FindCeil(arr,mid+1,high,key);
}



}

int FindCount(int key,int* Y,int m,int* YCountHelper){

if(key==0){
return 0;
}


if(key==1){

return YCountHelper[0];

}

int ceilIndex=FindCeil(Y,0,m-1,key);
if(ceilIndex==-1){
ceilIndex=m;
}
int count=m-ceilIndex;

count+=YCountHelper[0]+YCountHelper[1];

if(key==2){
count-=(YCountHelper[3]+YCountHelper[4]);
}

if(key==3){
count+=YCountHelper[2];
}


return count;
}



int FindPair2(int* X,int n,int* Y ,int m){

int YCountHelper[5];

int j;

for(j=0;j<5;j++){
YCountHelper[j]=0;
}

int i;

for(i=0;i<m;i++){
if(Y[i]<5){
YCountHelper[Y[i]]++;
}
}

/*
printf("\nY count\n");

for(j=0;j<5;j++){
printf("%d  ",YCountHelper[j]);
}
getch();
*/

QuickSort(Y,0,m-1);
/*
for(i=0;i<m;i++){
printf("%d  ",Y[i]);
}
getch();
*/

int count=0;

for(i=0;i<n;i++){
count+=FindCount(X[i],Y,m,YCountHelper);
}

return count;
}


int main(){


//int arr1[]={2,1,6};
int arr1[]={10,19,18};
int n=sizeof(arr1)/sizeof(arr1[0]);

//int arr2[]={1,5};
int arr2[]={11,15,9};
int m=sizeof(arr2)/sizeof(arr2[0]);

printf("\nFind No of pairs such that x^y > y^x : ");
//O(n*m)
//FindPair(arr1,n,arr2,m);

//O(mLog(m) + O(nlog(m)))
int count=FindPair2(arr1,n,arr2,m);
printf("%d ",count);

return 0;
}
