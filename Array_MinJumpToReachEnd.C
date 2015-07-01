#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>


int FindMinJump(int* arr,int low,int high,int* tmp){
if(low==high){
return 0;
}

if(arr[low]==0){
return INT_MAX;
}

int min=INT_MAX;
int i;
int jump;
for(i=low+1;i<=high && i<=low+arr[low];i++){
    if(tmp[i]){
    jump=tmp[i];
    }else{
    tmp[i]=FindMinJump(arr,i,high,tmp);
    jump=tmp[i];
    }
jump=FindMinJump(arr,i,high,tmp);
if(jump!=INT_MAX && jump+1<min){
min=jump+1;
}

}

return min;
}

int FindMinJump2(int* arr,int n,int * tmp){

tmp[n-1]=0;

int i;
int j;
int min;
for(i=n-2;i>=0;i--){
if(arr[i]==0){
tmp[i]=INT_MAX;
}
else if(arr[i]>=n-i-1){
tmp[i]=1;
}else{
min=INT_MAX;
for(j=i+1; j<n && j<=i+arr[i];j++){
if(tmp[j]<min){
min=tmp[j];
}
}

if(min!=INT_MAX){
   tmp[i]=min+1;
   }else{
   tmp[i]=INT_MAX;
   }

}
}

for(i=0;i<n;i++){
printf("%d   ",tmp[i]);
}
getch();
return tmp[0];
}

int main(){
int arr[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
int n=sizeof(arr)/sizeof(arr[0]);
int* tmp=(int*)calloc(n,sizeof(int));
//int minJump=FindMinJump(arr,0,n-1,tmp);

int minJump=FindMinJump2(arr,n,tmp);

if(minJump!=INT_MAX){
printf("\nMinimum number of jumps needed : %d",minJump);
}else{
printf("\nNo path");
}

return 0;
}
