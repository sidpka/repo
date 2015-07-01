#include<stdio.h>
#include<conio.h>

int FindPow(int x,int y){

int res=1;

while(y>0){

if(y&1){
res*=x;

}
x*=x;
y=y>>1;

}

return res;
}

int main(){

int x=3;
int y=5;

printf("\n%d ^ %d : %d",x,y,FindPow(x,y));



return 0;
}
