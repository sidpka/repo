#include<stdio.h>
#include<conio.h>


int FindMul(int num1,int num2){

if(num2==0){
return 0;
}

if(num2>0){
return num1+FindMul(num1,num2-1);
}

if(num2<0){
return -FindMul(num1,-num2);
}


}

int main(){

int num1=11;
int num2=-5;

int result=FindMul(num1,num2);

printf("\n%d x %d : %d",num1,num2,result);

return 0;
}
