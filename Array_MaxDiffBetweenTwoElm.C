#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

int FindMaxDiff(int* arr,int n){


int i;
int j;
int tmp;
int maxDiff=0;
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(arr[j]>arr[i]){
tmp=arr[j]-arr[i];
if(tmp>maxDiff){
maxDiff=tmp;
}
}
}
}

return maxDiff;




}

int FindMaxDiff2(int* arr,int n){

int i;
int tmp;
int maxDiff=INT_MIN;
int minSoFar=arr[0];

for(i=1;i<n;i++){
tmp=arr[i]-minSoFar;
if(tmp>maxDiff){
maxDiff=tmp;
}
if(arr[i]<minSoFar){
minSoFar=arr[i];
}
}
return maxDiff;
}


int FindMaxDiff3(int* arr,int n){

int diff[n-1];
int i;
for(i=0;i<n-1;i++){
diff[i]=arr[i+1]-arr[i];
}

int maxDiff=diff[0];

for(i=1;i<n-1;i++){
if(diff[i-1]>0){
diff[i]+=diff[i-1];
}
if(diff[i]>maxDiff){
maxDiff=diff[i];
}
}

return maxDiff;

return 0;
}



int main(){

int arr[]={2,3,10,6,4,8,1};

int n=sizeof(arr)/sizeof(arr[0]);
//Naive O(n^2)
int maxDiff=FindMaxDiff(arr,n);

printf("\nMax diff : %d",maxDiff);
//O(n)
maxDiff=FindMaxDiff2(arr,n);

printf("\nMax diff : %d",maxDiff);

//O(n)
maxDiff=FindMaxDiff3(arr,n);

printf("\nMax diff : %d",maxDiff);

return 0;
}
