#include<stdio.h>
#include<conio.h>



int FindMissing_Util(int arr[],int low,int high,int diff){

if(low>=high){
return 999999;
}

int mid=(low+high)/2;

if(arr[mid+1]-arr[mid]!=diff){

return arr[mid]+diff;
}

if(mid>0 && (arr[mid]-arr[mid-1]!=diff )){
return arr[mid-1]+diff;
}

if(arr[mid]==arr[0]+diff*mid){
return FindMissing_Util(arr,mid+1,high,diff);
}else{
return FindMissing_Util(arr,low,mid-1,diff);
}



}

int FindMissing(int arr[],int n){

int diff=(arr[n-1]-arr[0])/n;

return FindMissing_Util(arr,0,n-1,diff);
}

int main(){


int arr[]={2,4,8,10};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nMissing number : %d",FindMissing(arr,n));


return 0;
}
