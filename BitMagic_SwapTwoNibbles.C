#include<stdio.h>
#include<conio.h>

int SwapNibble(int n){

return ((n & (0x0F))<<4) | ( (n & (0xF0)) >>4 );

}

int main(){

int n=100;

printf("\n%d Swap Nibble : %d",n,SwapNibble(n));


return 0;
}
