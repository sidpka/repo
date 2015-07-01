#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


int cmp(const void* a,const void* b){


return ( *(char*)a- *(char*)b  );


}


void FindAllLexographic_Util(char str[],char buffer[],int index,int n){

if(index==n){
printf("\n%s",buffer);
return;
}

int len=strlen(str);

int i;

for(i=0;i<len;i++){

buffer[index]=str[i];

FindAllLexographic_Util(str,buffer,index+1,n);



}




}

void FindAllLexographic(char str[]){

int len=strlen(str);
char* buffer=(char*)malloc(sizeof(char)*(len+1) );

qsort(str,len,sizeof(char),cmp);
buffer[len]='\0';

FindAllLexographic_Util(str,buffer,0,len);


}


int main(){

char str[]="CBA";
printf("\nAll permutation in lexographic order :\n");
FindAllLexographic(str);





return 0;
}
