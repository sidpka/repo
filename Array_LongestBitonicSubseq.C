#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>


int FindLongestBitonic(int* arr,int n){

int i;

int* inc=(int*)malloc(sizeof(int)*n);
int * dec=(int*)malloc(sizeof(int)*n);

for(i=0;i<n;i++){
inc[i]=1;
dec[i]=1;
}

int j;


for(i=1;i<n;i++){
for(j=0;j<i;j++){
if(arr[i]>arr[j] && inc[i]<arr[i]+inc[j]){
inc[i]=inc[j]+1;
}
}
}

for(i=n-2;i>=0;i--){

for(j=n-1;j>i;j--){
if(arr[i]>arr[j] && dec[i]<dec[j]+arr[i]){
dec[i]=dec[j]+1;
}
}

}

int max=INT_MIN;

for(i=0;i<n;i++){
if(max<inc[i]+dec[i]-1){
max=inc[i]+dec[i]-1;
}
}

return max;

}

int main(){

int arr[]={1, 11, 2, 10, 4, 5, 2, 1};
//int arr[]={80, 60, 30, 40, 20, 10};
int n=sizeof(arr)/sizeof(arr[0]);

int maxBitonicSubSeq=FindLongestBitonic(arr,n);

printf("\nLongest Bitonic SubSeq : %d",maxBitonicSubSeq);
getch();







return 0;
}
