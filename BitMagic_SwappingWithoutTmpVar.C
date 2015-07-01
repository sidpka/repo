#include<stdio.h>
#include<conio.h>

void Swap(int* a,int* b){
if(*a == *b){
return;
}
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;

}


void Swap2(int * a,int * b){
if(*a == *b){
return;
}
*a=(*a) * (*b);
*b=(*a)/(*b);
*a=(*a)/(*b);



}

void Swap3(int* a,int* b){
if(*a == *b){
return;
}
*a=(*a)^(*b);
*b=(*a)^(*b);
*a=(*a)^(*b);

}

int main(){

int a=20;
int b=20;
Swap3(&a,&a);
printf("\na: %d  b : %d",a,b);



return 0;
}
