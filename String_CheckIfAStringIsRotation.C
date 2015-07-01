#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int FindRotation(char str1[],char str2[]){


int m=strlen(str1);
int n=strlen(str2);

if(m!=n){
return 0;
}

char* tmp=(char*)malloc(sizeof(char)*(m+n-1));
tmp[0]='\0';
strcat(tmp,str1);
strcat(tmp,str1);
//printf("%s",tmp);

char* ptr= strstr(tmp,str2);
free(tmp);
return ptr!=NULL;

}

int main(){


char str1[]="ABCD";
char str2[]="CDAB";

int result=FindRotation(str1,str2);

if(result){
printf("\n%s is rotation of %s",str2,str1);
}else{
printf("\nNo");
}






return 0;
}
