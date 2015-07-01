#include<stdio.h>
#include<conio.h>

int CheckIfPowerOf_4(int n){

if(n && !(n&(n-1))){
int count=0;

while(n>1){
count++;
n=n>>1;
}
if(!(count&1)){
return 1;
}
}

return 0;
}

int main(){

int n=16;

int result=CheckIfPowerOf_4(n);
result==1?printf("\n%d is Power of 4",n):printf("\n%d is not power of  4",n);



return 0;
}
