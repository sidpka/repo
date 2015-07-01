#include<stdio.h>
#include<conio.h>

int Diff(int x,int y){

int borrow=0;

while(y){
borrow=(~x)&y;
x=x^y;
y=borrow<<1;

}

return x;
}

int main(){

int x=7;
int y=4;

printf("\n%d - %d : %d",x,y,Diff(x,y));



return 0;
}
