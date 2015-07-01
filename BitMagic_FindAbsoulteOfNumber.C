#include<stdio.h>
#include<conio.h>
#define CHAR_BIT 8

int FindAbs(int n){


int mask=n>>(sizeof(n)*CHAR_BIT -1);
/*
printf("\nMask is : %d",mask);
getch();
return (mask+n)^mask;
*/

//printf("%d",n);
int count=0;
printf("\nMask is : %d",mask);
int result=(n+mask);
printf("\nResult : %d",result);
getch();
while(count<=33){
    int x;
printf("\n%d    %d",n&1,mask&1);
n=n>>1;
mask=mask>>1;
count++;
}





getch();
}

int main(){

int n=-2;

printf("Absoulte val of : %d is : %d",n,FindAbs(n));



return 0;
}
