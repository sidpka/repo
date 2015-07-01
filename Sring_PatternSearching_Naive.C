#include<stdio.h>
#include<conio.h>
#include<string.h>

void FindPatternOccurance(char text[],char pattern[]){

int n=strlen(text);
int m=strlen(pattern);

int i;
int j;

for(i=0;i<(n-m+1);i++){

for(j=0;j<m;j++){
if(text[i+j]!=pattern[j]){
break;
}
}
if(j==m){
printf("\nPattern found at : %d",i);
}

}


}

int main(){

char text[]="AABAACAADAABAAABAA";

char pattern[]="AABA";

FindPatternOccurance(text,pattern);







return 0;
}
