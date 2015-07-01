#include<stdio.h>
#include<conio.h>
#include<string.h>

void Swap(char* a,char* b){

char tmp;
tmp=*a;
*a=*b;
*b=tmp;

}

void PrintPermutation(char str[],int l,int h){
if(l==h){
   printf("%s\n",str);
return;
}

int i;


char tmp;

for(i=l;i<=h;i++){

Swap(&str[i],&str[l]);
//tmp=str[i];

/*
tmp=str[i];
str[i]=str[l];
str[l]=tmp;
*/

//printf("%c",str[i]);
PrintPermutation(str,l+1,h);
/*
tmp=str[i];
str[i]=str[l];
str[l]=tmp;
*/
Swap(&str[i],&str[l]);
}


}

int main(){


char str[]="sid";

int n=strlen(str);

PrintPermutation(str,0,n-1);



return 0;
}
