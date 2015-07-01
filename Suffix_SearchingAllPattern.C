#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define CHAR_MAX 256

struct Suffix{
struct Suffix* child[CHAR_MAX];
struct Suffix* suffixLink;
int start;
int* end;
int suffixIndex;
};
typedef struct Suffix STree;
//global variables

char text[100];
int* rootEnd;
STree* root;
int leafEnd;
STree* activeNode;
STree* nextNode;
int activeEdge;
int activeLength;
int remainingSuffixCount;
int* splitEnd;
STree* split;
int size;
//end global variables declaration

STree* NewNode(int start,int* end){
STree* newNode=(STree*)malloc(sizeof(STree));
newNode->start=start;
newNode->end=end;
int i;

for(i=0;i<CHAR_MAX;i++){
newNode->child[i]=NULL;
}
newNode->suffixIndex=-1;
newNode->suffixLink=root;
return newNode;
}

int EdgeLength(STree* node){
if(node==root){
return 0;
}
return (*(node->end)-node->start +1);


}

int WalkDown(STree* node){

if(activeLength>=EdgeLength(node)){
activeEdge+=EdgeLength(node);
activeLength-=EdgeLength(node);
activeNode=node;
return 1;
}
return 0;



}

void ExtendSuffixTree(int pos){

leafEnd=pos;
remainingSuffixCount++;
nextNode=NULL;
while(remainingSuffixCount>0){

    //printf("\nHere");
//APCFALZ
if(activeLength==0){
activeEdge=pos;
}


if(activeNode->child[text[activeEdge]]==NULL){
activeNode->child[text[activeEdge]]=NewNode(pos,&leafEnd);
if(nextNode!=NULL){
nextNode->suffixLink=activeNode;
nextNode=NULL;
}
}else{

STree* next=activeNode->child[text[activeEdge]];

if(WalkDown(next)){
continue;
}
if(text[next->start+activeLength]==text[pos]){
activeLength++;
if(nextNode!=NULL && activeNode!=root){
nextNode->suffixLink=activeNode;
nextNode=NULL;
}
break;
}

splitEnd=(int*)malloc(sizeof(int));
*splitEnd=next->start+activeLength-1;
split=NewNode(next->start,splitEnd);

split->child[text[pos]]=NewNode(pos,&leafEnd);

activeNode->child[text[activeEdge]]=split;

next->start=next->start+activeLength;
split->child[text[next->start]]=next;

if(nextNode!=NULL){
nextNode->suffixLink=split;
}
nextNode=split;
}
remainingSuffixCount--;
if(activeNode==root && activeLength>0){
activeLength--;
activeEdge=pos-remainingSuffixCount+1;
}

if(activeNode!=root){
activeNode=activeNode->suffixLink;
}

}
}

void Print(STree* root){
int i;
for(i=root->start;i<=*(root->end);i++){
printf("%c",text[i]);
}
}

void SuffixTreeTraversal(STree* root,int level){
if(!root){
return;
}

if(root->start!=-1){
Print(root);
}
//printf("\nTraversal");
int i;
int leaf=1;
for(i=0;i<CHAR_MAX;i++){
if(root->child[i]!=NULL){
if(root->start!=-1 && leaf){
printf("[%d]\n",root->suffixIndex);
}
leaf=0;
SuffixTreeTraversal(root->child[i],level+EdgeLength(root->child[i]));
}
}

if(leaf){
root->suffixIndex=size-level;
printf("[%d]\n",root->suffixIndex);
}
}

void FreeSuffixTree(STree* root){

if(!root){
return;
}
int i;
for(i=0;i<CHAR_MAX;i++){
if(root->child[i]!=NULL){
FreeSuffixTree(root->child[i]);
}
}

if(root->start!=-1){
free(root->end);
}
free(root);

}


void SuffixTree(char* text){
size=strlen(text);

root=NULL;
rootEnd=(int*)malloc(sizeof(int));
*rootEnd=-1;
root=NewNode(-1,rootEnd);
activeNode=root;
activeLength=0;
int i;
remainingSuffixCount=0;

for(i=0;i<size;i++){
ExtendSuffixTree(i);
}

//DFS
int level=0;
//printf("\nHere");
SuffixTreeTraversal(root,level);

//free

FreeSuffixTree(root);
}

int TraverseEdge(STree* root,char* pattern ,int idx){

int i;

for(i=root->start;i<=*(root->end) && pattern[idx]!='\0';i++,idx++){
if(text[i]!=pattern[idx]){
return -1;
}
}

if(pattern[idx]=='\0'){
return 1;
}else{
return 0;
}


}

int CountSubstring(STree* root){
if(!root){
return 0;
}

int i;

int count=0;

if(root->suffixIndex>-1){
printf("\nFound at position : %d",root->suffixIndex);
return 1;
}

for(i=0;i<CHAR_MAX;i++){
if(root->child[i]!=NULL){
count+=CountSubstring(root->child[i]);
}
}
return count;
}

int DoTraverse(STree* root,char* pattern,int idx){

if(!root){
return -1;
}
int res=-1;
if(root->start!=-1){
res=TraverseEdge(root,pattern,idx);
if(res==-1){
return res;
}
if(res==1){

if(root->suffixIndex>-1){
printf("\nSubstring count : 1 : FOund at position : %d",root->suffixIndex);
}else{
printf("\nSubstring count : %d",CountSubstring(root));
}
return 1;
}
}
idx+=EdgeLength(root);
if(root->child[pattern[idx]]!=NULL){
return DoTraverse(root->child[pattern[idx]],pattern,idx);
}else{
return -1;
}
}

void SearchPattern(char* pattern){

int res=DoTraverse(root,pattern,0);
if(res==1){
printf("\nPattern %s found !!",pattern);
}else{
printf("\nNot found");
}
}


int main(){
//printf("\nEntering text itself : \n");
strcpy(text,"Sid Sid Sid$");
//printf("%s",text);
SuffixTree(text);
SearchPattern("AA");
SearchPattern("Sid");
SearchPattern("dis");
SearchPattern("Siddharth Pandey");
return 0;
}
