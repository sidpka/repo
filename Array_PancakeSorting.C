#include<stdio.h>
#include<conio.h>


void Flip(int* arr,int i){

int start=0;
int tmp;
while(start<i){
tmp=arr[start];
arr[start]=arr[i];
arr[i]=tmp;
i--;
start++;
}



}

int FindMaxIndex(int* arr,int n){

int i;
int maxIndex;

for(maxIndex=0,i=0;i<=n;i++){
if(arr[i]>arr[maxIndex]){
maxIndex=i;
}
}

return maxIndex;
}

void PancakeSorting(int* arr,int n){


int i;
int maxIndex;
for(i=n-1;i>0;i--){

maxIndex=FindMaxIndex(arr,i);

if(maxIndex!=i){
Flip(arr,maxIndex);
Flip(arr,i);
}


}



}

int main(){


int arr[]={2,3,1,6,4,8,5};

int n=sizeof(arr)/sizeof(arr[0]);

PancakeSorting(arr,n);

printf("\nSorted array\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}









return 0;
}
