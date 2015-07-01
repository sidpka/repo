#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Bunch{
int count;
char** BArray;
};
typedef struct Bunch BNode;

struct LL{
int index;
struct LL* next;
};
typedef struct LL LNode;

struct Trie{
int isEnd;
LNode* head;
struct Trie* child[256];
};
typedef struct Trie TNode;

TNode* NewNode(){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->isEnd=0;
tmpNode->head=NULL;
int i;
for(i=0;i<256;i++){
tmpNode->child[i]=NULL;
}
return tmpNode;
}

LNode* InsertLL(TNode* node,int i){

    LNode* tmpNode=(LNode*)malloc(sizeof(LNode));
    tmpNode->index=i;
    if(!node->head){
    tmpNode->next=NULL;
    return tmpNode;
    }else{
    tmpNode->next=node->head;
    return tmpNode;
    }

}

void TraverseLL(TNode* node,BNode* bNode){
if(!node->head){
return;
}

LNode* tmpNode=node->head;

while(tmpNode){
printf("%s  ",bNode->BArray[tmpNode->index]);
tmpNode=tmpNode->next;
}
}



BNode* CreateBunch(int n){
BNode* tmpNode=(BNode*)malloc(sizeof(BNode));
tmpNode->count=n;
tmpNode->BArray=(char**)malloc(sizeof(char*)*n);

int i;

for(i=0;i<n;i++){
tmpNode->BArray[i]=(char*)malloc(sizeof(char)*50);
}

return tmpNode;
}

char* GetSorted(char* word){

int len=strlen(word);
char* buffer=(char*)malloc(sizeof(char)*len);

int array[256];
int i;

for(i=0;i<256;i++){
array[i]=0;
}

for(i=0;i<len;i++){
array[*(word+i)]++;
}

int index=0;

for(i=0;i<256;i++){
if(array[i]){
while(array[i]){
buffer[index++]=(char)i;
array[i]--;
}
}
}
//printf("\n%s",buffer);
return buffer;
}


void InsertTrie(TNode** root,int index,char* word){
if(!(*root)->child[*word]){
(*root)->child[*word]=NewNode();
}

if(*(word+1)){
InsertTrie(&(*root)->child[*word],index,word+1);
}else{
    //printf("\nHere for %c",*(word));
(*root)->child[*word]->isEnd=1;
(*root)->child[*word]->head=InsertLL((*root)->child[*word],index);
}

}

void TraverseTrie(TNode* root,BNode* bunchHead){
if(!root){
return;
}

int i;

for(i=0;i<256;i++){
if(root->child[i]){
if(root->child[i]->isEnd){
printf("\n");
//printf("\nHere for %c",i);
TraverseLL(root->child[i],bunchHead);
}
TraverseTrie(root->child[i],bunchHead);
}
}



}

int main(){
    /*
char word[50]="public";
GetSorted(word);
getch();
*/
int n;
printf("\nEnter the number of words you will enter : ");
scanf("%d",&n);

BNode* bunchHead=CreateBunch(n);
TNode* root=NewNode();
int i;

for(i=0;i<n;i++){
printf("\nEnter you word : ");
scanf("%s",bunchHead->BArray[i]);
}

printf("\nPress enter to populate Trie...");
getch();
for(i=0;i<n;i++){
    char* buffer=GetSorted(bunchHead->BArray[i]);
    //printf("\nInserting : %s",buffer);
InsertTrie(&root,i,buffer);
}

printf("\nTrie Updated\n\n");
getch();

printf("\nPress enter to see all anagrams : \n\n");
TraverseTrie(root,bunchHead);
getch();

}
