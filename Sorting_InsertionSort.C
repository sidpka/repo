#include<stdio.h>
#include<conio.h>


void InsertionSort(int* arr,int n){

int i;
int j;
int tmp;

for(i=1;i<n;i++){

tmp=arr[i];
j=i;
//printf("\nTmp is : %d and j is : %d",tmp,j);
while(arr[j-1]>tmp && j>0){
arr[j]=arr[j-1];
//printf("\nArray[%d] is : %d",j,arr[j]);
j--;
}
arr[j]=tmp;
}
}

int main(){


int arr[]={2,1,4,3,8,6,7};

int n=sizeof(arr)/sizeof(arr[0]);

InsertionSort(arr,n);

printf("\nSorted\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}







return 0;
}
