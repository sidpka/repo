#include<stdio.h>
#include<conio.h>


int max(int a,int b){

return a>b?a:b;
}

int FindKadane(int arr[],int n){

int curMax=arr[0];
int maxSoFar=arr[0];

int i;

for(i=1;i<n;i++){

curMax=max(arr[i],curMax+arr[i]);

if(curMax>maxSoFar){
maxSoFar=curMax;
}

}

return maxSoFar;




}

int main(){

int arr[]={-2,-3,-4,-1,-2,1,5,-3};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nMax sum contiguous subarray : %d",FindKadane(arr,n));

return 0;
}
