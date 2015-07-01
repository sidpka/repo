#include<stdio.h>
#include<conio.h>

int FindSquare(int n){

if(n==0){
return 0;
}

if(n<0){
n=-n;
}

int i;

int nFloor=n>>1;

if(n&1){
return (FindSquare(nFloor)<<2) + (nFloor << 2)+1;
}else{
return (FindSquare(nFloor)<<2);
}


}


int main(){

int n=5;
printf("\n%d ^ 2 : %d",n,FindSquare(n));


return 0;
}
