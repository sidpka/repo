#include<stdio.h>
#include<conio.h>

void FindLargestSubarray(int* arr,int n){


int countZero=0;
int countOne=0;

int i;

for(i=0;i<n;i++){
if(arr[i]==0){
countZero++;
}else{
countOne++;
}
}

int startIndex;
int endIndex;
if(countZero==countOne){
startIndex=0;
endIndex=n-1;
}
else if(countOne==0 || countZero==0){
startIndex=-1;
endIndex=-1;
}else{
startIndex=0;
endIndex=n-1;
while(countZero!=countOne){
if(arr[endIndex]==0 && countZero>countOne){
countZero--;
endIndex--;
}else if(arr[endIndex]==0 && countZero<countOne){
if(arr[startIndex]==0){
startIndex++;
countZero--;
}else if(arr[startIndex]==1){
startIndex++;
countOne--;
}
}else if(arr[endIndex]==1 && countOne>countZero){
countOne--;
endIndex--;
}else if(arr[endIndex]==1 && countOne<countZero){
if(arr[startIndex]==1){
startIndex++;
countOne--;
}else if(arr[startIndex]==0){
startIndex++;
countZero--;
}
}
}
}

if(startIndex==-1 && endIndex==-1){
printf("\nNo subarray");
return;
}
printf("\nSubarray : Start : %d and End : %d",startIndex,endIndex);


}

void FindLargestSubarray2(int* arr,int n){

int sum=0;

int maxSize=-1;
int startIndex;
int i;
int j;

for(i=0;i<n-1;i++){
sum=(arr[i]==0?-1:1);

for(j=i+1;j<n;j++){
sum+=(arr[j]==0?-1:1);

if(sum==0 && maxSize<j-i+1){
maxSize=j-i+1;
startIndex=i;
}
}


}

if(maxSize==-1){
printf("\nNo subarray");
}else{
printf("\nStart : %d end index : %d",startIndex,startIndex+maxSize-1);
}

}


void FindLargestSubarray3(int* arr,int n){

int leftSum[n];

int sum=0;

int i;

leftSum[0]=(arr[0]==0?-1:1);
int min=arr[0];
int max=arr[0];
for(i=1;i<n;i++){

leftSum[i]=leftSum[i-1]+(arr[i]==0?-1:1);
if(leftSum[i]<min){
min=leftSum[i];
}
if(leftSum[i]>max){
max=leftSum[i];
}

}

printf("\nTesting\n");

for(i=0;i<n;i++){
printf("%d  ",leftSum[i]);
}

int hash[max-min+1];
int maxSize=-1;
int startIndex;

for(i=0;i<max-min+1;i++){
hash[i]=-1;
}

for(i=0;i<n;i++){

if(leftSum[i]==0){

startIndex=0;
maxSize=i+1;

}

if(hash[leftSum[i]-min]==-1){
hash[leftSum[i]-min]=i;
}else{
if((i-hash[leftSum[i]-min])>maxSize){
maxSize=i-hash[leftSum[i]-min];
startIndex=hash[leftSum[i]-min]+1;
printf("\nhere for : %d",i);
}

}
}

printf("\nMap\n");
for(i=0;i<max-min+1;i++){
printf("%d  ",hash[i]);
}

if(maxSize==-1){
printf("\No subarray");
}else{
printf("\nMax size if : %d",maxSize);
printf("\nStart: %d End : %d",startIndex,startIndex+maxSize-1);
}

}


int main(){


int arr[]={1, 0, 1, 1, 1, 0, 0};
//int arr[]={1,1,1,1};
//int arr[]={0, 0, 1, 1, 0};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nPress enter to find largest subarray with equal number of 0s and 1s : ");
//FindLargestSubarray(arr,n);
//FindLargestSubarray2(arr,n);
FindLargestSubarray3(arr,n);




return 0;
}
