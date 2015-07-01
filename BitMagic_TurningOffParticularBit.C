#include<stdio.h>
#include<conio.h>

int TurnOff(int n,int k){

int mask=~(1<<(k-1));

return n&mask;

}

int main(){

int n=15;
int k=3;

printf("\n%d",TurnOff(n,k));






return 0;
}
