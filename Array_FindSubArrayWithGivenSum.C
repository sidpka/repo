#include<stdio.h>
#include<conio.h>

void FindSubArray(int* arr,int n,int sum){

int leftIndex;
int i;
int j;

int sumTemp=0;

for(i=0;i<n;i++){
leftIndex=i;
sumTemp=0;

for(j=i;j<n;j++){
sumTemp+=arr[j];
if(sumTemp>sum){
break;
}
if(sumTemp==sum){
printf("\n\nSubArray : %d -- %d",leftIndex,j);
return;
}
}

}

printf("\nNo subArray");
}

void FindSubArray2(int* arr,int n,int sum){

int i=0;
int j=-1;

int sumTemp=0;

while(i<n && j<n){
    //printf("\nSum is : %d\n",sumTemp);
    if(sumTemp==sum){
    printf("\nSubArray : %d -- %d",i,j);
    return;
    }else if(sumTemp<sum && j<n){
    sumTemp+=arr[++j];
    }else if(sumTemp>sum){
    sumTemp-=arr[i];
    i++;
    }

}

printf("\nNo SubArray");

}

int main(){

int arr[]={2,1,6,4,8,6};

int n=sizeof(arr)/sizeof(arr[0]);

int sum=21;

printf("\nPress enter to find the contiguous subarray : ");
getch();
//FindSubArray(arr,n,sum);
FindSubArray2(arr,n,sum);

return 0;
}
