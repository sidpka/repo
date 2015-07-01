#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define RANGE 255


void CountSort(char arr[],int n){

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

char arr[]="geeksforgeeks";
//int n=sizeof(arr)/sizeof(arr[0]);
int n=strlen(arr);
CountSort(arr,n);

printf("\nSorted array is :\n");

printf("%s",arr);







return 0;
}
