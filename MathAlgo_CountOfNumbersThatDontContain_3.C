#include<stdio.h>
#include<conio.h>

int FindCount(int n){

if(n<3){
return n;
}

if(n>=3 && n<10){
return (n-1);
}

int po=1;

while(n/po>9){
po*=10;
}

int msd=n/po;

if(msd==3){
return FindCount(3*(po)-1);
}else{
return (FindCount(msd)*FindCount(po-1)+FindCount(msd)+FindCount(n% (po) ));
}


}

int main(){

int n=578;

printf("\nCount of numbers from 1 to %d that dont contains 3 : %d",n,FindCount(n));







return 0;
}
