#include<stdio.h>
#include<conio.h>

int Merge(int* arr,int* tmp,int left,int mid,int right){

    int invCount=0;
    int leftEnd=mid-1;
    int index=left;
    int size=right-left+1;
    while(left<=leftEnd && mid<=right){

    if(arr[left]<=arr[mid]){
    tmp[index++]=arr[left++];
    }else{
    tmp[index++]=arr[mid++];
    invCount+=leftEnd+1-left;
    }

    }

    while(left<=leftEnd){
    tmp[index++]=arr[left++];
    }

    while(mid<=right){
    tmp[index++]=arr[mid++];
    }

int i;

for(i=0;i<size;i++){
arr[right]=tmp[right];
right=right-1;
}

return invCount;

}

int MergeSort(int* arr,int* tmp,int left,int right){

int invCount=0;

if(right>left){
int mid=(left+right)/2;
invCount=MergeSort(arr,tmp,left,mid);
invCount+= MergeSort(arr,tmp,mid+1,right);
invCount+=Merge(arr,tmp,left,mid+1,right);
}
//printf("\nWill return : %d",invCount);
return invCount;
}

int FindInversionCount(int* arr,int n){

int invCount=0;
int tmp[n];
invCount=MergeSort(arr,tmp,0,n-1);
return invCount;
}

int main(){


int arr[]={2,1,4,3,6,8};

int n=sizeof(arr)/sizeof(arr[0]);



printf("\nInversion count is : %d\n\n",FindInversionCount(arr,n));
/*
int i;
for(i=0;i<n;i++){

printf("%d  ",arr[i]);
}
*/
getch();

return 0;
}
