#include<stdio.h>
#include<conio.h>


int SmallestSubarray(int* arr,int n,int X){

int start=0;
int end=0;
int minLen=n+1;
int sum=0;
while(end<n){

while(end<n && sum<=X){
sum+=arr[end++];
}



while(sum>X && start<n){
if((end-start)<minLen) {
minLen=end-start;
}
sum-=arr[start++];
}


}

return minLen;

}

int main(){


int arr[]={1,4,45,6,0,18};

int n=sizeof(arr)/sizeof(arr[0]);
int X=51;
int minLen=SmallestSubarray(arr,n,X);

printf("\nMin length subarray with sum greater than : %d is : %d",X,minLen);




return 0;
}
