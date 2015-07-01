#include<stdio.h>
#include<conio.h>
#include<math.h>

int CheckPosition(int n){

int pos=1;
while(n){
if(n&1){
return pos;
}
pos++;
n=n>>1;

}

}

int CheckPosition2(int n){

// when we take 2's complement of the number all bits are reverted except the first bit from right to left
//e.g 12 (1100) . 1's complement  : 0011 , 2's complement : 0100
//and  2's compelnet of n is : -n
// so n&(-n): 100

return log2(n & (-n))+1;




}

int main(){

int n=18;

//printf("\nPosition of first 1 in binary of %d is : %d",n,CheckPosition(n));
printf("\nPosition of first 1 in binary of %d is : %d",n,CheckPosition2(n));



return 0;
}
