#include<stdio.h>
#include<conio.h>
#include<limits.h>

void FindFirstRepeatingNumber(int* arr,int n){

int min=INT_MAX;
int max=INT_MIN;

int i;

for(i=0;i<n;i++){

if(arr[i]<min){
min=arr[i];
}

if(arr[i]>max){
max=arr[i];
}

}
int tmp[max-min+1];

for(i=0;i<max-min+1;i++){
tmp[i]=0;
}

for(i=0;i<n;i++){
if(tmp[arr[i]-min]<0){
printf("\n First Duplicate Elm : %d",arr[i]);
break;
}else{
tmp[arr[i]-min]=-arr[i];
}
}

}








int main(){

//int arr[]={10,5,3,4,3,5,6};
int arr[]={6,10,5,4,9,12,4,6,11};
int n=sizeof(arr)/sizeof(arr[0]);

FindFirstRepeatingNumber(arr,n);






return 0;
}
