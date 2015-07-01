#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int FindInversion(int* arr,int n){

int i;
int j;

int count=0;

for(i=0;i<n;i++){
for(j=i+1;j<n;j++){

if(arr[i]>arr[j]){
count++;
}

}
}
return count;
}

void Insert(int* arr,int elm,int atIndex,int n){

int i;

for(i=n;i>atIndex;i--){
arr[i]=arr[i-1];
}

arr[atIndex]=elm;

}

int FindInversion2(int* arr,int n){

int* tmp=(int*)malloc(sizeof(int)*n);
int index=0;
int i;
int count=0;

tmp[index++]=arr[n-1];
int j;

for(i=n-2;i>=0;i--){
    /*
if(arr[i]>tmp[index-1]){

for(j=index-1;j>=0;j--){
if(arr[i]>tmp[j]){
count++;
}else{
break;
}
}

Insert(tmp,arr[i],j+1,index);
index++;

}
*/

if(arr[i]>tmp[index-1]){

for(j=0;j<index;j++){
if(arr[i]>tmp[j]){
count+=index-j;
break;
}
}

Insert(tmp,arr[i],j,index);
index++;

}
else{
tmp[index++]=arr[i];
}

}

return count;
}


int main(){

int arr[]={2,4,1,3,5};
//int arr[]={1,2,3,4,5};
//int arr[]={5,4,3,2,1};
int n;
n=sizeof(arr)/sizeof(arr[0]);
//naive
printf("\nNo of inversions : %d",FindInversion(arr,n));
//DP
printf("\nNo of inversions : %d",FindInversion2(arr,n));
getch();



return 0;
}
