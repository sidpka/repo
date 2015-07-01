#include<stdio.h>
#include<conio.h>


int FindMajority(int* arr,int elm,int n){

int i;

for(i=0;i<n;i++){
if((i+n/2 <n) && arr[i]==elm && (arr[i]==arr[i+n/2])){
    //printf("\nHere for %d",arr[i]);
return 1;
}
}

return 0;
}



int BinarySearch(int arr[],int elm,int low,int high){

if(high>=low){

int mid=(low+high)/2;

if((mid==0 || elm> arr[mid-1]) && (arr[mid]==elm)){
return mid;
}else if(elm>arr[mid]){
return BinarySearch(arr,elm,mid+1,high);
}else{
return BinarySearch(arr,elm,low,mid-1);
}


}

return -1;

}

int FindMajority2(int* arr,int elm,int n){

int i=BinarySearch(arr,elm,0,n-1);
//printf("\nIndex : %d\n",i);
if(i==-1){
return 0;
}

if(i+n/2<n && arr[i]==arr[i+n/2]){
return 1;
}else{
return 0;
}
}


int main(){
int arr[]={1,2,2,2,3};
int n=sizeof(arr)/sizeof(arr[0]);
int elm=2;
//O(n)
FindMajority(arr,elm,n)==1?printf("\nYes"):printf("\nNo");

//O(Log(n));
FindMajority2(arr,elm,n)==1?printf("\nYes"):printf("\nNo");

return 0;
}
