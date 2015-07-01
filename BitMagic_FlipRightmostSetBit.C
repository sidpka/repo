#include<stdio.h>
#include<conio.h>

int FindFlip(int n){

return n&(n-1);
}

int main(){

int n=12;

printf("\nUnsetting rightmost set bit : %d",FindFlip(n));


return 0;
}
