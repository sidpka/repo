#include<stdio.h>
#include<conio.h>
#include<string.h>


void FindRunLengthEncoding(char str[],int n){

char tmp[n];

int i;

int index=0;
i=0;
int j;
while(i<n){
tmp[index++]=str[i];
j=i+1;
while(str[j]==str[i]){
j++;
}
tmp[index++]=j-i+48;
i=j;
}

tmp[index]='\0';

printf("%s",tmp);




}

int main(){


char str[]="wwwwaaadexxxxxx";

int n=strlen(str);

FindRunLengthEncoding(str,n);




return 0;
}
