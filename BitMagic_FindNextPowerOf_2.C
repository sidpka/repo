#include<stdio.h>
#include<conio.h>
#include<math.h>

int FindNextPower(int n){
int p=log2(n);

//printf("\n%d",p);
//getch();

return pow(2,p+1);



}

int FindNextPower2(int n){

int count=0;

if(n & !(n & (n-1))){
return n;
}

while(n){
count++;
n=n>>1;
}
//printf("\n%d",count);

return (1<<count);
}


int FindNextPower3(int n){

n=n|(n>>1);
n=n|(n>>2);
n=n|(n>>4);
n=n|(n>>8);
n=n|(n>>16);

return n+1;

}

int main(){

int n=16;
//printf("\nNext power of 2 of %d is : %d",n,FindNextPower(n));
//printf("\nNext power of 2 of %d is : %d",n,FindNextPower2(n));
printf("\nNext power of 2 of %d is : %d",n,FindNextPower3(n));


return 0;
}
