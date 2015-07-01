#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int GetIndex(int* arr,int left,int right,int key){


int mid;

while(right-left>1){
mid=left+(right-left)/2;
(arr[mid]>=key?right:left)=mid;
}

return right;

}
int FindLIS(int* arr,int n){
int* tmp=(int*)calloc(n,sizeof(int));
int i;
int len=1;
for(i=0;i<n;i++){
if(arr[i]<tmp[0]){
tmp[0]=arr[i];
}else if(arr[i]>tmp[len-1]){
tmp[len++]=arr[i];
}else{
tmp[GetIndex(tmp,-1,len-1,arr[i])]=arr[i];
}
}



return len;

}
int main(){


int arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

int n=sizeof(arr)/sizeof(arr[0]);

int lis=FindLIS(arr,n);

printf("\LIS : %d",lis);

return 0;
}
