#include<stdio.h>
#include<conio.h>
#include<limits.h>

struct MM{
int min;
int max;
};
typedef struct MM minmax;

minmax SetMinMax(int* arr,int low,int high){

if(low>high){
    minmax xp;
    xp.min=INT_MAX;
    xp.max=INT_MIN;
return xp;
}
minmax tmp,tmp1,tmp2;
if(low==high){
tmp.min=arr[low];
tmp.max=arr[low];
return tmp;
}

int mid=(low+high)/2;

tmp=SetMinMax(arr,low,mid-1);
tmp1=SetMinMax(arr,mid+1,high);

if(tmp.min<tmp1.min){
tmp2.min=tmp.min;
}else{
tmp2.min=tmp1.min;
}

if(tmp.max>tmp1.max){
tmp2.max=tmp.max;
}else{
tmp2.max=tmp1.max;
}

if(tmp2.min>arr[mid]){
tmp2.min=arr[mid];
}

if(tmp2.max<arr[mid]){
tmp2.max=arr[mid];
}

/*
if(mm.min>tmp2.min){
mm.min=tmp2.min;
}

if(mm.max<tmp2.max){
mm.max=tmp2.max;
}
*/

return tmp2;
}

minmax GetMinMax(int* arr,int n){
minmax mm;
mm=SetMinMax(arr,0,n-1);
return mm;
}

int main(){

int arr[]={2,1,3,6,5,4};
int n=sizeof(arr)/sizeof(arr[0]);
minmax mm;
mm=GetMinMax(arr,n);
printf("\nMin is : %d",mm.min);
printf("\nMax is : %d",mm.max);

return 0;
}
