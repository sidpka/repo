#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>



int max(int a,int b){

return (a>b)?a:b;
}

char* GetSum(char a[],char b[]){

//int len=MakeLen(a,b);

int len1=strlen(a);
int len2=strlen(b);

int len=max(len1,len2)+1;

char* first=(char*)malloc(sizeof(char)*len);
char* second=(char*)malloc(sizeof(char)*len);
first[len]='\0';
second[len]='\0';
int i;
if(len1<len2){
for(i=0;i<(len2-len1);i++){
first[i]='0';
}
for(;i<len;i++){
first[i]=a[i-len1];
}
}else{

for(i=0;i<len;i++){
first[i]=a[i];
}
}

if(len1>len2){
for(i=0;i<(len1-len2);i++){
second[i]='0';
}
for(;i<len;i++){
second[i]=b[i-len2];
}
}else{
for(i=0;i<len;i++){
second[i]=b[i];
}
}

printf("\n%s\n%s",first,second);

getch();

}

int main(){

char a[]="1100011";
char b[]="10";

printf("\nResult : %s",GetSum(a,b));



return 0;
}
