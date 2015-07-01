#include<stdio.h>
#include<conio.h>

void BubbleSort(int* arr,int n){

int i;
int j;
int tmp;
int flag=1;
for(i=n-1;i>=0;i--){
if(flag==1){
    flag=0;
for(j=0;j<i;j++){
if(arr[j]>arr[j+1]){
tmp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=tmp;
flag=1;
}
}
}else{
break;
}
}
}

int main(){

int arr[]={2,1,4,3,8,6,7};

int n=sizeof(arr)/sizeof(arr[0]);


printf("\nSorted\n\n");
 int i;
BubbleSort(arr,n);
 for(i=0;i<n;i++){
 printf("%d  ",arr[i]);
 }






return 0;
}
