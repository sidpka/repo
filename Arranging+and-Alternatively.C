#include<stdio.h>
#include<conio.h>


void Swap(int* arr,int left,int right){

arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];

}

void Rearrange(int* arr,int n){


int i=0;
int j=n-1;

while(i<j){

while(arr[i]<0){
i++;
}

while(arr[j]>0){
j--;
}

if(i<j){
Swap(arr,i,j);
}
}

//printf("\ni :%d j : %d",i,j);

int pos=j+1;
int neg=0;

while(neg<pos && pos<n && arr[neg]<0){

Swap(arr,neg,pos);
neg+=2;
pos++;

}



}


int main(){

int arr[]={-1,2,-3,4,5,6,-7,8,9};
int n=sizeof(arr)/sizeof(arr[0]);

Rearrange(arr,n);

printf("\nRearranged array is : \n\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}






return 0;
}
