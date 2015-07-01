#include<stdio.h>
#include<conio.h>

void PrintPair(int* pair,int* arr,int n){

arr[0]=(pair[0]+pair[1]-pair[n-1])/2;

int i;

for(i=0;i<n-1;i++){
arr[i+1]=pair[i]-arr[0];
}


}

int main(){


int pair[]={14,9,10,11,12,7};
int n=4;
int arr[n];

PrintPair(pair,arr,n);

int i;

printf("\nOriginal array\n\n");

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}



return 0;
}
