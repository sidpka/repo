#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define max 9999

int FindNextWordLength(char words[],int i){
if(words[i]==' '){
i=i+1;
}

int j=i;

int len=0;

while(words[j]!=' '){
    if(words[j]=='\0'){
    break;
    }
len++;
j++;
}

//printf("\nReaching here : len %d",len);

return len;
}


void PrintWord(char words[],int i,int len){

int j;

for(j=i;j<len;j++){
printf("%c",words[j]);
}


}


void FindWordWrap(char words[],int n,int m){


int i;
i=0;
int flag=0;
int wordLen;
int currentLineWidth;
while(i<n){
printf("\nMain Loop\n");
currentLineWidth=0;

while(currentLineWidth<=m){
wordLen=FindNextWordLength(words,i);
//printf("\nSubllop\n");
if(currentLineWidth+wordLen<=m){
currentLineWidth+=wordLen;
//PrintWord(words,i,wordLen);
int k=i;
while(words[k]!=' '){
printf("%c",words[k]);
k++;
}
//for(k=i;k<wordLen;k++){
//printf("%c",words[k]);
//}
i+=wordLen+1;
if(i>=n){

flag=1;}
//printf("\ni is : %d",i);
if(currentLineWidth<m){
printf(" ");
}
}else{
printf("\n");
if(i>=n){
flag=1;
}

break;
}

}

if(flag==1){
break;
}

//break;

}




}

int main(){


char words[]="Geeks for geeks presents word wrap problem";

int m=15;

int n=strlen(words);

//

FindWordWrap(words,n,m);












return 0;
}
