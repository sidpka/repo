#include<stdio.h>
#include<string.h>

int main(){


char str[30];
char dest[50];

memset(str,'\0',sizeof(str));

strcpy(str,"sid");

printf("%s",str);

strcpy(dest,str);

printf("\n%s",dest);





return 0;
}


