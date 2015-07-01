#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int FindLIS(int* arr,int n){

int* tmp=(int*)malloc(sizeof(int)*n);

int i;
int j;

for(i=0;i<n;i++){
tmp[i]=1;
}

for(i=1;i<n;i++){

for(j=0;j<i;j++){
if(arr[i]>arr[j] && tmp[i]<tmp[j]+1){
tmp[i]=tmp[j]+1;
}
}

}

int max=1;

for(i=0;i<n;i++){
if(tmp[i]>max){
max=tmp[i];
}
}

return max;
}



int FindIndex(int* arr,int index,int key){

int low=0;
int high=index-1;
int mid;
while(low<high){
mid=(low+high)/2;
if(arr[mid]==key){
return mid;
}else if(arr[mid]>key){
high=mid-1;
}else{
low=mid+1;
}


}

return high;

}

int FindLIS2(int* arr,int n){


int i;

int index=0;

int* tmp=(int*)malloc(sizeof(int)*n);

int* prev=(int*)malloc(sizeof(int)*n);
prev[0]=-1;
tmp[index++]=arr[0];

for(i=1;i<n;i++){

if(arr[i]<tmp[0]){
tmp[0]=arr[i];
}else if(arr[i]>tmp[index-1]){
    prev[index]=tmp[index-1];
tmp[index++]=arr[i];
}else{

int pos=FindIndex(tmp,index,arr[i]);
prev[index]=tmp[pos];
tmp[pos]=arr[i];

}


}

printf("\nLIS is : \n");
printf("%d  ",tmp[index-1]);
for(i=index-1;i>0;i--){
printf("%d  ",prev[i]);
}

printf("\n");
return index;
}


int main(){


//int arr[]={2,5,3,7,11,8,10,13,6};
int arr[]={2,3,10,5,6};
int n=sizeof(arr)/sizeof(arr[0]);

//O(n^2) time complexity
//printf("\nLongest Increasing Subsequence is : %d",FindLIS(arr,n));

//O(NLog(N)) time complexity
printf("\nLongest Increasing Subsequence is : %d",FindLIS2(arr,n));


return 0;
}
