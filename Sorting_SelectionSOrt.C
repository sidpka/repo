#include<stdio.h>
#include<conio.h>


void SelectionSort(int* arr,int n){

int i;
int j;
int min;
int tmp;

for(i=0;i<n-1;i++){
min=i;

for(j=i+1;j<n;j++){
if(arr[min]>arr[j]){
min=j;
}
}
tmp=arr[i];
arr[i]=arr[min];
arr[min]=tmp;
}
}

int main(){


int arr[]={2,1,4,3,8,6,7};

int n=sizeof(arr)/sizeof(arr[0]);

SelectionSort(arr,n);

printf("\nSorted\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}







return 0;
}
