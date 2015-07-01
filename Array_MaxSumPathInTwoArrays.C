#include<stdio.h>
#include<conio.h>
#define SIZE 100

int max(int a,int b){
return a>b?a:b;
}

int MaxSumPath(int* A,int n,int* B,int m){



int i=0;
int j=0;

int result=0;
int sumA=0;
int sumB=0;

while(i<n && j<m){

if(A[i]<B[j]){
sumA+=A[i];
i++;
}
else if(A[i]>B[j]){
sumB+=B[j];
j++;
}else{

//printf("\nCommon point : %d",A[i]);
result+=max(sumA,sumB)+A[i];
//printf("\nReuslt : %d",result);
i++;
j++;
sumA=0;
sumB=0;
}




}

while(i<n){
sumA+=A[i++];
}

while(j<m){
sumB+=B[j++];
}

result+=max(sumA,sumB);

return result;
}




int main(){

int A[]={2,3,7,10,12};
int n=sizeof(A)/sizeof(A[0]);

int B[]={1,5,7,8};
int m=sizeof(B)/sizeof(B[0]);

int maxSum=MaxSumPath(A,n,B,m);

printf("\nMax sum path in two arrays : %d",maxSum);







return 0;
}
