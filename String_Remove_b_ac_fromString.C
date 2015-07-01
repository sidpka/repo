#include<stdio.h>
#include<conio.h>
#include<string.h>

void Remove(char str[]){

int n=strlen(str);

int i;
int j=0;
int state=1;

for(i=0;i<n;i++){

if(state ==1 && str[i]!='a' && str[i]!='b'){
str[j]=str[i];
j++;
}

if(state==2 && str[i]!='c'){
    str[j++]='a';
if(str[i]!='a' && str[i]!='b'){
str[j++]=str[i];
}

}

state=(str[i]=='a')?2:1;

}

if(state==2){
str[j++]='a';
}
str[j]='\0';


}

int main(){


char str[]="aaaac";

Remove(str);

printf("\n%s",str);



return 0;
}
