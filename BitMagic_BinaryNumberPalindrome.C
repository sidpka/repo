#include<stdio.h>
#include<conio.h>
#include<math.h>



int CheckBitAt(int n,int pos){

return (n& (1<<pos)) ?1:0;
}


int CheckIfPalindrome(int n){

int left=log2(n);
//printf("\nLeft : %d",left);

int right=0;
/*
printf("\nAt %d : %d",left,CheckBitAt(n,left));
printf("\nAt %d : %d",right,CheckBitAt(n,right));
printf("\nAt %d : %d",1,CheckBitAt(n,1));
getch();
*/
while(right <left){
if(CheckBitAt(n,right) !=CheckBitAt(n,left)){
return 0;
}
left--;
right++;
}

return 1;
}

int main(){

int n=12;

int result=CheckIfPalindrome(n);

result==1?printf("\nPalindrome"):printf("\nNot a palindrome");


return 0;
}
