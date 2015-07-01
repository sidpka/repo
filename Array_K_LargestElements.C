#include<stdio.h>
#include<conio.h>

void GetKLargest(int* arr,int n,int K){

int i;
int j;
int tmp;
for(i=n-1;i>=n-K;i--){

for(j=0;j<i;j++){
if(arr[j]>arr[j+1]){
tmp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=tmp;
}
}

}

}

int main(){

int arr[]={2,1,4,3,5,0,8};
int n=sizeof(arr)/sizeof(arr[0]);

int K=3;

GetKLargest(arr,n,K);

printf("\nK Largest elements are : \n");

int i;

for(i=n-K;i<n;i++){
printf("%d  ",arr[i]);
}






return 0;
}
