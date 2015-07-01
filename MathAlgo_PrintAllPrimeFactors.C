#include<stdio.h>
#include<conio.h>
#include<math.h>


void PrintAllPrimeFactors(int n){

while(n%2==0){
printf("%d  ",2);
n/=2;
}

int i;

for(i=3;i<=sqrt(n);i+=2){
while(n%i==0){
printf("%d  ",i);
n/=i;
}

}

if(n>2){
printf("%d  ",n);
}







}

int main(){

//int n=12;
//int n=100;
int n=1000;
printf("\nAll Prime Factors of : %d are : \n",n);
PrintAllPrimeFactors(n);





}
