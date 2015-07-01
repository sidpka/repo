#include<stdio.h>
#include<conio.h>

char* RemoveAdjacent_Util(char str[],char* lastRemoved){


if(str[0]=='\0' || str[1]=='\0'){
return str;
}

if(str[0]==str[1]){
*lastRemoved=str[0];
while(str[1] && str[0]==str[1]){

str++;

}
str++;
return RemoveAdjacent_Util(str,lastRemoved);

}

char* remStr=RemoveAdjacent_Util(str+1,lastRemoved);

if(remStr[0] && remStr[0]==str[0]){
*lastRemoved=remStr[0];
return remStr+1;
}

if(remStr[0]=='\0'  && str[0]==*lastRemoved){
return remStr;
}

//reduces address of remaining string by 1 to accomodate str[0]
remStr--;
remStr[0]=str[0];

return remStr;



}

char* RemoveAdjacent(char str[]){

char lastRemoved='\0';
return RemoveAdjacent_Util(str,&lastRemoved);

}

int main(){

char str[]="geeksforgeeg";

printf("\n%s",RemoveAdjacent(str));






return 0;
}
