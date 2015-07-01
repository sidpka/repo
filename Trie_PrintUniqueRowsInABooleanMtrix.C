#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Trie{
char data;
struct Trie* next[2];
};

typedef struct Trie TNode;



TNode* GetNode(){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
if(newNode){
newNode->data=0;
int i;

for(i=0;i<2;i++){
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

index=word[i]-48;

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
index=word[i]-48;

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


for(i=0;i<2;i++){
if(root->next[i]){
buffer[index]=48+i;
PrintAll(root->next[i],buffer,index+1);
}
}
}

int main(){
int m,n;
printf("\nEnter the number of rows and columns in matrix : ");
scanf("%d %d",&m,&n);

char** matrix=(char**)malloc(sizeof(char*)*m);
int i;
for(i=0;i<m;i++){
matrix[i]=(char*)malloc(sizeof(char*)*n);
}

int j;
printf("\nEnter data in matrix :\n\n");
getch();


for(i=0;i<m;i++){
//for(j=0;j<n;j++){
printf("matric[%d][] : ",i);
scanf("%s",matrix[i]);
//}
}
//char data[100];
TNode* root=NULL;
int result;
for(i=0;i<m;i++){
result=SearchTrie(root,matrix[i]);
if(!result){
InsertTrie(&root,matrix[i]);
printf("\n%s",matrix[i]);
}
}

return 0;
}
