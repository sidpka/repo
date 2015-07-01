#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct TrieNode{

int isEnd;
struct TrieNode** child;

};
typedef struct TrieNode Trie;

Trie* NewNode(){

Trie* tmpNode=(Trie*)malloc(sizeof(Trie));
tmpNode->isEnd=0;
tmpNode->child=(Trie**)malloc(sizeof(Trie*)*26);
int i;

for(i=0;i<26;i++){
tmpNode->child[i]=NULL;
}

return tmpNode;


}

void InsertTrie(Trie** root,char* word){

if(!(*root)){
(*root)=NewNode();
}

if(*word){
InsertTrie(&(*root)->child[*word-'a'],word+1);
}

if(!*(word+1)){
(*root)->isEnd=1;
}


}

int Search(Trie* root,char* word){

if(!root){
return 0;
}

if(*word){
if(root->child[*word-'a']==NULL){
return 0;
}else{
return Search(root->child[*word-'a'],word+1);
}
}else{
return root->isEnd==1;
}


}

char* Substring(char str[],int pos,int len){

char* pointer=(char*)malloc(sizeof(char)*(len+1));

int i;

for(i=0;i<len;i++){
pointer[i]=str[i+pos-1];
}
pointer[i]='\0';

return pointer;

}

int CheckWordBreak(Trie* root,char* word){
if(!*word){

return 1;

}
//printf("\nHere for : %s",word);
int pos=1;
int length=1;

int len=strlen(word);

//int tmp=len;
//int flag=0;

//while(pos<=len){

while(length<=len){
char* pointer=Substring(word,pos,length);
if(Search(root,pointer) && CheckWordBreak(root,word+length)){
//return 1;
//printf("\nf\t%s",pointer);
//if(Search(root,word+length) || length==len){
    //printf("\ns\t%s",word+length);
return 1;
//}
}
free(pointer);
length++;

}

//pos++;
//length=1;
//tmp--;
//}




return 0;
}

int CheckWordBreak_DP(Trie* root,char* word){
int len=strlen(word);

if(len==0){
return 0;
}

int dp[len+1];

int i;

for(i=0;i<=len;i++){
dp[i]=0;
}

int j;
int pos=1;
for(i=1;i<=len;i++){
if(dp[i]==0 && Search(root,Substring(word,pos,i))){
dp[i]=1;
}

if(dp[i]==1){

if(i==len){
return 1;
}

for(j=i+1;j<=len;j++){

if(dp[j]==0 && Search(root,Substring(word+i,pos,j-i))){
dp[j]=1;
}

if(dp[j]==1){
if(j==len){
return 1;
}
}

}
}
}

return 0;
}


int main(){

char dictionary[12][20]={"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man","go","mango"};

int i;

Trie* root=NULL;

for(i=0;i<12;i++){

InsertTrie(&root,dictionary[i]);

}

/*
int result=Search(root,"mango");
printf("Result : %d",result);
*/

char word[]="ilikemango";


//int result=CheckWordBreak(root,word);
int result=CheckWordBreak_DP(root,word);
if(result){
printf("\nYes");
}else{
printf("\nNo");
}

return 0;
}
