#include<stdio.h>
#include<conio.h>



int FindCount(int n){

int coun=0;

int i;
for(i=5;n/i>=1;i*=5){
coun+=n/i;
}


return coun;
}

int main(){

int n=100;

printf("\nNo of trailing 0s in %d! : %d",n,FindCount(n));





return 0;
}
