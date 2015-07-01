#include<stdio.h>
#include<conio.h>

void PrintReverse(char str[],int low,int n){

if(low==n){
return;
}

PrintReverse(str,low+1,n);


printf("%c",str[low]);


}

int main(){


char str[]="bunty";
int n=5;

PrintReverse(str,0,n);





return 0;
}
