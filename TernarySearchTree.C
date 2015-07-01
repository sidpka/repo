#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


struct TST{
char data;
struct TST* left;
struct TST* right;
struct TST* equal;
int isEnd;
};

typedef struct TST TNode;;

TNode* NewNode(char word){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->left=NULL;
newNode->right=NULL;
newNode->equal=NULL;
newNode->isEnd=0;
newNode->data=word;
return newNode;

}

void TraverseTsT_Util(TNode* root,char* buffer,int depth){

if(!root){
return;
}
//printf("\n33");
TraverseTsT_Util(root->left,buffer,depth);
buffer[depth]=root->data;
if(root->isEnd){
buffer[depth+1]='\0';
printf("\n%s",buffer);
}
TraverseTsT_Util(root->equal,buffer,depth+1);

TraverseTsT_Util(root->right,buffer,depth);
}


void TraverseTsT(TNode* root){

char* buffer=(char*)malloc(sizeof(char)*100);
TraverseTsT_Util(root,buffer,0);
}


TNode* Insert(TNode* root,char* word){
if(!root){
root=NewNode(*word);
}

if(root->data>*word){
root->left=Insert(root->left,word);
}else if(root->data < *word){
root->right=Insert(root->right,word);
}else{
if(!*(word+1)){
root->isEnd=1;
}else{
root->equal=Insert(root->equal,(word+1));
}
}
return root;
}

int Search(TNode* root,char* word){

if(!root){
return 0;
}

if(*word<root->data){
return Search(root->left,word);
}else if(*word>root->data){
return Search(root->right,word);
}else{
if(root->isEnd && !*(word+1)){
return 1;
}else if(!(*word+1) && root->isEnd==0){
return 0;
}else{
return Search(root->equal,word+1);
}


}



}


int main(){
int ch=1;
char word[100];
TNode* root=NULL;
int result;
while(ch){
printf("\nEnter your choice : ");
printf("\n1.Insert");
printf("\n2.Search");
printf("\n3.Traverse");
printf("\n0.Exit\n");
scanf("%d",&ch);
switch(ch){

case 1:
printf("\nEnter your word : ");
scanf("%s",word);
root=Insert(root,word);
break;
case 2:
printf("\nEnter your word : ");
scanf("%s",word);
result=Search(root,word);
if(result==1){
printf("\nWord found in dictionary");
}else{
printf("\nNot in dictionary");
}
break;
case 3:
TraverseTsT(root);
break;
case 0:
ch=0;
break;
}
}

return 0;
}
