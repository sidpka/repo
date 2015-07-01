#include<stdio.h>
#include<conio.h>
#include<string.h>



char* FindModified(char str1[],char str2[]){

int m=strlen(str1);
int n=strlen(str2);

int count[256];

int i;

for(i=0;i<256;i++){
count[i]=0;
}

for(i=0;i<n;i++){
count[str2[i]]=1;
}

char tmp[m];
int index=0;
for(i=0;i<m;i++){
if(!count[str1[i]]){
tmp[index++]=str1[i];
}
}


tmp[index]='\0';

return tmp;
}


int main(){


char str1[]="sid";
char str2[]="siddharth";

char* tmp=FindModified(str2,str1);

printf("%s",tmp);




return 0;
}
