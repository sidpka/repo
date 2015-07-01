#include<stdio.h>
#include<conio.h>


int GetNextHigher(int n){

int firstSet=n&(-n);
int nextHigher=n+firstSet;

int rightOnes=n^nextHigher;
rightOnes=rightOnes/firstSet;
rightOnes=rightOnes>>2;

return nextHigher|rightOnes;
}

int main(){

int n=12;

printf("\nNext higher number with same set bit count : %d",GetNextHigher(n));

return 0;
}
