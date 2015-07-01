#include<stdio.h>
#include<conio.h>

void SortK(int* arr,int n,int K){
int key;
int i;
int j;

for(i=1;i<n;i++){

j=i-1;
key=arr[i];
while(j>=0 && key< arr[j]){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}

}


int main(){


int arr[]={3,2,1,6,5,4};

int n=sizeof(arr)/sizeof(arr[0]);

int K=2;

SortK(arr,n,K);

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}



return 0;
}
