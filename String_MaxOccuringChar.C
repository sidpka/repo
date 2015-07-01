#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Number_Of_Chars 256

char FindMaxChar(char str[]){

int n=strlen(str);

int count[Number_Of_Chars];

int i;

for(i=0;i<Number_Of_Chars;i++){
count[i]=0;
}

for(i=0;i<n;i++){
count[str[i]]++;
}

int max=0;
char maxChar;

for(i=0;i<Number_Of_Chars;i++){
if(count[i]>max){
maxChar=i;
max=count[i];
}
}


return maxChar;



}

int main(){

char str[]="memme";

printf("\nMax occuring char is : %c",FindMaxChar(str));



return 0;
}
