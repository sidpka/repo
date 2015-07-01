#include<stdio.h>
#include<conio.h>


void PrintAllCombinationsUtil(int* arr,int start,int end,int* buffer,int index,int r){

if(index==r){

int j;

for(j=0;j<r;j++){
printf("%d  ",buffer[j]);
}
printf("\n");

}

int i;

for(i=start;i<=end && end-i+1>=r-index;i++){
buffer[index]=arr[i];
PrintAllCombinationsUtil(arr,i+1,end,buffer,index+1,r);
while(arr[i]==arr[i+1]){
i++;
}
}



}

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


void PrintAllCombinationsUtil2(int* arr,int i,int end,int* buffer,int index,int r){

if(index==r){

int j;

for(j=0;j<r;j++){
printf("%d  ",buffer[j]);
}

printf("\n");

return;



}

if(i>end){
return;
}

buffer[index]=arr[i];

PrintAllCombinationsUtil2(arr,i+1,end,buffer,index+1,r);

while(arr[i]==arr[i+1]){
i++;
}

PrintAllCombinationsUtil2(arr,i+1,end,buffer,index,r);




}


void PrintAllCombinations(int* arr,int n,int r){

int buffer[r];


//To handle duplicates

QuickSort(arr,0,n-1);

/*
int i;
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
getch();
*/

//PrintAllCombinationsUtil(arr,0,n-1,buffer,0,r);


//Pascal's identity nCr=n-1Cr + n-1Cr-1

PrintAllCombinationsUtil2(arr,0,n-1,buffer,0,r);

}

int main(){

int arr[]={1,2,2,4};

int n=sizeof(arr)/sizeof(arr[0]);
int r=2;
PrintAllCombinations(arr,n,r);







return 0;
}
