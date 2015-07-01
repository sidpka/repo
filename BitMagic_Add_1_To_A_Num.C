#include<stdio.h>
#include<conio.h>

int FindSum(int n){

int i=0;
int m=n;

while(m&1){
i++;
m=m>>1;
}
int num=(1<<i);
//printf("\n%d",num);
n=n|num;
//printf("\n%d",n);

while(i){
n=n&(n-1);
i--;
}


return n;
}

int FindSum2(int n){

int m=1;

while(n & m){
n=n^m;
m=m<<1;
}

n=n^m;

return n;

}

int FindSum3(int n){

printf("%d",-(~(n)));


getch();
}

int main(){

int n=11;

//printf("%d + 1 : %d",n,FindSum(n));
//printf("%d + 1 : %d",n,FindSum2(n));
printf("%d + 1 : %d",n,FindSum3(n));



return 0;
}
