#include<stdio.h>
#include<conio.h>


void FindIndividualDigits(int n){

int div;
int rem=1;

int i;
//Upto 10 dcimal place

for(i=0;i<20;i++){
div=rem*10/n;
printf("%d",div);
rem=(rem*10)%n;
}


}

int FindPeriod(int n){

int rem=1;

int i;

for(i=1;i<=n+1;i++){
rem=(rem*10)%n;
}

int tmp=rem;

int count=0;

do{

rem=rem*10%n;
count++;

}while(rem!=tmp);

return count;


}

int main(){

int n=7;

printf("\nNumber of repeating digits in 1/%d : %d",n,FindPeriod(n));
//FindIndividualDigits(n);





return 0;
}
