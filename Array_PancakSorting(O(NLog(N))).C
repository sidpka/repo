#include<stdio.h>
#include<conio.h>


void Flip(int* arr,int i){

int start=0;
int tmp;
while(start<i){
tmp=arr[start];
arr[start]=arr[i];
arr[i]=tmp;
i--;
start++;
}



}

int FindMaxIndex(int* arr,int n){

int i;
int maxIndex;

for(maxIndex=0,i=0;i<=n;i++){
if(arr[i]>arr[maxIndex]){
maxIndex=i;
}
}

return maxIndex;
}

int CeilIndex(int* arr,int l,int h,int key){

if(l<=h){

if(key<=arr[l]){

return l;
}

if(key>arr[h]){
return -1;
}

int mid=(l+h)/2;

if(arr[mid]==key){
return mid;
}

if(arr[mid]<key){
if(mid+1<=h && arr[mid+1]>=key){
return mid+1;
}else{
return CeilIndex(arr,mid+1,h,key);
}
}

if(mid-1 >= l && key>arr[mid-1]){
return mid;
}else{
return CeilIndex(arr,l,mid-1,key);
}


}


}


void PancakeSorting(int* arr,int n){


int i;
int maxIndex;
int j;
for(i=2;i<n;i++){
j=CeilIndex(arr,0,i-1,arr[i]);
if(j!=-1){
Flip(arr,j-1);
Flip(arr,i-1);
Flip(arr,i);
Flip(arr,j);


}


}



}

int main(){


int arr[]={2,3,1,6,4,8,5};

int n=sizeof(arr)/sizeof(arr[0]);

PancakeSorting(arr,n);

printf("\nSorted array\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

return 0;
}
