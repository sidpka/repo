#include<stdio.h>
#include<conio.h>
#include<string.h>
#define CharCount 256


char* RemoveDuplicate(char str[]){


int count[CharCount];

int i;

for(i=0;i<CharCount;i++){
count[i]=0;
}

for(i=0;i<strlen(str);i++){
count[str[i]]++;
}

char tmp[strlen(str)];

int index=0;

for(i=0;i<strlen(str);i++){
if(count[str[i]]>=1){
tmp[index++]=str[i];
//printf("%c",i);
count[str[i]]=0;
}

}

tmp[index]='\0';
return tmp;


}
int main(){


char str[]="siddharth";

char* tmp=RemoveDuplicate(str);

printf("\n%s",tmp);



return 0;
}
