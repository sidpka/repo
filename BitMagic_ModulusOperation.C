#include<stdio.h>
#include<conio.h>

int FindModulus(int n,int d){


return n&(d-1);


}

int main(){

int n=6;
int d=4;

printf("\n%d modulus %d : %d",n,d,FindModulus(n,d));


return 0;
}
