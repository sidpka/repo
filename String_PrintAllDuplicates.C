#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Char_Count 256

void FindDuplicates(char str[]){

int count[Char_Count];

int i;

for(i=0;i<Char_Count;i++){
count[i]=0;
}

for(i=0;str[i];i++){
count[str[i]]++;
}


printf("\nDuplicate letters with count :\n");

for(i=0;i<Char_Count;i++){
    if(count[i]>1){
printf("\n%c\t%d",i,count[i]);
    }
}




}

int main(){


char str[]="Siddharth";

FindDuplicates(str);





return 0;
}
