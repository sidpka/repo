#include<stdio.h>
#include<conio.h>
#include<math.h>


int max(int a,int b){


return a>b?a:b;

}

int min(int a,int b){
return a<b?a:b;
}

int gcd(int a,int b){

if(a%b==0){
return b;
}

return gcd(b,a%b);

}


void FindAllUnitFraction(int nr,int dr){

int tmp;
int div;
while(nr!=1){
tmp=ceil(float(dr)/float(nr));
//printf("%d",tmp);
printf("1/%d  ",tmp);

nr=(nr*tmp)-(dr);
dr=(dr*tmp);

div=gcd(max(dr,nr),min(dr,nr));
//printf("\ngcd is : %d",div);
nr/=div;
dr/=div;

}
printf("1/%d ",dr);




}



int main(){

int nr=6;
int dr=14;

FindAllUnitFraction(nr,dr);



return 0;
}
