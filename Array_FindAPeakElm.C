#include<stdio.h>
#include<conio.h>


int FindPeak(int* arr,int n){

int i;

if(arr[0]>arr[1]){
return arr[0];
}

if(arr[n-1]>arr[n-2]){
return arr[n-1];
}



for(i=i;i<n-1;i++){
if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
return  arr[i];
}
}

//return -1
}


int FindPeak2(int* arr,int left,int right,int n){

int mid=(left+right)/2;



if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1])){
return arr[mid];
}else if(mid>0 && arr[mid]<arr[mid-1]){
return FindPeak2(arr,left,mid-1,n);
}else{

    return FindPeak2(arr,mid+1,right,n);

}



}


int main(){


//int arr[]={5,10,20,15};
int arr[]={40,4,3,2,1};
int n=sizeof(arr)/sizeof(arr[0]);

//O(n) time
//printf("\nPeak Element : %d",FindPeak(arr,n));

//O(Log(n) time)

printf("\nPeak Element : %d",FindPeak2(arr,0,n-1,n));



return 0;
}
