#include<stdio.h>
#include<conio.h>

int CheckDiff(int* arr,int low,int high,int diffElm){
if(high>low){
if(arr[high]-arr[low]==diffElm){
return 1;
}else if(arr[high]-arr[low]>diffElm){
return CheckDiff(arr,low+1,high,diffElm) || CheckDiff(arr,low,high-1,diffElm);
}else{
return 0;
}
}
return 0;
}

void Swap(int* arr,int low,int high){
arr[low]+=arr[high];
arr[high]=arr[low]-arr[high];
arr[low]-=arr[high];
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



int CheckDiff2(int* arr,int n, int diffElm){

int i=0;
int j=1;

while(i<n-1 && j<n){
if(arr[j]-arr[i]==diffElm){
return 1;
}else if(arr[j]-arr[i]<diffElm){
j++;
}else{
i++;
}
}
return 0;
}

int FindIfDiffP(int* arr,int n,int diffElm){
if(n==1 || n==0){
return 0;
}

QuickSort(arr,0,n-1);
/*
int i;
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
getch();
*/
//return CheckDiff(arr,0,n-1,diffElm);
return CheckDiff2(arr,n,diffElm);
}

int main(){

//int arr[]={5,20,3,2,50,80};
//int diffElm=78;

int arr[]={90,70,20,80,50};
int diffElm=45;
int n=sizeof(arr)/sizeof(arr[0]);



int result=FindIfDiffP(arr,n,diffElm);

if(result==1){
printf("\nYes");
}else{
printf("\nNo");
}


return 0;
}
