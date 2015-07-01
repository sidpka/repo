#include<stdio.h>
#include<conio.h>



void FindSubarray(int* arr,int n){
int hash[1000];

int i;

for(i=-400;i<500;i++){
hash[i]=-1;
}

int sum=0;
for(i=0;i<n;i++){
sum+=arr[i];
if(sum==0){
printf("\n%d--%d",0,i);
return;
}

if(arr[i]==0){
printf("\n%d--%d",i,i);
return;
}

if(hash[sum]!=-1){
printf("\n%d--%d",hash[sum]+1,i);
return;
}

hash[sum]=i;
}

printf("\nSubarray with sum 0 is not found");

}

int main(){

//int arr[]={4,2,-3,1,6};
int arr[]={4,2,0,1,6};
//int arr[]={-3,2,3,1,6};
int n=sizeof(arr)/sizeof(arr[0]);


FindSubarray(arr,n);




return 0;
}
