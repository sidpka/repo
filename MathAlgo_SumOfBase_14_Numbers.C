#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int CharToInt(char ch){

if(ch>='0' && ch<='9'){
return ch-'0';
}

if(ch>='A' && ch <='D'){
return ch-'A'+10;
}


}

char IntToChar(int num){

if(num>=0 && num<=9){
return num+'0';
}

if(num>=10 && num<=14){
return num-10+'A';
}

}

char* FindSumBase14(char* num1,char* num2){

int len1=strlen(num1);

int len2=strlen(num2);

int carry=0;

char* res=(char*)malloc(sizeof(char)*(len1+2));

int i;
int n1;
int n2;
int sum;
res[len1+1]='\0';
for(i=len1-1;i>=0;i--){

n1=CharToInt(num1[i]);
n2=CharToInt(num2[i]);

sum=n1+n2+carry;

if(sum>=14){
carry=1;
sum=sum-14;
}else{
carry=0;
}

res[i+1]=IntToChar(sum);




}


if(carry==0){
return res+1;
}else{
res[0]='1';
return res;
}







}

int main(){


char *num1="12A";
char* num2="CD3";

char* result=FindSumBase14(num1,num2);

printf("\nSum is : %s",result);






return 0;
}
