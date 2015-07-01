#include<stdio.h>
#include<conio.h>

void Merge(int* arr,int* tmp,int left,int mid,int right){

int leftEnd=mid-1;
int size=right-left+1;
int index=left;

while(left<=leftEnd && mid<=right){
if(arr[left]<=arr[mid]){
tmp[index++]=arr[left];
left++;
}else{
tmp[index++]=arr[mid];
mid++;
}
}

while(left<=leftEnd){
tmp[index++]=arr[left];
left++;
}

while(mid<=right){
tmp[index++]=arr[mid];
mid++;
}
int i;
for(i=index-1;i>=0;i--){
arr[i]=tmp[i];
}



}

void MergeSort(int* arr,int* tmp,int left,int right){

if(right>left){
int mid=(left+right)/2;
MergeSort(arr,tmp,left,mid);
MergeSort(arr,tmp,mid+1,right);
Merge(arr,tmp,left,mid+1,right);
}
}


int main(){

int arr[]={6,5,4,3,2,1};

int n=sizeof(arr)/sizeof(arr[0]);

int tmp[n];

MergeSort(arr,tmp,0,n-1);

printf("\nSorted\n\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

return 0;
}
