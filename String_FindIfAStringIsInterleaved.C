#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindIfInterleaved_Util(char str1[],int len1,char str2[],int len2,char str3[],int len3){


if(len3==0){

if(len1==0 && len2==0){
return 1;
}else{
return 0;
}

}

int result;
if(str1[len1-1]==str3[len3-1]){
result=FindIfInterleaved_Util(str1,len1-1,str2,len2,str3,len3-1);
}
if(result==1){
return result;
}else{

if(str2[len2-1]==str3[len3-1]){
return FindIfInterleaved_Util(str1,len1,str2,len2-1,str3,len3-1);
}else{
return 0;
}

}

}

int FindIfInterleaved(char str1[],char str2[],char str3[]){


int len1=strlen(str1);
int len2=strlen(str2);
int len3=strlen(str3);

if(len1+len2!=len3){
return 0;
}

return FindIfInterleaved_Util(str1,len1,str2,len2,str3,len3);




}

int main(){


char str1[]="AB";
char str2[]="CD";

char str3[]="CDAB";

if(FindIfInterleaved(str1,str2,str3)){
printf("\nYes");
}else{
printf("\No");
}



return 0;
}
