#include<stdio.h>
#include<conio.h>


int CheckDiv(int n){


if(n==0 || n==9){
return 1;
}

if(n < 9){
return 0;
}

return CheckDiv( (n>>3) - (n&7));

}

int main(){

int n=18;
int result=CheckDiv(n);

result==1?printf("\nDivisible"):printf("\nNot Divisible");



return 0;
}
