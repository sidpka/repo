#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Trie{
char data;
struct Trie* next[26];
};

typedef struct Trie TNode;



TNode* GetNode(){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
if(newNode){
newNode->data=0;
int i;

for(i=0;i<26;i++){
newNode->next[i]=NULL;
}
}else{
printf("\nMemory Error");
}

return newNode;
}



void InsertTrie(TNode** root,char* word){
int length=strlen(word);
int i;
int index;
if(!(*root)){
(*root)=GetNode();
//printf("\nHere");
}
TNode* tmpNode=(*root);
for(i=0;i<length;i++){

index=word[i]-97;

if(tmpNode->next[index]==NULL){
    //printf("\nReaching here ");
tmpNode->next[index]=GetNode();
}
tmpNode=tmpNode->next[index];
}
tmpNode->data=1;
}

int SearchTrie(TNode* root,char* word){
if(!root){
return 0;
}

int length=strlen(word);

int i;
int index;
TNode* tmpNode=root;
for(i=0;i<length;i++){
index=word[i]-97;

if(tmpNode->next[index]==NULL){
return 0;
}
tmpNode=tmpNode->next[index];
}

return tmpNode->data==1 && tmpNode;



}

void PrintCurrent(char* buffer,int index){
int i;
for(i=0;i<index;i++){
printf("%c",buffer[i]);
}
printf("\n");
}

void PrintAll(TNode* root,char* buffer,int index){
if(!root){
return;
}
int i;

if(root->data==1){
PrintCurrent(buffer,index);
}


for(i=0;i<26;i++){
if(root->next[i]){
buffer[index]=97+i;
PrintAll(root->next[i],buffer,index+1);
}
}
}

int main(){
int n;
printf("\nEnter the number of strings you want to add: ");
scanf("%d",&n);
int i;
char data[100];
TNode* root=NULL;
for(i=0;i<n;i++){
//printf("\nEnter the length of string you want to add : ");
printf("\nEnter the string you want to add : ");
scanf("%s",data);
InsertTrie(&root,data);
}
printf("\%d words added ",n);
getch();

printf("\nEnter the string you want to search : ");
scanf("%s",data);
int result=SearchTrie(root,data);
if(result){
printf("\nWord found !Hurray!");
}else{
printf("\nSorry! word not found !");
}
char* buffer=(char*)malloc(sizeof(char)*100);
printf("\nPress enter to print all the words in the dictionary you just created :\n");
getch();
PrintAll(root,buffer,0);
getch();
return 0;
}
