#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define RANGE 100

void CountSort(int* arr,int n){

int* Count=(int*)calloc((RANGE+1),sizeof(int));

int i;

for(i=0;i<n;i++){
Count[arr[i]]++;
}

for(i=1;i<RANGE;i++){
Count[i]+=Count[i-1];
}
/*
for(i=0;i<RANGE;i++){
printf("%d  ",Count[i]);
}
getch();
*/
int* output=(int*)malloc(sizeof(int)*n);

for(i=0;i<n;i++){
output[Count[arr[i]]-1]=arr[i];
Count[arr[i]]--;
}

for(i=0;i<n;i++){
arr[i]=output[i];
}

}

int main(){

int arr[]={2,55,7,88,9,55,1,3};
int n=sizeof(arr)/sizeof(arr[0]);

CountSort(arr,n);

printf("\nSorted array is :\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}







return 0;
}
