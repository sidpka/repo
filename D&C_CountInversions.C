#include<stdio.h>
#include<conio.h>


int DoMerge(int arr[],int tmpArr[],int left,int mid,int right){
//printf("\nHere");
int tmpPos=left;
int leftEnd=mid-1;
int size=right-left+1;
int invCount=0;

while(left<=leftEnd && mid<=right){
if(arr[left]<=arr[mid]){
tmpArr[tmpPos++]=arr[left++];
}else{
tmpArr[tmpPos++]=arr[mid++];
invCount+=(mid-left);
}

}
while(left<=leftEnd){
tmpArr[tmpPos++]=arr[left++];
}

while(mid<=right){
tmpArr[tmpPos++]=arr[mid++];
}

int i;

for(i=0;i<=size;i++){
arr[right]=tmpArr[right];
right--;
}

return invCount;
}



int MergeSort(int arr[],int tmpArr[],int left,int right){
if(left>=right){
return 0;
}
int invCount=0;
int mid=(left+right)/2;
invCount=MergeSort(arr,tmpArr,left,mid);
invCount+=MergeSort(arr,tmpArr,mid+1,right);
invCount+=DoMerge(arr,tmpArr,left,mid+1,right);

return invCount;
}

int main(){

int arr[]={2,1};
int n=sizeof(arr)/sizeof(arr[0]);

int tmpArr[n];


int invCount=MergeSort(arr,tmpArr,0,n-1);
printf("\nInvCount : %d",invCount);

return 0;
}
