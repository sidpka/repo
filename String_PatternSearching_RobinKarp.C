#include<stdio.h>
#include<conio.h>
#include<string.h>
#define d 256


void FindRobinKarp(char text[],char pattern[],int  q){


int n=strlen(text);
int m=strlen(pattern);

int p=0;
int t=0;

int h=1;

int i;
int j;

for(i=0;i<m-1;i++){
h=(h*d)%q;
}
//printf("%d",h);

for(i=0;i<m;i++){
p=(p*d + pattern[i])%q;
t=(t*d+text[i])%q;
}

/*
printf("\nP is : %d",p);
printf("\nT is : %d",t);
*/

for(i=0;i<(n-m+1);i++){
if(p==t){

for(j=0;j<m;j++){
if(pattern[j]!=text[i+j]){
break;
}
}
if(j==m){
printf("\nPattern found at : %d",i);
}

}

if(i<n-m){
t=(d*(t- h*text[i]) + text[i+m] )%q;
if(t<0){
t+=q;
}
}
}





}


int main(){


char text[]="AABAACAADAABAAABAA";

char pattern[]="AABA";

int q=101;

FindRobinKarp(text,pattern,q);






return 0;
}
