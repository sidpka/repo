#include<stdio.h>
#include<conio.h>
#include<string.h>

int PrintReverse(char str[],int i,int count){

if(str[i]==' ' || str[i]=='\0'){
return count+1;
}

int cnt=PrintReverse(str,i+1,count+1);
printf("%c",str[i]);

return cnt;
}


void FindRev(char* a,char* b){

char x;
while(a<b){
x=*a;
*a++=*b;
*b--=x;

}

}


void FindReverse(char str[],int n){

int i=0;

/*
while(i<n){

i+=PrintReverse(str,i,0);
printf(" ");
}

*/

char *tmp=str;

char *wordBegin=str;

while(*tmp){

tmp++;

if(*tmp=='\0'){
FindRev(wordBegin,tmp-1);
}else if(*tmp==' '){
FindRev(wordBegin,tmp-1);
wordBegin=tmp+1;
}

}

FindRev(str,tmp-1);

printf("%s",str);





}


void FindReverse2(char str[],int n){


char* wordStart=NULL;
char* tmp=str;


while(*tmp){

if(wordStart==NULL && *tmp!=' '){
wordStart=tmp;
}

if(wordStart && (*(tmp+1)==' ' || *(tmp+1)=='\0') ){
FindRev(wordStart,tmp);
wordStart=NULL;
}

tmp++;


}

FindRev(str,tmp-1);

printf("%s",str);

}

int main(){


char str[]="i like programming very much";

int n=strlen(str);

//FindReverse(str,n);

FindReverse2(str,n);







return 0;
}
