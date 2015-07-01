#include<stdio.h>
#include<conio.h>

int CheckSign(int a,int b){
return (a^b)<0;
}

int CheckSign2(int a,int b){
return ((a^b)>>31)&1;
}

int main(){

int a=-10;
int b=100;

//int result=CheckSign(a,b);
int result=CheckSign2(a,b);

result==1?printf("\nOpposite Sign"):printf("\nSame sign");



return 0;
}
