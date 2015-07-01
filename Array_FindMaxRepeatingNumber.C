#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int FindMaxRpeating(int* arr,int n){

int k=arr[0];

int i;

for(i=1;i<n;i++){
if(arr[i]>k){
k=arr[i];
}
}
//k is range of input.. so % operation gives everything less than k
k=k+1;

for(i=0;i<n;i++){
arr[arr[i]%k]+=k;
}

int max=arr[0];
int result=0;
for(i=1;i<n;i++){
if(arr[i]>max){
max=arr[i];
result=i;
}
}

return result;


}


int main(){


int arr[]={2,3,3,5,3,4,1,7};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nMax repeating number : %d",FindMaxRpeating(arr,n));







return 0;
}
