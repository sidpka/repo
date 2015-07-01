#include<stdio.h>
#include<conio.h>
#define N 4

int min(int a,int b){

return a<b?a:b;
}

int FindMinTime(int a[2][N],int t[2][N],int e[],int x[]){


int F[N];
int S[N];

F[0]=a[0][0]+e[0];
S[0]=a[1][0]+e[1];

int i;

for(i=1;i<N;i++){
F[i]=min(F[i-1]+a[0][i],S[i-1]+t[1][i]+a[0][i]);
S[i]=min(S[i-1]+a[1][i],F[i-1]+t[0][i]+a[1][i]);

}
//printf("\n%d",F[N-1]);
return min(F[N-1]+x[0],S[N-1]+x[1]);




}

int main(){

int a[2][N]={{4,5,3,2},{2,10,1,4} };
int t[2][N]={{0,7,4,5},{0,9,2,8} };
int e[]={10,12};
int x[]={18,7};

printf("\nMin time spent in maufacturing a car : %d",FindMinTime(a,t,e,x));







return 0;
}
