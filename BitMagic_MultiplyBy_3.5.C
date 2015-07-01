#include<stdio.h>
#include<conio.h>

int FindMul3Point5(int n){

return ((n<<1)+n+(n>>1));


}

int main(){

int n=2;
printf("\n%d * 3.5 : %d",n,FindMul3Point5(n));


return 0;
}
