#include<stdio.h>
#include<conio.h>

int Sum(int a,int b){

int carry=0;

while(b!=0){
carry= a&b;
a=a^b;
b=carry<<1;
}

return a;
}

int main(){

int a=2;
int b=3;

printf("\n%d + %d : %d",a,b,Sum(a,b));

return 0;
}
