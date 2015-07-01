#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int FindMaxLBitonic(int* arr,int n){

int* inc=(int*)calloc(n,sizeof(int));
int* dec=(int*)calloc(n,sizeof(int));

inc[0]=1;
int i;

for(i=1;i<n;i++){
if(arr[i]>arr[i-1]){
inc[i]=inc[i-1]+1;
}else{
inc[i]=1;
}
}

dec[n-1]=1;

for(i=n-2;i>=0;i--){
if(arr[i]>arr[i+1]){
dec[i]=dec[i+1]+1;
}else{
dec[i]=1;
}
}


int max=0;
/*
for(i=0;i<n;i++){
printf("%d  ",inc[i]);
}
printf("\n");
for(i=0;i<n;i++){
printf("%d  ",dec[i]);
}

*/

for(i=0;i<n;i++){
if(inc[i]+dec[i]-1 >max){
max=inc[i]+dec[i]-1;
}
}

return max;
}

int main(){

int arr[]={12,4,78,90,45,32};
int n=sizeof(arr)/sizeof(arr[0]);

int max=FindMaxLBitonic(arr,n);

printf("\nMax length bitonic subaaray is : %d",max);




return 0;
}
