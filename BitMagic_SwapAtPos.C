#include<stdio.h>
#include<conio.h>

int Swap(int num,int p1,int p2,int n){

int set1=(num>>p1)&((1<<n)-1);
//printf("\nSet1 : %d",set1);

int set2=(num>>p2)&((1<<n)-1);


int zor=set1^set2;

zor=(zor<<p1)|(zor<<p2);

return num^zor;





}

int main(){

int num=28;
int p1=0;
int p2=3;
int n=2;

printf("\nAfter swapping : %d",Swap(num,p1,p2,n));



return 0;
}
