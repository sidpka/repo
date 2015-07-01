#include<stdio.h>
#include<conio.h>


int FindMaxSubarraySum(int* arr,int n){

int i;


int max=0;
int tmpMax=0;
for(i=0;i<n;i++){
    tmpMax+=arr[i];
if(tmpMax<0){
tmpMax=0;
}else{

if(max<tmpMax){
max=tmpMax;
}


}

}

return max;




}


int max(int a,int b){
return a>b?a:b;
}

int max(int a,int b,int c){

//return max(a,b)>c?max(a,b):c;

return max(max(a,b),c);
}

int FindMaxCross(int* arr,int l,int m,int h){

int i;
int leftSum=0;
int sum=0;
for(i=m;i>=0;i--){
sum+=arr[i];
if(sum>leftSum){
leftSum=sum;
}
}

int rightSum=0;
sum=0;
for(i=m+1;i<=h;i++){
sum+=arr[i];
if(sum>rightSum){
rightSum=sum;
}
}


return leftSum+rightSum;


}

int FindMaxSubarraySum2(int* arr,int l,int h){

if(l==h){
return arr[l];
}

int mid=(l+h)/2;

return max(FindMaxSubarraySum2(arr,l,mid),FindMaxSubarraySum2(arr,mid+1,h),FindMaxCross(arr,l,mid,h));

}

int main(){


int arr[]={-2,-5,6,-2,-3,1,5,-6};
int n=sizeof(arr)/sizeof(arr[0]);
//Kadane
//printf("\nMax subarray sum is : %d",FindMaxSubarraySum(arr,n));

//Divide and conquer


printf("\nMax subarray sum is : %d",FindMaxSubarraySum2(arr,0,n-1));



return 0;
}
