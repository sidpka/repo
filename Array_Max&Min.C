#include<stdio.h>
#include<conio.h>
#include<limits.h>

void PrintMaxMin(int* arr,int n){

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
printf("\nMin is : %d",min);
printf("\nMax is : %d",max);

}

int main(){

int arr[]={2,1,4,6,3,3};
int n=sizeof(arr)/sizeof(arr[0]);

PrintMaxMin(arr,n);

return 0;
}
