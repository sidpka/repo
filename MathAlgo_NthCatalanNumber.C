#include<stdio.h>
#include<conio.h>

int FindCatalan(int n){

if(n<=1){
return 1;
}
//printf("\nhere");

int i;
int res=0;
for(i=0;i<n;i++){
res+=FindCatalan(i)* FindCatalan(n-i-1);
}

return res;
}

int FindCatalan2(int n,int k){

int res=1;

int i;

for(i=0;i<k;i++){
res*=(n-i);
res/=(i+1);

}


return res/(k+1);

}

int main(){

int n=5;
//FindCatalan(4);
//printf("\n%dth catalan number : %d",n,FindCatalan(n));
printf("\n%dth catalan number : %d",n,FindCatalan2(2*n,n));


return 0;
}
