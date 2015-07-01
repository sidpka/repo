#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int GenerateInt(char* text,int len){
int i;

int value=0;
for(i=0;i<len;i++){
value=value*10;
value=value+(text[i]-'0');
}
//printf("\nIn generate value is : %d",value);
return value;
}


int main(){

char text[]="12345";
char pattern[]="45";
int lenP=strlen(pattern);
//printf("\nLength of pattern is : %d",lenP);
int p=GenerateInt(pattern,lenP);
//printf("\np is : %d",p);
getch();
int lenT=strlen(text);
int i;
int tmp;
for(i=0;i<=lenT-lenP;i++){
    tmp=GenerateInt(text+i,lenP);
    //printf("\n\nbis is : %d",tmp);
if(tmp==p){
printf("\nPattern found after %d shifts ",i);
}
}









return 0;
}
