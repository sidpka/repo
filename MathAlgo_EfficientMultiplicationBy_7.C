#include<stdio.h>
#include<conio.h>


int FindMultiplyBy7(int num){


if(num<0){
return 0;
}

/*
int numX8=num<<3;

return numX8-num;
*/


//it does not evaluate num<<3 if bracket is not used and num<<3-num gives 0

return (num<<3)-num;


}

int main(){

int num=4;


//idea is to multiply by 8 and then subtract itself // n<<3 multiplies by 8 i.e left shift thrice and then subtract n
//same can be used to multiply by 9 (n<<3) + n


printf("\n%d x 7 : %d",num,FindMultiplyBy7(num));





return 0;
}
