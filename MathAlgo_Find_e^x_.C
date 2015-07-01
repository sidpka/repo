#include<stdio.h>
#include<conio.h>



float FindExp(int n,float x){

int i;

float res=1;

for(i=n-1;i>0;i--){
res= (res*(x/float(i))) +1;

}


return res;

}

int main(){

float x=1.0;
int n=10;

printf("\ne^%f till term %d : %f",x,n,FindExp(n,x));






return 0;
}
