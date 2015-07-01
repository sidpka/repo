#include<stdio.h>
#include<conio.h>
#include<string.h>

int dp[3];

void FindCount(char str[],int i,int n,int* count){
if(!str[i]){
(*count)++;
return;
}

if(str[i+1]!='\0' && (str[i]-'0' <=2 && str[i+1]-'0' <=6) ){

FindCount(str,i+2,n,count);
}

FindCount(str,i+1,n,count);


}


int FindCount2(char str[],int i,int n,int* count){
if(!str[i]){
(*count)++;
return;
}


}


int main(){

char str[]="123";
int n=sizeof(str);
int count=0;
//FindCount(str,0,n,&count);

FindCount2(str,0,n,&count);

printf("\nCount : %d",count);

return 0;
}
