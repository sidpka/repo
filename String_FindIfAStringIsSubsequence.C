#include<stdio.h>
#include<conio.h>
#include<string.h>

int FindIfSequence_Util(char str1[],char str2[]){


if(*str1 && !*str2){
return 0;
}else if( !*str1 && !*str2){
return 1;
}else if(!*str1){
return 1;
}

if(*str1==*str2){
return FindIfSequence_Util(str1+1,str2+1);
}
return FindIfSequence_Util(str1,str2+1);





}

int FindIfSubsequence(char str1[],char str2[]){

return FindIfSequence_Util(str1,str2);



}


int FindIfSubsequence2(char str1[],char str2[]){

int i;
int j;
int n=strlen(str2);
int m=strlen(str1);

for(i=0,j=0;i<n&j<m;i++){
if(str1[j]==str2[i]){
j++;
}

}

if(j==m){
return 1;
}
return 0;
}

int main(){


char str1[]="AXY";
char str2[]="ADXCPY";

//int result=FindIfSubsequence(str1,str2);
int result=FindIfSubsequence2(str1,str2);
if(result){
printf("\nYes");
}else{
printf("\No");
}


return 0;

}
