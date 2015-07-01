#include<stdio.h>
#include<conio.h>


int FindBF(int n,int k){

int res=1;

if(k>(n-k)){
k=n-k;
}

int i;

for(i=0;i<k;i++){
res*=(n-i);
res/=(i+1);
}

return res;

}

int main(){

int n=5;
int k=2;

printf("\nBinomial coefficeint %d C %d : %d",n,k,FindBF(n,k));



return 0;
}
