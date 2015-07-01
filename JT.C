#include<stdio.h>

#include<string.h>
#include<stdlib.h>
#include<conio.h>

int main(){


char* a=(char*)malloc(sizeof(char)*10);
char* b;

printf("\nEnter string : ");

scanf("%s",a);

strcpy(b,a);
printf("\nCopied string : %s",b);
char c[2]="0";
strcat(b,a);
printf("\nC : %s",b);



/*

while(n--){
char* S1=DeQueue(queue);
printf("\n%s",S1);
strcpy(S2,S1);
printf("\nS2 : %s",S2);
strcat(S1,tmpZero);
printf("\nDone");
break;
EnQueue(queue,S1);
strcat(S2,tmpOne);
EnQueue(queue,S2);

}


*/



return 0;
}
