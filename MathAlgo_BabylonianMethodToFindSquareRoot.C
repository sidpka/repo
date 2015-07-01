#include<stdio.h>
#include<conio.h>

int FindSquareRoot(int num){

int x=num;
int y=1;

while(x>y){


x=(x+y)/2;

y=num/x;

}

return x;
}

float FindSquareRoot2(float num){

float x=num;
float y=1;

float error=0.0000001;

while(x-y>error){
x=(x+y)/2;

y=num/x;

}

return x;

}

int main(){

//If perfect square

/*
int num=4;
int root=FindSquareRoot(num);

printf("\nSquare root of : %d is : %d",num,root);
*/

//If not prfct sqr

float num=111019;

float root=FindSquareRoot2(num);

printf("\nSquare root of : %f is : %f",num,root);

return 0;
}
