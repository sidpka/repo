#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindValidity(char str[]){


if(str[0]<65 || str[0]>90){
return 0;
}

int i=0;

while(str[i]){
if(str[i]==' ' && str[i+1]==' '){
return 0;
}
if( (str[i]>=65 && str[i]<=90) && (str[i+1]>=65 && str[i+1]<=90)){
return 0;
}

if( (str[i]>=65 && str[i]<=90 ) && i>0 && (str[i-1]!=' ') && (str[i-1]>=97 && str[i-1]<=122)){
return 0;
}

i++;
}
if(str[i-1]!='.'){
return 0;
}



return 1;
}

int main(){

char str[]="GeeksQuiz. is a quiz site.";
int result=FindValidity(str);

result==1?printf("\nValid"):printf("\nInvalid");

return 0;
}
