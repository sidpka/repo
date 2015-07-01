#include<stdio.h>
#include<conio.h>


int FindMod(int n,int d){

return n&(d-1);
}

int main(){

int n=19;
int d=4;

printf("%d mod %d : %d",n,d,FindMod(n,d));


return 0;
}
