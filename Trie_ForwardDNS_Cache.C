#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Trie{
char isLeaf;
char* ipAddress;
struct Trie* next[27];
};

typedef struct Trie TNode;



TNode* GetNode(){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
if(newNode){
newNode->isLeaf=0;
newNode->ipAddress=NULL;
int i;

for(i=0;i<27;i++){
newNode->next[i]=NULL;
}
}else{
printf("\nMemory Error");
}

return newNode;
}

int CharToInt(char c){
return (c=='.')?26:c-'a';
}

char IntToChar(int index){
return (index==26)?'.':97+index;
}

void InsertTrie(TNode** root,char* word,char* ipAddress){
int length=strlen(word);
int i;
int index;
if(!(*root)){
(*root)=GetNode();
//printf("\nHere");
}
TNode* tmpNode=(*root);
for(i=0;i<length;i++){

index=CharToInt(word[i]);

if(tmpNode->next[index]==NULL){
    //printf("\nReaching here ");
tmpNode->next[index]=GetNode();
}
tmpNode=tmpNode->next[index];
}
tmpNode->isLeaf=1;
tmpNode->ipAddress=(char*)malloc(sizeof(char)*strlen(ipAddress));
strcpy(tmpNode->ipAddress,ipAddress);
}

char* SearchTrie(TNode* root,char* word){
if(!root){
return NULL;
}
int length=strlen(word);
int i;
int index;
TNode* tmpNode=root;
for(i=0;i<length;i++){
index=CharToInt(word[i]);
if(tmpNode->next[index]==NULL){
return NULL;
}
tmpNode=tmpNode->next[index];
}

if(tmpNode->isLeaf){
return tmpNode->ipAddress;
}else{
return NULL;
}

//return tmpNode->data==1 && tmpNode;
}

void PrintCurrent(char* buffer,int index){
int i;
for(i=0;i<index;i++){
printf("%c",buffer[i]);
}
printf("  :  ");
}

void PrintAll(TNode* root,char* buffer,int index){
if(!root){
return;
}
int i;

if(root->isLeaf==1){
PrintCurrent(buffer,index);
printf("%s",root->ipAddress);
printf("\n\n");
}


for(i=0;i<27;i++){
if(root->next[i]){
buffer[index]=IntToChar(i);
PrintAll(root->next[i],buffer,index+1);
}
}
}

int main(){
int n;
//printf("\nEnter the number of strings you want to add: ");
//scanf("%d",&n);
   char URL[][50] = { "www.samsung.com", "www.samsung.net",
                       "www.google.in"
                     };
    char ipAdd[][100] = { "107.108.11.123", "107.109.123.255",
                          "74.125.200.106"
                        };

int i;
char data[100];
TNode* root=NULL;
printf("\nGoing to build cache\n");
getch();
for(i=0;i<3;i++){
//printf("\nEnter the length of string you want to add : ");
//printf("\nEnter the string you want to add : ");
//scanf("%s",data);
InsertTrie(&root,URL[i],ipAdd[i]);
}
printf("\%d Cahche added ",i);
getch();
printf("\nEnter the url you want to know ip of : ");
scanf("%s",data);
char* result=SearchTrie(root,data);
if(result){
printf("\n\nIP found !Hurray!\n");
printf("%s",result);
}else{
printf("\nSorry! url not found in cache!");
}
getch();
//char* buffer=(char*)malloc(sizeof(char)*400);
//char* array=(char*)malloc(sizeof(char)*300);

printf("\nPress enter to print all the forward lookup in the cache :\n");
getch();
PrintAll(root,data,0);
getch();
return 0;
}
