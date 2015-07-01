#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void BadCharHeuristic(char* pattern,int* lps){
int lenP=strlen(pattern);
//printf("\nLength is : %d",lenP);
int i,j;
for(i=0;i<256;i++){
lps[i]=-1;
}
for(i=0;i<lenP;i++){
lps[(int)pattern[i]]=i;
}


//printf("\nhere reaching");
}

int max(int a,int b){
return a>b?a:b;
}

void Boye_moore(char* text,char* pattern){

int lenT=strlen(text);
int lenP=strlen(pattern);

int* badChar=(int*)malloc(sizeof(int)*256);
//printf("\nHere here");
BadCharHeuristic(pattern,badChar);

int i,j;
i=0;

while(i<=lenT-lenP){
j=lenP-1;;
while(j>=0 && pattern[j]==text[i+j]){
j--;
}
if(j<0){
printf("\nPattern occurs at : %d",i);
i+=(i+lenP<lenT)?(lenP-badChar[(int)text[i+lenP]]):1;
}else{
i+=max(1,j-badChar[(int)text[i+j]]);
}
}
}

int main(){
char text[]="bacbabababacaca";
char pattern[]="ab";
Boye_moore(text,pattern);
getch();
return 0;
}
