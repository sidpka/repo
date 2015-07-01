#include<stdio.h>
#include<conio.h>

void DecToBin(int n){

unsigned int i;

for(i=1<<31;i>0; i=i>>1){
 n&i?printf("1"):printf("0");
}


}

int main(){

int n=25;

printf("\nPress enter to see binary rep of %d\n\n",n);
getch();
DecToBin(n);

return 0;
}
