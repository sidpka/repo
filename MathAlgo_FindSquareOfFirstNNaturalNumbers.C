#include<stdio.h>
#include<conio.h>

void PrintSquares(int n){

int pSquare=0;

int i;

for(i=1;i<=n;i++){
pSquare=pSquare+i+(i-1);

printf("\nSq(%d)  :  %d",i,pSquare);
}



}

void PrintSquares2(int n){

int i;
int sum=0;
int odd=1;
for(i=1;i<=n;i++){
sum+=odd;
printf("\nSq(%d)  :%d",i,sum);
odd=odd+2;



}


}

int main(){

int n=10;


//PrintSquares(n);

PrintSquares2(n);


return 0;
}
