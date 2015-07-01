#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Trie{
char isLeaf;
char* url;
struct Trie* next[11];
};

typedef struct Trie TNode;



TNode* GetNode(){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
if(newNode){
newNode->isLeaf=0;
newNode->url=NULL;
int i;

for(i=0;i<11;i++){
newNode->next[i]=NULL;
}
}else{
printf("\nMemory Error");
}

return newNode;
}

int CharToInt(char c){
return (c=='.')?10:c-'0';
}

char IntToChar(int index){
return (index==10)?'.':'0'+index;
}

void InsertTrie(TNode** root,char* url,char* ipAddress){
int length=strlen(ipAddress);
//printf("\nLength is : %d",length);
int i;
int index;
if(!(*root)){
(*root)=GetNode();
//printf("\nHere");
}
TNode* tmpNode=(*root);
for(i=0;i<length;i++){
//printf("\nHere");
index=CharToInt(ipAddress[i]);

if(tmpNode->next[index]==NULL){
    //printf("\nReaching here ");
tmpNode->next[index]=GetNode();
}
tmpNode=tmpNode->next[index];
}
tmpNode->isLeaf=1;
tmpNode->url=(char*)malloc(sizeof(char)*strlen(url));
strcpy(tmpNode->url,url);
}

char* SearchTrie(TNode* root,char* ipAddress){
if(!root){
return NULL;
}
int length=strlen(ipAddress);
int i;
int index;
TNode* tmpNode=root;
for(i=0;i<length;i++){
index=CharToInt(ipAddress[i]);
if(tmpNode->next[index]==NULL){
return NULL;
}
tmpNode=tmpNode->next[index];
}

if(tmpNode->isLeaf){
return tmpNode->url;
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
printf("%s",root->url);
printf("\n\n");
}


for(i=0;i<11;i++){
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
printf("\nEnter the ipAddress you want to know url of : ");
scanf("%s",data);
char* result=SearchTrie(root,data);
if(result){
printf("\n\nUrl found !Hurray!\n");
printf("%s",result);
}else{
printf("\nSorry! ip not found in cache!");
}
getch();
//char* buffer=(char*)malloc(sizeof(char)*400);
//char* array=(char*)malloc(sizeof(char)*300);

printf("\nPress enter to print all the backward lookup in the cache :\n");
getch();
PrintAll(root,data,0);
getch();
return 0;
}
