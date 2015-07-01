#include<stdio.h>
#include<conio.h>

int Fib(int n){

int fi[n+1];

int i;

fi[0]=0;
fi[1]=1;

for(i=2;i<=n;i++){
fi[i]=fi[i-1]+fi[i-2];
}

return fi[n];
}

int Fib1(int n){

if(n==0){
return 0;
}

if(n==1){
return 1;
}

return Fib1(n-1)+Fib1(n-2);


}


//int fi[21]={0};
int Fib2(int* fi,int n){
if(n==0){
return 0;
}

if(n==1){
return 1;
}

if(!fi[n]){
return fi[n]=Fib2(fi,n-1)+Fib2(fi,n-2);
}else{
return fi[n];
}




}

int main(){

int n=20;

printf("\nPress enter to find Find Fibonacci using naive approach :\n");
getch();
printf("\nFibonacci %d is : %d",n,Fib1(n));

printf("\nPress enter to find Find Fibonacci using Bottom up approach :\n");
getch();
printf("\nFibonacci %d is : %d",n,Fib(n));

printf("\nPress enter to find Find Fibonacci using Top down approach :\n");
getch();
int fi[21]={0};
printf("\nFibonacci %d is : %d",n,Fib2(fi,n));


return 0;
}
