#include<stdio.h>
#include<conio.h>
#include<string.h>

void Swap(char* a,char* b){

char tmp=*a;
*a=*b;
*b=tmp;

}

void FindPermutation(char *str,int i,int n){

if(i==n){
printf("\n%s",str);
return;
}else{

int j;

for(j=i;j<=n;j++){
Swap(str+i,str+j);
FindPermutation(str,i+1,n);
Swap(str+i,str+j);

}

}



}

int main(){


char str[]="ABC";

int n=strlen(str);

FindPermutation(str,0,n-1);








return 0;
}
