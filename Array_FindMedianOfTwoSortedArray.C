#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int FindMedian_Util(int* arr,int n){

if(n&1){
return arr[n/2];
}else{
return (arr[n/2]+arr[n/2 -1])/2;
}

}

int max(int a,int b){
return a>b?a:b;
}

int min(int a,int b){
return a<b?a:b;
}

int FindMedian(int* arr1,int* arr2,int n){

if(n<=0){
return -1;
}

if(n==1){
return (arr1[0]+arr2[0])/2;
}

if(n==2){
return (max(arr1[0],arr2[0])+ min(arr1[1],arr2[1]))/2;
}

int median1=FindMedian_Util(arr1,n);
int median2=FindMedian_Util(arr2,n);

if(median1==median2){
return median1;
}else if(median1 > median2){

if(n&1){

return FindMedian(arr1+n/2,arr2,n-n/2);
}else{
return FindMedian(arr1+n/2-1,arr2,n-n/2+1);
}
}else{
if(n&1){
return FindMedian(arr1,arr2+n/2,n-n/2);
}else{
return FindMedian(arr1,arr2+n/2-1,n-n/2+1);
}
}
}

int main(){

int arr1[]={1,12,15,26,38};
int arr2[]={2,13,17,30,45};

int size=sizeof(arr1)/sizeof(arr1[0]);
//printf("\n%d",size);

int median=FindMedian(arr1,arr2,size);

printf("\nMedian is : %d",median);
getch();

}
