#include<stdio.h>
#include<conio.h>
#include<string.h>

void FindPattern(char text[],char pattern[]){

int n=strlen(text);
int m=strlen(pattern);

int i;
int j;


for(i=0;i<n-m+1;i++){

for(j=0;j<m;j++){
if(text[i+j]!=pattern[j]){
break;
}
}

if(j==m){
printf("\nPattern found at : %d",i);
}

else if(j!=0){
i+=j;
}



}




}

int main(){


char text[]="ABCEABCDABCEABCD";

char pattern[]="ABCD";

FindPattern(text,pattern);





return 0;
}
