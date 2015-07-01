#include<stdio.h>
#include<conio.h>

int CheckIfPowerOf2(int n){

if(n && !(n&(n-1))){
return 1;
}

return 0;

}

int main(){

int n=8;
int result=CheckIfPowerOf2(n);
printf("\nPress enter to check if %d is power of 2 : \n",n);
getch();
result==1?printf("\nYes"):printf("\No");


return 0;
}
