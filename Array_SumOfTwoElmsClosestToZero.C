#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


int FindSum(int* arr,int n){


int i;
int j;

int sum=0;
int result=9999;
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
sum=arr[i]+arr[j];
if(abs(result)>abs(sum)){
result=sum;
}
}

}

return result;
}

int cmp(const void* a,const void* b){

return *(int*)a-*(int*)b;

}

int FindSum2(int* arr,int n){

int tmp[n];

int i;

for(i=0;i<n;i++){
tmp[i]=arr[i];
}

qsort(tmp,n,sizeof(int),cmp);
/*
for(i=0;i<n;i++){
printf("%d  ",tmp[i]);
}
*/

int left=0;
int right=n-1;
int result=99999;
int sum=0;
int a,b;
while(left<right){
sum=tmp[left]+tmp[right];
if(abs(result)>abs(sum)){
result=sum;
a=tmp[left];
b=tmp[right];
}
if(sum<0){
left++;
}else{
right--;
}
}

printf("\nSum of : %d and %d :   ",a,b);

return result;
}



int main(){

int arr[]={1,60,-10,70,-80,85};

int n=sizeof(arr)/sizeof(arr[0]);

//Find Sum of two elements so that sum is closest to zero

//Naive O(n^2)
int sum=FindSum(arr,n);
printf("\n%d",sum);


//O(n)
sum=FindSum2(arr,n);
printf("%d",sum);

return 0;
}
