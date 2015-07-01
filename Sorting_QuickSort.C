#include<stdio.h>
#include<conio.h>


void Swap(int* arr,int left,int right){
arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];
}

int Partition(int* arr,int low,int high){
int pivotItem=arr[low];
int left=low;
int right=high;
int tmp;
while(left<right){

while(arr[left]<=pivotItem){
left++;
}
while(arr[right]>pivotItem){
right--;
}

if(left<right){

    Swap(arr,left,right);
    /*
arr[left]=arr[left]+arr[right];
arr[right]=arr[left]-arr[right];
arr[left]=arr[left]-arr[right];
*/
    /*
tmp=arr[left];
arr[left]=arr[right];
arr[right]=tmp;
*/
}

}

arr[low]=arr[right];
arr[right]=pivotItem;
return right;
}

void QuickSort(int* arr,int low,int high){
if(high>low){
int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);
}
}

int main(){

int arr[]={3,1,4,2,6,8};

int n=sizeof(arr)/sizeof(arr[0]);

QuickSort(arr,0,n-1);

printf("\nArray after sorting : \n\n");
getch();

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);

}




return 0;
}
