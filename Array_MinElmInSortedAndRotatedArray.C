#include<stdio.h>
#include<conio.h>

int min(int a,int b){
return a<b?a:b;
}

int FindMin(int* arr,int low,int high){

if(high<low){
return arr[low];
}

if(high==low){
return arr[low];
}

int mid=(low+high)/2;

if(mid<high  && arr[mid+1]<arr[mid]){
    return arr[mid+1];

}

if(arr[low]==arr[mid] && arr[mid]==arr[high]){
return min(FindMin(arr,low,mid-1),FindMin(arr,mid+1,high));
}


if(mid>low && arr[mid]<arr[mid-1]){
return arr[mid];
}

if(arr[high]>arr[mid]){
return FindMin(arr,low,mid-1);
}

return FindMin(arr,mid+1,high);


}

int main(){


//int arr[]={5,6,1,2,3,4};
int arr[]={2,2,2,2,2,2,2,2,0,1,1,2};
int n=sizeof(arr)/sizeof(arr[0]);

int min=FindMin(arr,0,n-1);

printf("\nMin : %d",min);




return 0;
}
