#include<stdio.h>
#include<conio.h>

int CountBits(int num){

int count=0;

while(num){
count+=num&1;
num=num>>1;
}

return count;
}

int main(){


int num=9;

printf("\nNo of set bits : %d",CountBits(num));




return 0;
}
