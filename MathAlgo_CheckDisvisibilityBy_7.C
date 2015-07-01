#include<stdio.h>
#include<conio.h>


int IsDivisible(int n){

if(n<0){
n=-n;
}

if(n==0 || n==7){
return 1;
}

if(n<10){
return 0;
}

int a;
int b;

a=n/10;
b=(n-a*10);

//printf("\na: %d and b : %d",a,b);

return IsDivisible(a-2*b);





}

int main(){

int n=616;

int result=IsDivisible(n);

if(result){
printf("\n%d is divisible by 7",n);
}else{
printf("\nNot divisible");
}


return 0;
}
