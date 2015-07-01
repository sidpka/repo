#include<stdio.h>
#include<conio.h>

int FindSPI(int* arr,int n){

int res=1;
int i;

for(i=0;i<n && arr[i]<=res;i++){
res+=arr[i];
}

return res;


}

int main(){

int arr[]={1,1,3,4};
int n=sizeof(arr)/sizeof(arr[0]);

int smallestPosInt=FindSPI(arr,n);

printf("\nSmallest positive int that can not be represented as subset sum in sorted array : %d",smallestPosInt);






return 0;
}
