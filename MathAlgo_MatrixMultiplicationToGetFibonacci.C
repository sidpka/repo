#include<stdio.h>
#include<conio.h>

void MatrixMul(int M[2][2],int F[2][2]){

int x=M[0][0]*F[0][0]+M[0][1]*F[1][0];
int y=M[0][0]*F[0][1]+M[0][1]*F[1][1];
int w=M[1][0]*F[0][0]+M[1][1]*F[1][0];
int z=M[1][0]*F[0][1]+M[1][1]*F[1][1];

M[0][0]=x;
M[0][1]=y;
M[1][0]=w;
M[1][1]=z;

}

void Power(int M[2][2],int n){

if(n==0 || n==1){
return;
}

int F[2][2]={{1,1},{1,0}};

MatrixMul(M,F);

Power(M,n-1);

}

void Power2(int M[2][2],int n){
if(n==0 || n==1){
return;
}

int F[2][2]={{1,1},{1,0}};

Power2(M,n/2);
MatrixMul(M,M);

if(n&1){
MatrixMul(M,F);
}


}

int FindFib(int n){

int M[2][2]={{1,1},{1,0}};

//Power(M,n-1);
Power2(M,n-1); //log(n)

int i;
int j;

/*
for(i=0;i<2;i++){
for(j=0;j<2;j++){
printf("%d  ",M[i][j]);
}
printf("\n");
}
*/

return M[0][0];
}

int main(){

int n=4;

printf("\n%dth fibonacci number is : %d",n,FindFib(n));





return 0;
}
