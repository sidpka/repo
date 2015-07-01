#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


char *Substring(char str[],int position,int len){

char* pointer=(char*)malloc(sizeof(char)*(len+1));


int c;

for(c=0;c<len;c++){
pointer[c]=str[position+c-1];
}
pointer[c]='\0';
return pointer;




}

void FindSubstring(char str[],int len){

int pos=1;
char sub[len+1];

int length=1;
int tmp=len;
while(pos<=len){

while(length<=tmp){
char* pointer=Substring(str,pos,length);
printf("\n%s",pointer);
free(pointer);
length++;
}
pos++;
length=1;
tmp--;
}

}

int main(){

char str[]="the";

int len=strlen(str);
FindSubstring(str,len);

return 0;
}
