#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void FindProd(int* arr,int n,int* prod){

int* left=(int*)malloc(sizeof(int)*n);
int* right=(int*)malloc(sizeof(int)*n);

left[0]=1;
right[n-1]=1;
int i;
for(i=1;i<n;i++){
left[i]=arr[i-1]*left[i-1];
}

for(i=n-2;i>=0;i--){
right[i]=arr[i+1]*right[i+1];
}

for(i=0;i<n;i++){
prod[i]=left[i]*right[i];
}


}

void FindProd2(int* arr,int n,int* prod){

int temp=1;
int i;
for(i=0;i<n;i++){
prod[i]=temp;
temp*=arr[i];
}

temp=1;

for(i=n-1;i>=0;i--){
prod[i]*=temp;
temp*=arr[i];
}

}

int main(){


int arr[]={2,1,4};

int n=sizeof(arr)/sizeof(arr[0]);
int prod[n];
//Space O(n)
//FindProd(arr,n,prod);


//Space O(1)
FindProd2(arr,n,prod);
printf("\nProd array :\n\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",prod[i]);
}








return 0;
}
