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


int FindMissingNumber3(int* arr,int n){

int resultSet1=0;
int i;
for(i=0;i<n;i++){
resultSet1=resultSet1^arr[i];
}

int resultSet2=0;

for(i=1;i<=n+1;i++){
resultSet2=resultSet2^i;
}

return resultSet1^resultSet2;
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

//int missingNumber=FindMissingNumber(arr,n);
//another method
//int missingNumber=FindMissingNumber2(arr,n);
int missingNumber=FindMissingNumber3(arr,n);
printf("\nMissing number is : %d",missingNumber);







return 0;
}
