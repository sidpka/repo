#include<stdio.h>
#include<conio.h>
#include<string.h>

int FindLS(char str[],int n){


int i;
int j;

int max=1;

int len=0;
int visited[26];
for(i=0;i<n;i++){

for(j=0;j<26;j++){
visited[j]=0;
}

len=0;

for(j=i;j<n;j++){
if(visited[str[j-'A']]){
if(max<len){
max=len;
}
break;
}else{
len++;
visited[str[j]-'A']=1;
//printf("\nHere %d",len);
}
}


}

return max;
}


int FindNRCS(char str[],int  n){

int visited[256];

int i;

for(i=0;i<256;i++){
visited[i]=-1;
}

int max=1;
int curLen=1;

int prevIndex;

visited[str[0]]=0;

for(i=1;i<n;i++){
prevIndex=visited[str[i]];

if(prevIndex==-1 || i-curLen>prevIndex){

curLen++;
}else{

if(curLen>max){
max=curLen;
}

curLen=i-prevIndex;


}

visited[str[i]]=i;
}

if(curLen>max){
max=curLen;
}

return max;



}

int main(){

//char str[]="ABDEFGABEF";
char str[]="GEEKSFORGEEKS";

int n=strlen(str);

//printf("\nLength of longest substring without repeating character : %d",FindLS(str,n));

printf("\nNpn repeating character substring : %d",FindNRCS(str,n));






return 0;
}
