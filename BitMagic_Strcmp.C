#include<stdio.h>
#include<conio.h>
#include<string.h>

int Strcmp(char a[],char b[]){

int i;

if(strlen(a)!=strlen(b)){

printf("\nInvalid");
return -5;
}

int len=strlen(a);
for(i=0;i<len;i++){
if( (a[i]==b[i]) || ( (a[i] ^ 32 )==b[i] ) ){
continue;
}else{
break;
}
}

if(a[i]==b[i]){
return 0;
}else if(  (a[i] | 32)<(a[i]|32)){
return -1;
}

return 1;
}

int main(){

char a[]="ABCD";
char b[]="abcd";

int result=Strcmp(a,b);

printf("\n%d",result);


return 0;
}
