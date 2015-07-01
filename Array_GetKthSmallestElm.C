#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>


void Swap(int* arr,int left,int right){
arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];

}

/*
int Partition(int* arr,int low,int high){


int pivotElm=arr[high];
int i=low;
int j;

for(j=low;j<=high-1;j++){
if(arr[j]<=pivotElm){
Swap(arr,i,j);
i++;
}
}
Swap(arr,i,high);

return i;
}

*/


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int Partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}

int RandomPartition(int* arr,int low,int high){

int n=high-low+1;

int pivot=rand()%n;
swap(&arr[pivot+low],&arr[high]);

return Partition(arr,low,high);

}



int GetKSmallest(int* arr,int low,int high,int K){

if(K>0 && K<=high-low+1){
int pivot=RandomPartition(arr,low,high);

if(pivot-low==K-1){
    //printf("\npivot : %d, el : %d\n",pivot,arr[pivot]);
return arr[pivot];
}

if(pivot-low > K-1){
return GetKSmallest(arr,low,pivot-1,K);
}

return GetKSmallest(arr,pivot+1,high,K-pivot+low-1);
}

return INT_MAX;
}



int main(){

int arr[]={12,3,5,7,4,19,26};

int n=sizeof(arr)/sizeof(arr[0]);

int K=3;

int kSmallestElement=GetKSmallest(arr,0,n-1,K);

if(kSmallestElement!=INT_MAX){
printf("\n Kth smallest element is : %d",kSmallestElement);
}else{
printf("\nDsnt exist");
}







return 0;
}
