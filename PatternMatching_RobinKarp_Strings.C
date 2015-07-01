#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define d 256
int main(){

char text[]="My name is siddharth";
char pattern[]="siddharth";
int q=101;
int h=1;
int t=0;
int p=0;
int i;
int j;
int lenT=strlen(text);
int lenP=strlen(pattern);
for(i=0;i<lenP-1;i++){
h=(h*d)%q;
}
for(i=0;i<lenP;i++){
p=(p*d +pattern[i])%q;
t=(t*d+text[i])%q;
}

for(i=0;i<=lenT-lenP;i++){
if(p==t){

for(j=0;j<lenP;j++){
if(pattern[j]!=text[i+j]){
break;
}
}
if(j==lenP){
printf("\nPattern found at : %d",i);
}
}
if(i<lenT-lenP){
t=(d*(t-text[i]*h)+ text[i+lenP])%q;
}
if(t<0){
t=t+q;
}
}
}
