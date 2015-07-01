#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <unordered_set>
#define CHAR_MAX 256
using namespace std;

struct Suffix{
struct Suffix* child[CHAR_MAX];
struct Suffix* suffixLink;
int start;
int* end;
int suffixIndex;
unordered_set<int> *forwardIndexList;
unordered_set<int> *reverseIndexList;
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
unordered_set<int>:: iterator forwardInd;
//end global variables declaration
int size1=-1;




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
newNode->forwardIndexList =new unordered_set<int>();
newNode->reverseIndexList=new unordered_set<int>();

return newNode;
}






int EdgeLength(STree* node){

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

void SuffixTreeTraversal(STree* root,int level){
if(!root){
return;
}

if(root->start!=-1){
//Print(root);
}
//printf("\nTraversal");
int i;
int leaf=1;
for(i=0;i<CHAR_MAX;i++){
if(root->child[i]!=NULL){
    /*
if(root->start!=-1 && leaf){
printf("[%d]\n",root->suffixIndex);
}
*/
leaf=0;
SuffixTreeTraversal(root->child[i],level+EdgeLength(root->child[i]));



if(root->start!=-1){

root->forwardIndexList->insert(root->child[i]->forwardIndexList->begin(),root->child[i]->forwardIndexList->end());
root->reverseIndexList->insert(root->child[i]->reverseIndexList->begin(),root->child[i]->reverseIndexList->end());

}


}
}

if(leaf){

    for(i=root->start;i<*(root->end);i++){
    if(text[i]=='#'){
    root->end=(int*)malloc(sizeof(int));
    *(root->end)=i;
    }
    }

root->suffixIndex=size-level;

if(root->suffixIndex<size1){
root->forwardIndexList->insert(root->suffixIndex);
}else{
root->reverseIndexList->insert(root->suffixIndex-size1);
}


//printf("[%d]\n",root->suffixIndex);
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


}

int LCS_Util(STree* node,int* max,int* suffixInd,int label){

if(!node){
return -1;
}

int i;

for(i=0;i<CHAR_MAX;i++){
if(node->child[i]!=NULL){

LCS_Util(node->child[i],max,suffixInd,label+EdgeLength(node->child[i]));

if((*max)<label && node->forwardIndexList->size()>0 && node->reverseIndexList->size()>0){



int revIndex;

for(forwardInd=node->forwardIndexList->begin();forwardInd!=node->forwardIndexList->end();forwardInd++){

revIndex=(size1-2)-(*forwardInd+label-1);

if(node->reverseIndexList->find(revIndex)!=node->reverseIndexList->end()){
(*max)=label;
(*suffixInd)=*(node->end)-label+1;
break;
}

}



}


}
}


}

void LCS(){

int max=0;
int suffixInd=0;

LCS_Util(root,&max,&suffixInd,0);

int i;

for(i=0;i<max;i++){
printf("%c",text[i+suffixInd]);
}
if(i==0){
printf("\nNo repeated substring");
}
}

int main(){

//printf("\nEntering text itself : \n");
size1=13;
//PopulateP();
strcpy(text,"abacdfgdcaba#abacdgfdcaba$");
//printf("%s",text);
SuffixTree(text);
printf("\nPress enter to find Longest Common substring\n\n");
//getch();
LCS();
FreeSuffixTree(root);
return 0;
}
