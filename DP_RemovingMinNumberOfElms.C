#include<stdio.h>
#include<conio.h>

int min(int a,int b){
return a<b?a:b;
}

int FindMinRem(int arr[],int low,int high,int n){


if(arr[low]*2>arr[high]){
return (low-0)+(n-1-high);
}

return min(FindMinRem(arr,low+1,high,n),FindMinRem(arr,low,high-1,n));

}

int Partition(int arr[],int low,int high){

int pivotElm=arr[low];
int left=low;
int right=high;

while(left<right){

while(arr[left]<=pivotElm){
left++;
}

while(arr[right]>pivotElm){
right--;
}

if(left<right){
arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];
}

}

arr[low]=arr[right];
arr[right]=pivotElm;

return right;




}

void QuickSort(int arr[],int low,int high){

if(low<high){
int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);
}

}



int FindMinRem_DP(int arr[],int n){

int dp[n][n];

int i;
int j;
int k;

/*
for(i=0;i<n;i++){
for(j=0;j<n;j++){
dp[i][j]=n;
}
}

int result=n;
for(i=0;i<n;i++){

for(j=n-1;j>=0;j--){
if(arr[i]*2>arr[j]){
break;
}
}
if(result>(i-0)+(n-1-j)){
result=(i-0)+(n-1-j);
}

}


return result;
*/


int gap;

for(gap=0;gap<n;gap++){

for(i=0,j=gap;j<n;i++,j++){
if(gap==0){
dp[i][j]=0;
}else{

if(arr[i]*2>arr[j]){
dp[i][j]=0;
}else{
dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
}

}
}

}

/*
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");
}

printf("\n\n%d",dp[0][n-1]);
getch();
*/

return dp[0][n-1];
}

int main(){

int arr[]={4, 5, 100, 9, 10, 11, 12, 15, 200};
//int arr[]={20, 7, 5, 6};
int n=sizeof(arr)/sizeof(arr[0]);

QuickSort(arr,0,n-1);
/*
int i;
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
getch();
*/

//printf("\nMin number of elm to be deleted from either side\n to get 2*min>max is : %d",FindMinRem(arr,0,n-1,n));


printf("\nMin number of elm to be deleted from either side\n to get 2*min>max is : %d",FindMinRem_DP(arr,n));
return 0;
}
