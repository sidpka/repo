#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>

int FindMaxJI(int* arr,int n){

int i;
int j;
int max=INT_MIN;
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(arr[i]<arr[j] && max<(j-i)){
max=(j-i);
}
}
}
if(max==INT_MIN){
return -1;
}else{
return max;
}

}


int max(int a,int b){
return a>b?a:b;
}

int min(int a,int b){
return a<b?a:b;
}

int FindMaxJI2(int* arr,int n){

int* leftMin=(int*)malloc(sizeof(int)*n);
int* rightMax=(int*)malloc(sizeof(int)*n);

leftMin[0]=arr[0];

int i;

for(i=1;i<n;i++){
leftMin[i]=min(leftMin[i-1],arr[i]);
}

rightMax[n-1]=arr[n-1];

for(i=n-2;i>=0;i--){
rightMax[i]=max(rightMax[i+1],arr[i]);
}
i=0;
int j=0;
int maxDiff=-1;
while(i<n && j<n){
if(leftMin[i]<rightMax[j]){
maxDiff=max(maxDiff,(j-i));
j++;
}else{
i++;
}

}

return maxDiff;


}

int main(){


int arr[]={34, 8, 10, 3, 2, 80, 30, 33, 1};

int n=sizeof(arr)/sizeof(arr[0]);
//printf("\nSize : %d",n);

/* O(n^2)
int maxJI=FindMaxJI(arr,n);
*/
//O(n)
int maxJI=FindMaxJI2(arr,n);
if(maxJI!=-1){
printf("\nMax J-I is : %d",maxJI);
}else{
printf("\nNo such index ");
}
return 0;
}
