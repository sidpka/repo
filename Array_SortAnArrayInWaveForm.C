#include<stdio.h>
#include<conio.h>

void Swap(int* arr,int left,int right){
arr[left]=arr[left]+arr[right];
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

if(low<high){

int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);


}

}


void WaveSort(int* arr,int n){

QuickSort(arr,0,n-1);

int i;
/*
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

getch();

*/


int j=n/2;
i=0;

while(j<n){
Swap(arr,i,j);
i+=2;
j++;

}

}


void WaveSort2(int* arr,int n){


int i;

for(i=0;i<n;i+=2){
if(i>0 && arr[i-1]>arr[i]){
Swap(arr,i-1,i);
}
if(i<n-1 && arr[i+1]>arr[i]){
Swap(arr,i,i+1);
}
}

}


int main(){

int arr[]={10,5,6,3,2,20,100,80};

int n=sizeof(arr)/sizeof(arr[0]);

//O()nLog(n))
//WaveSort(arr,n);

//O(n)

WaveSort2(arr,n);

printf("\nWave sorted array is \n\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}




return 0;
}
