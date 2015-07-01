#include<stdio.h>
#include<conio.h>

int Divide(int a,int b){

while(a%b==0){
a=a/b;
}

return a;

}

int IsUgly(int n){


n=Divide(n,2);
n=Divide(n,3);
n=Divide(n,5);

if(n==1){
return 1;
}

return 0;
}


int FindUglyNumber(int n){

int i=1;
int count=1;

while(n>count){
i++;

if(IsUgly(i)){
count++;
}

}

return i;






}


int min(int a,int b){

return a<b?a:b;
}


int FindUglyNumber_DP(int n){

int i2=0;
int i3=0;
int i5=0;

int i;

int dp[n];
dp[0]=1;

int m2=dp[i2]*2;
int m3=dp[i3]*3;
int m5=dp[i5]*5;

int nextUgly;

for(i=1;i<n;i++){

nextUgly=min(m2,min(m3,m5));

dp[i]=nextUgly;

if(nextUgly==m2){
i2=i2+1;

m2=dp[i2]*2;
}

if(nextUgly==m3){
i3=i3+1;

m3=dp[i3]*3;
}

if(nextUgly==m5){
i5=i5+1;
m5=dp[i5]*5;
}


}




return nextUgly;

}

int main(){

int n=150;

//printf("\n%dth ugly number is : %d",n,FindUglyNumber(n));

printf("\n%dth ugly number is : %d",n,FindUglyNumber_DP(n));




return 0;
}
