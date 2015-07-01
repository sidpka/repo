#include<stdio.h>
#include<conio.h>
#include<math.h>

int IsPerfectSquare(int x){

int n=sqrt(x);

return x==n*n;
}

int FindIfFibonacci(int n){

return IsPerfectSquare(5*(n*n)+4)||IsPerfectSquare(5*(n*n)-4);
}

int main(){


int n=5;

int result=FindIfFibonacci(n);
result==1?printf("\nYes"):printf("\nNo");





return 0;
}
