#include<stdio.h>
#include<conio.h>

int FindPower(int x,int y){


if(y==0){
return 1;
}

int tmp=FindPower(x,y/2);

if(y%2==0){
return tmp*tmp;
}else{
if(y>0){
return x*tmp*tmp;
}else{
return tmp*tmp/x;
}
}


}

int main(){

int x=2;
int y=3;

printf("\n%d ^ %d : %d",x,y,FindPower(x,y));





return 0;
}
