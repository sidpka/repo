#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int FindMissingNumber(int* arr,int n){
int tmp=1;

int i;

for(i=0;i<n;i++){
if(tmp!=arr[i]){
return tmp;
}
tmp+=1;
}

}


int FindMissingNumber2(int* arr,int n){
int sum=(n+1)*(n+2)/2;

int i;

for(i=0;i<n;i++){
sum-=arr[i];
}
return sum;
}


void FindMissingNumber3(int* arr,int n){
int size=n+2;
int resultSet1=0;
int i;
for(i=0;i<n;i++){
resultSet1=resultSet1^arr[i];
}

int resultSet2=0;

for(i=1;i<=size;i++){
resultSet2=resultSet2^i;
}

 int result =resultSet1^resultSet2;
int m1=0;
int m2=0;

result=result& (result-1);

for(i=0;i<n;i++){
if(arr[i] & result){
m1=m1^arr[i];
}else{
m2=m2^arr[i];
}
}

for(i=1;i<=size;i++){
if(i&result){
m1=m1^i;
}else{
m2=m2^i;
}
}
printf("\nMissing numbers are   : %d and %d",m1,m2);
}


int main(){

int n;

printf("\nEnter the number of elements : ");
scanf("%d",&n);

int i;
int* arr=(int*)malloc(sizeof(int)*n);

for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}


FindMissingNumber3(arr,n);








return 0;
}
