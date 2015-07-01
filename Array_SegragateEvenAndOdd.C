#include<stdio.h>
#include<conio.h>

int Swap(int* arr,int left,int right){
arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];
}

void SegragateEvenOdd(int* arr,int n){

int left=0;
int right=n-1;

while(left<right){

while(!(arr[left]&1)){
left++;
}

while(arr[right]&1){
right--;
}

if(left<right){
Swap(arr,left,right);
left++;
right--;
}

}
}

int main(){

int arr[]={1,2,4,3,5,6,9,7,8,10};

int n=sizeof(arr)/sizeof(arr[0]);


//int sArr[n];

SegragateEvenOdd(arr,n);

printf("\nSegragated \n\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}







return 0;
}
