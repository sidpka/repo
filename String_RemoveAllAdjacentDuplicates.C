#include<stdio.h>
#include<conio.h>
#include<string.h>

void RemoveAdjacentDuplicate(char str[]){

int i;

int j=0;

for(i=1;str[i];i++){

if(str[i-1]!=str[i]){

if(j==0){
str[j++]=str[i-1];
}else{
if(str[j-1]!=str[i-1]){
    //printf("\nHere for : %c",str[i]);
str[j++]=str[i-1];
}else{
j--;
}

}
}else{
i++;
}


}

if(str[i-2]!=str[i-1] && str[i-1]!=str[j-1]){
str[j++]=str[i-1];
}else if(str[i-1]==str[j-1]){
j--;
}

str[j]='\0';





}

void RemoveAdjacentDuplicate2(char str[]){


int i=1;
int j=0;

for(i=1;str[i];i++){

if(str[i]!=str[i-1]){

if(j==0){
str[j++]=str[i-1];
}else if(str[i-1]!=str[j-1]){
str[j++]=str[i-1];
}else{
j--;
}
}else{
i++;
}
}

if(i==strlen(str)){

if(j==0){
str[j++]=str[i-1];
}else if(str[i-1]!=str[j-1]){
str[j++]=str[i-1];
}else{
j--;
}


}

str[j]='\0';






}

int main(){

//char str[]="azxxzy";
char str[]="acaaabbbacdddd";
RemoveAdjacentDuplicate2(str);


printf("\n%s",str);




return 0;
}
