#include<stdio.h>
#include<conio.h>
#include<string.h>

void FindNEqualParts(char str[],int n,int parts){


int i;

if(n%parts!=0){
printf("\nInvalid input");
return;
}

for(i=0;i<n;i++){
if(i%parts==0){
printf("\n");
}
printf("%c",str[i]);
}





}

int main(){

char str[]="I_am_siddharth_pandey";

int n=strlen(str);
int parts=3;
FindNEqualParts(str,n,parts);




return 0;
}
