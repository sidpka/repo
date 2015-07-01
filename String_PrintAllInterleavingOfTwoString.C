#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


void FindAllInterleaving_Util(char str1[],int start1,int len1,char str2[],int start2,int len2,char buffer[],int index){

if(index==len1+len2){
printf("\n%s",buffer);
return;
}

if(start1<len1){
buffer[index]=str1[start1];
FindAllInterleaving_Util(str1,start1+1,len1,str2,start2,len2,buffer,index+1);
}

if(start2<len2){
buffer[index]=str2[start2];
FindAllInterleaving_Util(str1,start1,len1,str2,start2+1,len2,buffer,index+1);
}



}


void FindAllInterleaving(char str1[],char str2[]){

int len1=strlen(str1);
int len2=strlen(str2);

char* buffer=(char*)malloc(sizeof(char)* (len1+len2+1));

buffer[len1+len2]='\0';

FindAllInterleaving_Util(str1,0,len1,str2,0,len2,buffer,0);





}

int main(){

char str1[]="AB";
char str2[]="CD";

printf("\nAll interleaving \n");

FindAllInterleaving(str1,str2);




return 0;
}
