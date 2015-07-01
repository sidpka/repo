#include<stdio.h>
#include<conio.h>

int CheckOddOccurance(int arr[],int n){

int num=0;
int i;
for(i=0;i<n;i++){
num^=arr[i];
}
return num;
}

int main(){
int arr[]={1,2,3,2,3,1,3};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nNumber occuring odd number of times : %d",CheckOddOccurance(arr,n));

return 0;
}
