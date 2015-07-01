#include<stdio.h>
#include<conio.h>
#include<string.h>



int FindIfMultiple(int a[],int b[]){

int multiple=-1;

int i;

for(i=0;i<26;i++){
if(a[i]!=0 && multiple==-1 && b[i]!=0){
multiple=a[i]/b[i];
}else if(a[i]!=0 && b[i]==0){
return 0;
}else if(a[i]==0 && b[i]!=0){
return 0;
}else if(a[i]!=multiple*b[i]){
return 0;
}
}

return 1;

}


int FindIfTrue(char str[]){

int n=strlen(str);

int countStr[26]={0};

int i;

/*
for(i=0;i<26;i++){
printf("%d ",countStr[i]);
}
*/

for(i=0;i<n;i++){
countStr[str[i]-'a']++;
}
/*
for(i=0;i<26;i++){
printf("%d ",countStr[i]);
}
*/
int j;
int k;
for(i=0;i<n/2;i++){

for(j=i;j<n/2;j++){
  int countSub[26]={0};
for(k=i;k<=j;k++){
countSub[str[k]-'a']++;
}
if(FindIfMultiple(countStr,countSub)){
    printf("\nStart : %d\t End : %d",i,j);
return 1;
}

}
}



return 0;

}

void FindLPS(char str[],int n,int lps[]){

int i=1;
int len=0;
lps[0]=0;

while(i<n){

if(str[i]==str[len]){
    len++;
    lps[i]=len;
    i++;
}else{

if(len){
len=lps[len-1];
}else{
lps[i]=0;
i++;
}

}


}



}


int FindIfTrue_KMP(char str[]){

int n=strlen(str);

int lps[n];

FindLPS(str,n,lps);//Longest Prefix Suffix

/*
int i;

for(i=0;i<n;i++){
printf("%d  ",lps[i]);
}

getch();
*/

int len=lps[n-1];

int i;
for(i=0;i<n-len;i++){
printf("%c",str[i]);
}
return (len>0 && n%(n-len)==0);


}

int main(){


char str[]="aabaabaabaab";
//char str[]="abcdabc";

//int result=FindIfTrue(str);
int result=FindIfTrue_KMP(str);
if(result){
printf("\nYes! Given string can be constructed by taking a substring and repeating");
}else{
printf("\No");
}



return 0;
}
