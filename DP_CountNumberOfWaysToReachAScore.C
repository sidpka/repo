#include<stdio.h>
#include<conio.h>

int FindCount(int n,int x,int y,int z){


int tmp[n+1];





int i;
for(i=1;i<=n;i++){
tmp[i]=0;
}
tmp[0]=1;

for(i=x;i<=n;i++){
tmp[i]+=tmp[i-x];
}

for(i=y;i<=n;i++){
tmp[i]+=tmp[i-y];
}

for(i=z;i<=n;i++){
tmp[i]+=tmp[i-z];
}

printf("\ntmp table count for differnet end scores :\n\n");

for(i=0;i<=n;i++){
printf("\n%d\t%d",i,tmp[i]);
}

printf("\n\nEnd\n\n");



return tmp[n];





}

int main(){


int  n=20;
int x=3;
int y=5;
int z=10;

printf("\nGiven Score that can be made : %d %d %d",x,y,z);

printf("\nNo of ways %d can be scored are : %d",n,FindCount(n,x,y,z));







return 0;
}
