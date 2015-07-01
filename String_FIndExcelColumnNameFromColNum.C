#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>


void Reverse(char str[]){


int i=0;
int j=strlen(str)-1;

while(i<j){
char tmp=str[i];
str[i]=str[j];
str[j]=tmp;
i++;
j--;
}


}

void FindColumnName(int colNo){
int n=colNo;
char str[100];

int i=0;

while(colNo){

int rem=colNo%26;
if(rem==0){
str[i++]='Z';
}else{
str[i++]=rem+'A'-1;
}
str[i]='\0';
colNo/=26;


}

Reverse(str);

printf("\nColNum : %d \t ColumnName : %s",n,str);






}


int main(){

int colNo=100;

FindColumnName(colNo);

return 0;

}
