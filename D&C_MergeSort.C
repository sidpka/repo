#include<stdio.h>
#include<conio.h>


void DoMerge(int arr[],int tmpArr[],int left,int mid,int right){
//printf("\nHere");
int tmpPos=left;
int leftEnd=mid-1;
int size=right-left+1;


while(left<=leftEnd && mid<=right){
if(arr[left]<arr[mid]){
tmpArr[tmpPos++]=arr[left++];
}else{
tmpArr[tmpPos++]=arr[mid++];

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


}



void MergeSort(int arr[],int tmpArr[],int left,int right){
if(left>=right){
return;
}
int mid=(left+right)/2;
MergeSort(arr,tmpArr,left,mid);
MergeSort(arr,tmpArr,mid+1,right);
DoMerge(arr,tmpArr,left,mid+1,right);
}

int main(){

int arr[]={2,1,6,4,7,5};
int n=sizeof(arr)/sizeof(arr[0]);

int tmpArr[n];


printf("\nSorted array :\n");
int i;
MergeSort(arr,tmpArr,0,n-1);
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

return 0;
}
