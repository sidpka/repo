#include<stdio.h>
#include<conio.h>
#include<math.h>

int Find_BP(float prob){

int n=ceil(sqrt( 2*365* log(1/(1-prob))  )   );

return n;
}

int main(){

float prob=0.99999;

printf("\nThere should be %d people in room so that \nprobability that 2 people have same birthday is : %f",Find_BP(prob),prob);


return 0;
}
