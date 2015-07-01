#include<stdio.h>
#include<conio.h>

int OnceOccurance(int arr[],int n){

int ones=0;
int twos=0;

int i;
int noThrees;

for(i=0;i<n;i++){
twos |=ones&arr[i];
ones^=arr[i];

noThrees=~(ones&twos);
ones&=noThrees;
twos&=noThrees;
}

return ones;
}

int main(){

int arr[]={3,3,3,4,5,5,5,4,4,6,7,6,6};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nElement occuring once : %d",OnceOccurance(arr,n));


return 0;
}
