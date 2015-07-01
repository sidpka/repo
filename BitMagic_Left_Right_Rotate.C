#include<stdio.h>
#include<conio.h>
#define INT_BIT 32

int LeftRotate(int n,int d){

return (n<<d)|(n>>(INT_BIT-d));
}

int RightRotate(int n,int d){


return (n>>d)|(n<<(INT_BIT-d));
}

int main(){

int n=16;
int d=2;

printf("%d",LeftRotate(n,d));
printf("\n%d",RightRotate(n,d));


return 0;
}
