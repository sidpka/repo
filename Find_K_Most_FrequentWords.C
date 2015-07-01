#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Trie{
char data;
int isEnd;
int heapIndex;
int count;
struct Trie* child[256];
};

typedef struct Trie TNode;


struct Heap{
int count;
int capacity;
TNode** HArray;
};
typedef struct Heap HNode;



TNode* NewNode(char ch){
TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=ch;
tmpNode->isEnd=0;

tmpNode->heapIndex=-1;
tmpNode->count=0;
int i;
for(i=0;i<256;i++){
tmpNode->child[i]=NULL;
}
return tmpNode;
}


void InsertHeap(HNode* heapHead,TNode* node){
int i=heapHead->count;

while(i>0 && node->count<heapHead->HArray[(i-1)/2]->count){
heapHead->HArray[i]=heapHead->HArray[(i-1)/2];
heapHead->HArray[(i-1)/2]->heapIndex=i;
i=(i-1)/2;
}

heapHead->HArray[i]=node;
heapHead->HArray[i]->heapIndex=i;
heapHead->count++;
}

int Left(HNode* heapHead,int i){
int left=2*i+1;
if(left<heapHead->count){
return left;
}else{
return -1;
}
}

int Right(HNode* heapHead,int i){
int right=2*i+1;
if(right<heapHead->count){
return right;
}else{
return -1;
}
}

void PercolateDown(HNode* heapHead,int i){

int left=Left(heapHead,i);
int right=Right(heapHead,i);
int min;

if(left!=-1 && heapHead->HArray[left]->count< heapHead->HArray[i]->count){
min=left;
}else{
min=i;
}

if(right!=-1 && heapHead->HArray[right]->count < heapHead->HArray[i]->count){
min=right;
}


if(i!=min){
TNode* tmpNode=heapHead->HArray[i];
heapHead->HArray[i]=heapHead->HArray[min];
heapHead->HArray[i]->heapIndex=i;
heapHead->HArray[min]=tmpNode;
heapHead->HArray[min]->heapIndex=min;

PercolateDown(heapHead,min);

}
}


TNode* PopHeap(HNode* heapHead){
TNode* tmpNode=heapHead->HArray[0];

heapHead->HArray[0]=heapHead->HArray[heapHead->count-1];
heapHead->count--;
PercolateDown(heapHead,0);

return tmpNode;

}



void InsertTrie(TNode** root,HNode* heapHead,char* word){
if((*root)->child[*word]==NULL){
(*root)->child[*word]=NewNode(*word);
}

if(*(word+1)){
InsertTrie(&(*root)->child[*word],heapHead,word+1);
}else{

(*root)->child[*word]->isEnd=1;
(*root)->child[*(word)]->count++;

if((*root)->child[*word]->heapIndex==-1){
    if(heapHead->count<heapHead->capacity){
    InsertHeap(heapHead,(*root)->child[*word]);

    }else{
int topElm=heapHead->HArray[0]->count;
if(topElm<(*root)->child[*(word)]->count){
TNode* tmpNode=PopHeap(heapHead);
tmpNode->heapIndex=-1;
InsertHeap(heapHead,(*root)->child[*word]);
}
    }

}else{
int index=(*root)->child[*word]->heapIndex;
//heapHead->HArray[index]->count++;
PercolateDown(heapHead,index);
}

}
}

void TraverseTrie(TNode* root,char* buffer,int index){
if(!root){
return;
}
int i;
for(i=0;i<256;i++){
if(root->child[i]){
buffer[index]=root->child[i]->data;
if(root->child[i]->isEnd==1){
buffer[index+1]='\0';
printf("\n%s : Count : %d",buffer,root->child[i]->count);
}
TraverseTrie(root->child[i],buffer,index+1);
}
}
}


void Traverse(TNode* root){
char* buffer=(char*)malloc(sizeof(char)*50);
TraverseTrie(root,buffer,0);
}

HNode* CreateHeap(int n){
HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->capacity=n;
tmpNode->count=0;
tmpNode->HArray=(TNode**)malloc(sizeof(TNode*)*n);
int i;

for(i=0;i<n;i++){
tmpNode->HArray[i]=NULL;
}
return tmpNode;
}

void PrintKFrequent_Util(TNode* root,char* buffer,int index){

if(!root){
return;
}

int i;

for(i=0;i<256;i++){
if(root->child[i]){
buffer[index]=root->child[i]->data;

if(root->child[i]->isEnd && root->child[i]->heapIndex!=-1){
buffer[index+1]='\0';
printf("\n%s : count : %d",buffer,root->child[i]->count);
}
PrintKFrequent_Util(root->child[i],buffer,index+1);
}
}
}

void PrintKFrequent(TNode* root){

char* buffer=(char*)malloc(sizeof(char)*50);
PrintKFrequent_Util(root,buffer,0);

}

int main(){

int ch=1;
printf("\nEnter the value of K : ");
int K;
scanf("%d",&K);
char word[100];
TNode* root=(TNode*)malloc(sizeof(TNode));
HNode* heapHead=CreateHeap(K);
printf("\nHeap capacity and count : %d and %d",heapHead->capacity,heapHead->count);
while(ch){
printf("\n1.Insert");
printf("\n2.Print %d most frequent words : ",K);
printf("\n3.TraverseTrie");
printf("\n0.Exit\n");
scanf("%d",&ch);

switch(ch){
case 1:
printf("\nEnter the word you want to insert : ");
scanf("%s",word);
InsertTrie(&root,heapHead,word);
break;

case 2:
PrintKFrequent(root);
break;

case 3:

Traverse(root);
break;

case 0:
break;

}

}

return 0;
}
