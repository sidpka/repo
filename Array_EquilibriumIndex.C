#include<stdio.h>
#include<conio.h>

int EqIndex(int* arr,int n){

int i,j;

int leftSum=0;
int rightSum=0;

for(i=0;i<n;i++){

leftSum=0;
rightSum=0;

//for left sum
for(j=0;j<i;j++){
leftSum+=arr[i];
}

for(j=i+1;j<n;j++){
rightSum+=arr[i];
}

if(leftSum==rightSum){
return i;
}

}

return -1;
}


int EqIndex2(int* arr,int n){

int leftSum=0;
int sum=0;

int i;

for(i=0;i<n;i++){
sum+=arr[i];
}

for(i=0;i<n;i++){
sum-=arr[i];
if(leftSum==sum){
return i;
}
leftSum+=arr[i];
}

return -1;
}


int main(){

int arr[]={-7,1,5,2,-4,3,0};

int n=sizeof(arr)/sizeof(arr[0]);


//O(n^2)
//int index=EqIndex(arr,n);


//O(n)
int index=EqIndex2(arr,n);

if(index!=-1){
printf("\nEquilibrium index : %d",index);
}else{
printf("\nNo eq index");
}





return 0;
}
