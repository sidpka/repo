#include<stdio.h>
#include<conio.h>

int CheckParity(int n){

int parity=0;

while(n){

parity=!parity;
n=(n&(n-1));

}

return parity;
}

int main(){

int n=13;

int parity=CheckParity(n);

printf("\nPress enter to check parity : ");
getch();
parity==1?printf("\nOdd"):printf("\nEven");


return 0;
}
