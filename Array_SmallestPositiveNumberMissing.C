#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>

int FindSmallestPosN(int* arr,int n){

int smallestPosN;

int i;
int max=INT_MIN;
int min=INT_MAX;

for(i=0;i<n;i++){
if(arr[i]>max){
max=arr[i];
}
}

if(max<=0){
return -1;
}

int* tmp=(int*)calloc(max+1,sizeof(int));

for(i=0;i<n;i++){
if(arr[i]>0){
tmp[arr[i]]++;
}
}

for(i=1;i<max;i++){
if(!tmp[i]){
return i;
}
}


}

int Swap(int* arr,int left,int right){

arr[left]+=arr[right];
arr[right]=arr[left]-arr[right];
arr[left]-=arr[right];

}

int Segragate(int* arr,int n){

int left=0;
int right=n-1;


while(left<right){
while(arr[left]<=0){
left++;
}
while(arr[right]>0){
right--;
}

if(arr[left]>0 && arr[right]<=0 && left<right){
Swap(arr,left,right);
left++;
right--;
}

}

return left;
}


int FindMissing(int* arr,int n){

int i;

for(i=0;i<n;i++){

if(abs(arr[i]-1)<n && arr[abs(arr[i])-1]>0){

arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
}

}

for(i=0;i<n;i++){
if(arr[i]>0){
return i+1;
}
}

return n+1;
}


int FindSmallestPosN2(int* arr,int n){

int i;
/*
for(i=0;i<n;i++){
printf("%d  ",arr[i ]);
}
*/
int posStart=Segragate(arr,n);
/*
printf("\npos : %d",posStart);
printf("\n\n");

for(i=0;i<n;i++){
printf("%d  ",arr[i ]);
}
*/


int missingN=FindMissing(arr+posStart,n-posStart);


return missingN;
}

int main(){


int arr[]={2, 3, 6, 4, 5, 1, -10, 7};

int n=sizeof(arr)/sizeof(arr[0]);

//Hashing takes extra spc
//int result=FindSmallestPosN(arr,n);

int result=FindSmallestPosN2(arr,n);

if(result!=-1){
printf("\nSmallest positive number missing : %d",result);
}else{
printf("\nNo positive number");
}





return 0;
}
