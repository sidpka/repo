#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Ternary{
char data;
struct Ternary* left;
struct Ternary* right;
struct Ternary* down;
bool isEndOfString;
};

typedef struct Ternary TSTNode;

TSTNode* NewNode(char data){
TSTNode* newNode=(TSTNode*)malloc(sizeof(TSTNode));
newNode->data=(data);
newNode->left=NULL;
newNode->right=NULL;
newNode->down=NULL;
newNode->isEndOfString=false;
return newNode;
}

void Insert(TSTNode** root,char* data){

if(!(*root)){
(*root)=NewNode(*data);
}

if((*data)<(*root)->data){
Insert(&((*root)->left),data);
}else if((*data)>(*root)->data){
Insert(&((*root)->right),data);
}

else{
if(*(data+1)){
Insert(&((*root)->down),data+1);
}else{
(*root)->isEndOfString=true;
}
}
}

void TraverseTST(TSTNode* root,char* buffer,int depth){
if(!root){
return;
}
TraverseTST(root->left,buffer,depth);
buffer[depth]=root->data;
if(root->isEndOfString){
    buffer[depth+1]='\0';
printf("\n %s\n",buffer);
}
TraverseTST(root->down,buffer,depth+1);
TraverseTST(root->right,buffer,depth);
}

int SearchTST(TSTNode* root,char* data){
if(!root){
return 0;
}

if((*data)<root->data){
return SearchTST(root->left,data);
}else if((*data)>root->data){
return SearchTST(root->right,data);
}else{

if(*(data+1)){
return SearchTST(root->down,data+1);
}else{
return root->isEndOfString==true;
}

}

}

int main(){
char* data=(char*)malloc(sizeof(char)*20);
int i;
TSTNode* root=NULL;
for(i=0;i<5;i++){
printf("\nEnter a string :  ");
scanf("%s",data);

Insert(&root,data);
}
printf("\n\n");
//printf("%c ",root->data);
//printf("%c  ",root->down->data);
//printf("%c  ",root->down->down->data);
printf("\nPress enter to traverse TST:\n\n");
getch();
char* buffer=(char*)malloc(sizeof(char)*20);
TraverseTST(root,buffer,0);
printf("\nEnter a string to search : ");
scanf("%s",data);
int result=SearchTST(root,data);
if(result){
printf("\nFound");
}
return 0;
}
