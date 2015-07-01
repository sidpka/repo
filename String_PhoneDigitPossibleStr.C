#include<stdio.h>
#include<conio.h>
#include<string.h>

void FindPossibleString_Util(char* str[],int num[],int n,char buffer[],int indx){

if(indx==n){
printf("\n%s",buffer);
return;
}

int i;

for(i=0;i<strlen(str[num[indx]] );i++){

buffer[indx]=str[num[indx]][i];
FindPossibleString_Util(str,num,n,buffer,indx+1);
if(num[indx]==0 || num[indx]==1){
return;
}
}



}

void FindPossibleString(char* str[],int num[],int n){

char buffer[n+1];
buffer[n]='\0';

FindPossibleString_Util(str,num,n,buffer,0);




}

int main(){


char *str[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

int num[]={2,3,4};

int n=sizeof(num)/sizeof(num[0]);

FindPossibleString(str,num,n);



return 0;
}
