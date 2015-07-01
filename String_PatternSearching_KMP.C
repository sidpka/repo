#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void FindLPS(char pattern[],int m,int* lps){


int i=1;
lps[0]=0;

int len=0;

while(i<m){

if(pattern[i]==pattern[len]){
len++;
lps[i]=len;
i++;
}else{
if(len!=0){
len=lps[len-1];
}else{
lps[i]=0;
i++;
}


}

}


}

void FindKMP(char text[],char pattern[]){


int n=strlen(text);
int m=strlen(pattern);

int i;
int j;

int *lps=(int*)malloc(sizeof(int)*m);

FindLPS(pattern,m,lps);
/*
for(i=0;i<m;i++){
printf("%d  ",lps[i]);
}

*/
i=0;
j=0;
while(i<n){

if(text[i]==pattern[j]){
i++;
j++;
}
if(j==m){
printf("\nPattern occurs at : %d",(i-j));
j=lps[j-1];
}
else if(i<n && pattern[j]!=text[i]){

if(j!=0){
j=lps[j-1];
}else{
i++;
}


}




}


}

int main(){

char text[]="AABAACAADAABAAABAA";

char pattern[]="AABA";

FindKMP(text,pattern);




return 0;
}
