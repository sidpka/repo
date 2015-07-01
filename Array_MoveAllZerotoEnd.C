#include<stdio.h>
#include<conio.h>


void Swap(int* arr,int left,int right){

int tmp;

tmp=arr[left];
arr[left]=arr[right];
arr[right]=tmp;


}

void MoveZeroToEnd(int* arr,int n){

int left=0;
int right=n-1;


while(left<right){

while(arr[left]!=0){
left++;
}

while(arr[right]==0){
right--;
}

if(left<right){
Swap(arr,left,right);
}


}


left=0;

for(left=0;left<n;left++){
printf("%d  ",arr[left]);
}


}

int main(){

int arr[] ={2,4,0,5,9,0,4,0};
int n=sizeof(arr)/sizeof(arr[0]);

MoveZeroToEnd(arr,n);








return 0;
}
