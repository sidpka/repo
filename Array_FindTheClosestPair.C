#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

void FindClosestPairSum(int* A,int n,int* B,int m,int X){

int sum=0;
int minDiff=INT_MAX;

int i=0;
int j=m-1;
int a,b;

while(i<n && j>0){

sum=A[i]+B[j];



if(abs(X-sum)<minDiff){
a=A[i];
b=B[j];
minDiff=abs(X-sum);
}

if(A[i]+B[j]<X){
i++;
}else{
j--;
}

}


printf("\nPair : %d %d",a,b);
}



int main(){


int A[]={1,4,5,7};
int B[]={10,20,30,40};

int n=sizeof(A)/sizeof(A[0]);
int m=sizeof(B)/sizeof(B[0]);

int X=32;

FindClosestPairSum(A,n,B,m,X);

return 0;
}
