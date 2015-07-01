#include<stdio.h>
#include<conio.h>

int ReverseBits(int n){

int NO_OF_BITS=sizeof(n)*8;
printf("\nNo of bits : %d",NO_OF_BITS);
int rn=0;

int i;

for(i=0;i<NO_OF_BITS;i++){

if(n&1){
rn |=(1<< (NO_OF_BITS-1-i));
}
n=n>>1;
//printf("\nrn is : %d",rn);
}


return rn;


}

unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
   }
   //printf("\nReverse : %d",reverse_num);
    return reverse_num;

}

int main(){

int n=2;

//printf("\nNumber of bytes in %d : %d",n,sizeof(n));

printf("\nPress enter to reverse bits of %d",n);
getch();

int rn=ReverseBits(n);
int rn1=reverseBits(n);

printf("\n%d\n%d",rn,rn1);

return 0;
}
