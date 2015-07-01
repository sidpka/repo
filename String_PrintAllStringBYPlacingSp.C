#include<stdio.h>
#include<conio.h>
#include<string.h>


void FindAllString_Util(char str[],int i,char buffer[],int index){

if(!str[i]){

buffer[index]='\0';
printf("\n%s",buffer);
return;
}

buffer[index]=str[i];
FindAllString_Util(str,i+1,buffer,index+1);

if(str[i+1]){
buffer[index+1]=' ';
FindAllString_Util(str,i+1,buffer,index+2);
}


}


void FindAllString(char str[]){


int n=strlen(str);

char buffer[2*n];
buffer[2*n-1]='\0';


FindAllString_Util(str,0,buffer,0);




}

int main(){


char str[]="ABC";
FindAllString(str);






return 0;
}
