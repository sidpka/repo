#include<stdio.h>
#include<conio.h>



void PrintPrime(int prime[],int n){
int i;


for(i=2;i<n;i++){
if(!prime[i]){
printf("%d  ",i);
}
}
}




void FindPrime(int n){

int prime[n];

int i;

for(i=0;i<n;i++){
prime[i]=0;
}

int j;

for(i=2;i<n;i++){
    if(prime[i]==0){
for(j=2;j*i<n;j++){
prime[i*j]=1;
}
    }
}


PrintPrime(prime,n);

}


int main(){


int n=30;

printf("\nPress enter to see all prime numbers below : %d\n\n",n);


FindPrime(n);






return 0;
}
