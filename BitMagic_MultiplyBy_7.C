#include<stdio.h>
#include<conio.h>

int MultiplyBy7(int n){

return ((n<<3)-n);
}

int main(){

int n=2;

printf("\n%d multiplied by 7 gives : %d",n,MultiplyBy7(n));


return 0;
}
