#include<stdio.h>
#include<conio.h>

int FindRussianPeasant(int a,int b){

int res=0;

while(b>0){

if(b&1){
res+=a;
}

a=a<<1;
b=b>>1;


}

return res;
}

int main(){

int a=20;
int b=12;
//multiply without using * operator
printf("\n%d * %d : %d",a,b,FindRussianPeasant(a,b));

return 0;
}
