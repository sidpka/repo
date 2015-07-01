#include<stdio.h>
#include<conio.h>


int FindHorner(int poly[],int n,int x){

int res=0;

int i;

for(i=0;i<n-1;i++){

res=x*(poly[i]+res);
}
res+=poly[i];

return res;
}

int FindHorner2(int poly[],int n,int x){

int res=poly[0];

int i;

for(i=1;i<n;i++){
res=x*res+poly[i];
}


return res;
}

int main(){

//int poly[]={2,-6,2,-1};
//int x=3;

int poly[]={2,0,3,1};
int x=2;
int n=sizeof(poly)/sizeof(poly[0]);

printf("\nValue of expression : ");
int i;
for(i=0;i<n;i++){
printf("%d X^%d  ",poly[i],n-i-1);
}

printf(" : %d",FindHorner2(poly,n,x));


return 0;
}
