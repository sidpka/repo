#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void PrintArray(int* arr,int n){

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

}


int FindMax(int* arr,int n){

int max=arr[0];

int i;

for(i=1;i<n;i++){
if(max<arr[i]){
max=arr[i];
}
}

return max;
}


void CountingSort(int* arr,int n,int exp){

int count[10];

int i;

for(i=0;i<10;i++){
count[i]=0;
}

for(i=0;i<n;i++){
count[(arr[i]/exp)%10]++;
}

for(i=1;i<10;i++){
count[i]+=count[i-1];
}
//printf("\nHere");
int *output=(int*)malloc(sizeof(int)*n);

for(i=n-1;i>=0;i--){
output[count[(arr[i]/exp)%10]-1]=arr[i];
count[(arr[i]/exp)%10]--;
}

for(i=0;i<n;i++){
arr[i]=output[i];
}


free(output);
}


void RadixSort(int* arr,int n){

int max=FindMax(arr,n);

//printf("\nMax is : %d",max);

int i;
int exp=1;

for(exp=1;max/exp>0;exp*=10){
    //printf("\nHere");
CountingSort(arr,n,exp);
}


}


int main(){

int arr[]={170,45,75,90,802,24,2,66};

int n=sizeof(arr)/sizeof(arr[0]);

RadixSort(arr,n);

printf("\nSorted array :\n\n");

PrintArray(arr,n);






return 0;
}
