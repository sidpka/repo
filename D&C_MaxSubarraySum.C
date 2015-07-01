#include<stdio.h>
#include<conio.h>


int FindMaxSum(int arr[],int n){

int sum=0;
int maxSum=0;

int i;
int j;


for(i=0;i<n;i++){
    sum=0;
for(j=i;j<n;j++){
sum+=arr[j];
if(sum>maxSum){
maxSum=sum;
}
}

}


return maxSum;

}

int max(int a,int b){
return a>b?a:b;
}
int max(int a,int b,int c){

return max(max(a,b),c);
}

int FindCrossingSum(int arr[],int low,int mid,int high){

int leftSum=0;
int sum=0;
int rightSum=0;

int i;

for(i=mid;i>=low;i--){
sum+=arr[i];
if(sum>leftSum){
leftSum=sum;
}
}

sum=0;
for(i=mid+1;i<=high;i++){
sum+=arr[i];
if(sum>rightSum){
rightSum=sum;
}
}


return leftSum+rightSum;

}

int FindSubarraySum(int arr[],int low,int high){
if(low==high){
return arr[low];
}
int mid=(low+high)/2;

return max(FindSubarraySum(arr,low,mid),FindSubarraySum(arr,mid+1,high),FindCrossingSum(arr,low,mid,high));



}
int FindMaxSum2(int arr[],int n){

return FindSubarraySum(arr,0,n-1);
}

int main(){

int arr[]={-2,-5,6,-2,-3,1,5,-6};
int n=sizeof(arr)/sizeof(arr[0]);

//printf("\nMax subarray sum : %d",FindMaxSum(arr,n));
printf("\nMax subarray sum : %d",FindMaxSum2(arr,n));


return 0;
}
