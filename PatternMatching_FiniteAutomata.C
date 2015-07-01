#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int BuildTFUtil(char* pattern,int len,int state,int x){

if(state<len && pattern[state]==x){
return state+1;
}

int ns;
int i;
for(ns=state;ns>0;ns--){
if(pattern[ns-1]==x){
for(i=0;i<ns-1;i++){
if(pattern[i]!=pattern[state-ns+i+1])
break;
}
if(i==ns-1){
return ns;
}
}
}
return 0;
}


void BuildTF(char* pattern,int len,int** TF){

int state;
int x;
for(state=0;state<=len;state++){
for(x=0;x<256;x++){
TF[state][x]=BuildTFUtil(pattern,len,state,x);
}
}
}

void FA(char* text,char* pattern){

int lenT=strlen(text);
int lenP=strlen(pattern);

int** TF=(int**)malloc(sizeof(int*)*(lenP+1));
int i;
for(i=0;i<lenP+1;i++){
TF[i]=(int*)malloc(sizeof(int)*256);
}

BuildTF(pattern,lenP,TF);
int state=0;
for(i=0;i<lenT;i++){
state=TF[state][text[i]];
if(state==lenP){
printf("\nFound at position : %d",i);
}
}

}

int main(){
char text[]="bacbabababacaca";
char pattern[]="ababac";
FA(text,pattern);
getch();
return 0;
}
