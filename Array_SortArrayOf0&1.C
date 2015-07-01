#include<stdio.h>
#include<conio.h>


void Swap(int* arr,int left,int right){

arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];

}


void Sort012(int* arr,int n){


int low=0;
int high=n-1;
int mid=0;

while(mid<=high){

    while(arr[high]==2 && high>mid){
    high--;
    }
    if(high<mid){
    break;
    }


switch(arr[mid]){
case 0:
Swap(arr,low,mid);
low++;
mid++;
break;
case 1:
mid++;
break;
case 2:
Swap(arr,mid,high);
high--;
break;
}
}


//printf("\nMid is : %d and n is : %d",mid,n);
}


int main(){


int arr[]={0,1,0,2,1,0,0,2,1,1,0,2};

int n=sizeof(arr)/sizeof(arr[0]);
Sort012(arr,n);

printf("\nSorted array is : \n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}






return 0;
}
