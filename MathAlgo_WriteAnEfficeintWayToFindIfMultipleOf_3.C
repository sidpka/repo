#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>


int FindIfMultipleOf3(int num){

int n=0;

while(num){
n+=num%10;
num/=10;
}


//printf("\n%d",n);

return n%3==0;


}

int FindIfMultipleOf3_Improved(int num){
/*
printf("\nHere");
*/
if(num<0){
num=-num;
}

if(num==0){
return 1;
}

if(num==1){
return 0;
}

int oddCount=0;
int evenCount=0;

while(num){

if(num&1){
oddCount++;
}

num=num>>1;

if(num&1){
evenCount++;
}

num=num>>1;

}


return FindIfMultipleOf3_Improved(abs(oddCount-evenCount));
}

int main(){


int number=612;

//int result=FindIfMultipleOf3(number);

int result=FindIfMultipleOf3_Improved(number);

result?printf("\nYes"):printf("\No");



/*
int x=4;

printf("%d",x);
x=x>>1;

printf("\n%d",x);

x=x>>1;

printf("\n%d",x);


//Right shift
x=x>>1;


//Left shift
x=x<<1
printf("\n%d",x);
*/


return 0;
}
