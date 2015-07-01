#include<stdio.h>
#include<conio.h>


int FindFixedPoint(int* arr,int n){

int i;

for(i=0;i<n;i++){
if(arr[i]==i){
return i;
}
}

return -1;
}

int BS(int* arr,int left,int right){

if(left<=right){
if(arr[left]==left){
return left;
}

int mid=(left+right)/2;

int l=BS(arr,left,mid-1);
if(l!=-1){
return l;
}else{
if(arr[mid]==mid){
return mid;
}else{
return BS(arr,mid+1,right);
}
}

}

return -1;
}


int FindFixedPoint2(int* arr,int n){
int index=BS(arr,0,n-1);
return index;
}

int main(){


int arr[]={2,4,2,6,5,7,8};
int n=sizeof(arr)/sizeof(arr[0]);
//O(n)
//int fixedPoint=FindFixedPoint(arr,n);


//O(Log(n))
int fixedPoint=FindFixedPoint2(arr,n);

if(fixedPoint!=-1){
printf("\nFixed point : %d",fixedPoint);
}else{
printf("\nNo fixed point");
}






return 0;
}
