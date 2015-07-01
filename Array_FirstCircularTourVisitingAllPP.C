#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int FindPetrolPump(int arr[][2],int n){

int startIndex=-1;

int distanceToBeCovered=0;

int i;

int tmp=0;

int* buffer=(int*)malloc(sizeof(int)*n);

buffer[0]=arr[0][0]-arr[0][1];
startIndex=0;
for(i=1;i<n;i++){
if(buffer[i-1]<0){
startIndex=i;
buffer[i]=arr[i][0]-arr[i][1];
distanceToBeCovered+=buffer[i-1];
}else{
buffer[i]=buffer[i-1]+arr[i][0]-arr[i][1];
}
}

if(buffer[i-1]>=distanceToBeCovered){
return startIndex;
}else{
return -1;
}

}


int FindPetrolPump2(int arr[][2],int n){

int startIndex=-1;

int distanceToBeCovered=0;

int i;

int tmp=0;

//int* buffer=(int*)malloc(sizeof(int)*n);

int buffer;
buffer=arr[0][0]-arr[0][1];
startIndex=0;
for(i=1;i<n;i++){
if(buffer<0){
startIndex=i;
distanceToBeCovered+=buffer;
buffer=arr[i][0]-arr[i][1];
}else{
buffer=buffer+arr[i][0]-arr[i][1];
}
}

if(buffer>=distanceToBeCovered){
return startIndex;
}else{
return -1;
}

}


int main(){


int arr[][2]={{4,6,},{6,5},{7,3},{4,5},{3,6},{2,4},{4,1}};
//int arr[][2]={{6,4},{3,6},{7,3}};
int n=sizeof(arr)/sizeof(arr[0]);

//O(n) space , O(n) time complexity
//int startIndex=FindPetrolPump(arr,n);

//O(1) space and O(n) time
int startIndex=FindPetrolPump2(arr,n);
startIndex==-1?printf("\No Petrol Pump found"):printf("\nPetrol pump : %d",startIndex);




return 0;
}
