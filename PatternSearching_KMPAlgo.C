#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int main(){

char text[]="Hey my name is Siddharth Siddharth!";
char pattern[]="Siddharth";

int i;
int lenT=strlen(text);
int lenP=strlen(pattern);
int j;

for(i=0;i<lenT-lenP;i++){
int flag=1;
for(j=0;j<lenP;j++){
if(text[i+j]!=pattern[j]){
flag=0;
break;
}
}
if(flag){
printf("\nFound at location : %d",i);
}
}





return 0;
}
