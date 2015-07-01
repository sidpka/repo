#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Char_Max 256


int IfAnagram(int Scount[],int Pcount[]){

int i;

for(i=0;i<Char_Max;i++){
if(Scount[i]!=Pcount[i]){
return 0;
}
}

return 1;
}

void FindPattern(char str[],char pat[]){

int Scount[Char_Max];
int Pcount[Char_Max];

int i;

for(i=0;i<Char_Max;i++){
Scount[i]=0;
Pcount[i]=0;
}

int lenStr=strlen(str);
int lenPat=strlen(pat);

for(i=0;i<lenPat;i++){
Scount[ str[i] ]++;
Pcount[ pat[i] ]++;
}

for(i=lenPat;i<lenStr;i++){
if(IfAnagram(Scount,Pcount)){
printf("\nPattern\Anagram found at : %d",i-lenPat);
}
Scount[ str[i] ]++;
Scount[ str[i-lenPat] ]--;
}
if(IfAnagram(Scount,Pcount)){
printf("\nPattern\Anagram found at : %d",i-lenPat);
}


}

int main(){

char str[]="BACDGABCDA";

char pat[]="ABCD";

FindPattern(str,pat);




return 0;
}
