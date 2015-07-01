#include<stdio.h>
#include<conio.h>

int FindIfMultiple3(int n){


if(n<0){
n=-n;
}
if(n==0){
return 1;
}

if(n==1){
return 0;
}


int oddBitCount=0;
int evenBitCount=0;

int flag=1;

while(n){

if(flag&1){
oddBitCount+=n&1;
}else{
evenBitCount+=n&1;
}

n=n>>1;
flag=!flag;
}


int diff=oddBitCount-evenBitCount;
if(diff<0){
diff=-diff;
}




return FindIfMultiple3(diff);

}

int main(){

int n=612;

FindIfMultiple3(n)==1?printf("\nYes"):printf("\nNo");



return 0;
}
