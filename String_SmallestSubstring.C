#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<limits.h>


int FindMinLengthSubstring(char str1[],char str2[]){

int n=strlen(str1);
int m=strlen(str2);

int count[26];
int minLen=INT_MAX;
int i;
int j;

int k;
int tmp[26];
for(j=0;j<26;j++){
count[j]=0;
}

for(j=0;j<m;j++){
count[str2[j] -'a']++;
}

int cnt;

for(i=0;i<n;i++){

cnt=m;

for(j=0;j<26;j++){
tmp[j]=count[j];
}

for(k=i;k<n;k++){

if(tmp[str1[k]-'a']){
cnt--;
tmp[str2[k]-'a']--;
}

if(cnt==0){
break;
}
}

if(cnt==0 && (k-i+1) <minLen){
minLen=k-i+1;
printf("\nMin len : %d",minLen);
}



}

printf("\nHere : %d",minLen);
return minLen;
}

int main(){

char str1[]="this is a test string";
char str2[]="tist";


int result=FindMinLengthSubstring(str1,str2);

if(result==INT_MAX){
printf("\nNot present");
}else{
printf("\nMin Length substring : %d",result);
}


return 0;
}
