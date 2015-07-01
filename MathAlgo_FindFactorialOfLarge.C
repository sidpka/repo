#include<stdio.h>
#include<conio.h>
#define max 200



void FindFactorial(int n){

int arr[max];
int size=1;
arr[0]=1;

int i;
int j;
int carry=0;
int prod;
int tmp;
for(i=2;i<=n;i++){
carry=0;
for(j=0;j<size;j++){
tmp=(arr[j]*i+carry);
arr[j]=tmp%10;
carry=tmp/10;
}

while(carry){
arr[size++]=carry%10;
carry/=10;
}


}


printf("\nFactorial of %d is :\n",n);

for(i=size-1;i>=0;i--){
printf("%d",arr[i]);
}


}

int main(){

int n=100;
FindFactorial(n);



return 0;
}
