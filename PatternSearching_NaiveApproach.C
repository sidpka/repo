#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void PopulateLPS(char* pattern,int* lps){
int lenP=strlen(pattern);
//printf("\nLength is : %d",lenP);
int i,j;

lps[0]=0;
i=1;
j=0;
while(i<lenP){
if(pattern[i]==pattern[j]){
lps[i]=j+1;
i++;
j++;
}
else if(j>0){
j=lps[j-1];
}else{
lps[i]=0;
i++;
}
}
//printf("\nhere reaching");
}

int KMP(char* text,char* pattern){

int lenT=strlen(text);
int lenP=strlen(pattern);

int* lps=(int*)malloc(sizeof(int)*lenP);
//printf("\nHere here");
PopulateLPS(pattern,lps);



int i,j;

/*
printf("\nlps\n\n");
for(i=0;i<lenP;i++){
printf("%d  ",lps[i]);
}
printf("\n\n");
*/

i=0;
j=0;
while(i<lenT){
if(text[i]==pattern[j]){
if(j==lenP-1){
return i-j;
}else{
i++;
j++;
}
}else if(j>0){
j=lps[j-1];
}else{
i++;
}

}
return -1;
}

int main(){

char text[]="bacbabababacaca";
char pattern[]="ababaca";

int result=KMP(text,pattern);
if(result==-1){
printf("\nPattern not found in the text");
}else{
printf("\nPattern found after %d shifts",result);
}
getch();
return 0;
}
