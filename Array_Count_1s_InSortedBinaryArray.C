#include<stdio.h>
#include<conio.h>

int BS(int* arr,int low,int high){

if(arr[low]==0){
return low-1;
}

if(arr[high]==1){
return high;
}

int mid=(low+high)/2;

if(mid-1 >=low && arr[mid-1]==1 && arr[mid]==0){
return mid-1;
}

else if(mid+1<=high && arr[mid+1]==0 && arr[mid]==1){
return mid;
}else if(arr[mid]==0){
return BS(arr,low,mid-1);
}else{
return BS(arr,mid+1,high);
}



}


int GetCount(int* arr,int n){


int lastIndex=BS(arr,0,n-1);

//printf("\nLast Index : %d",lastIndex);

return lastIndex-0+1;


}

int main(){


//int arr[]={1,1,0,0,0,0,0};
//int arr[]={1,1,1,1,1,1,1,1};
int arr[]={1,1,1,1,0,0};
int n=sizeof(arr)/sizeof(arr[0]);

int countOf1=GetCount(arr,n);

printf("\nCount of 1 : %d",countOf1);






return 0;
}
