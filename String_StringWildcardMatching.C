#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindIfMatching(char first[],char second[]){

if(*first=='\0' && *second=='\0'){
return 1;
}

if(*first=='*' && *(first+1)!='\0' && *second=='\0'){
return 0;
}

if(*first=='?' || *first==*second){
return FindIfMatching(first+1,second+1);
}

if(*first){

return FindIfMatching(first,second+1)|| FindIfMatching(first+1,second+1);

}


return 0;

}

int main(){


char first[]="g*ks";
char second[]="geeks";

FindIfMatching(first,second)==1?printf("\nYes"):printf("\nNo");


return 0;
}
