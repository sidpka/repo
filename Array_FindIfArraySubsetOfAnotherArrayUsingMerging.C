#include<stdio.h>
#include<conio.h>

void Swap(int* arr,int left,int right){

arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];

}

int Partition(int* arr,int low,int high){


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
Swap(arr,left,right);
}


}

arr[low]=arr[right];
arr[right]=pivotElm;
return right;

}

void QuickSort(int* arr,int low,int high){

if(high>low){

int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);


}


}


int FindIfSubset(int* mArr,int n,int* sArr,int m){

QuickSort(mArr,0,n-1);
QuickSort(sArr,0,m-1);

int i;
int j;
/*
for(i=0;i<n;i++){
printf("%d  ",mArr[i]);
}
*/

i=0;
j=0;

while(i<n && j<m){

if(mArr[i]<sArr[j]){
i++;
}else if(mArr[i]==sArr[j]){
i++;
j++;
}else{
return 0;
}

}

if(j<m){
return 0;
}

return 1;

}


int main(){

int mArr[]={2,1,4,6,5,0,4};
int n=sizeof(mArr)/sizeof(mArr[0]);

int sArr[]={1,2,4,4,5};
int m=sizeof(sArr)/sizeof(sArr[0]);


int result=FindIfSubset(mArr,n,sArr,m);

if(result){
printf("\nYes ! Subset");
}else{
printf("\nNo! no subset");
}
return 0;
}
