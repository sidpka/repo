#include<stdio.h>
#include<conio.h>

int SwapEvenOdd(int n){

int evenBits=n & (0xAAAAAAAA);

int oddBits=n& (0x55555555);

evenBits=evenBits>>1;
oddBits=oddBits<<1;

return evenBits | oddBits;


}

int main(){

int n=23;

printf("\nSwapping even n odd bits : %d",SwapEvenOdd(n));




return 0;
}
