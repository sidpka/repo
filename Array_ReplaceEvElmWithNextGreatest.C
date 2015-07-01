#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void FindNextGreatest(int* arr,int n){

int* largest=(int*)malloc(sizeof(int)*n);

largest[n-1]=-1;

int max=-1;
int i;
for(i=n-2;i>=0;i--){
if(arr[i+1]>max){
largest[i]=arr[i+1];
max=arr[i+1];
}else{
largest[i]=max;
}
}

for(i=0;i<n;i++){
printf("%d  ",largest[i]);
}



}


void FindNextGreatest2(int* arr,int n){

int tmp=arr[n-1];
arr[n-1]=-1;
int max=-1;

int i;

for(i=n-2;i>=0;i--){
if(tmp>max){
max=tmp;
}
tmp=arr[i];
arr[i]=max;
}

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

}

int main(){

int arr[]={16,17,4,3,5,2};

int n=sizeof(arr)/sizeof(arr[0]);

//O(n) sapce
//FindNextGreatest(arr,n);


FindNextGreatest2(arr,n);

return 0;
}
