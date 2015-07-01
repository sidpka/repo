#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct TreeNode{
int data;
struct TreeNode* left,*right;
};
typedef struct TreeNode TNode;

TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->right=NULL;
newNode->left=NULL;
return newNode;
}

void Insert(TNode** root,int data){
if(!(*root)){
(*root)=NewNode(data);
}else{
if((*root)->data>data){
Insert(&(*root)->left,data);
}else{
Insert(&(*root)->right,data);
}
}
}


int Search(TNode* root,int data){
if(!root){
return 0;
}
if(root->data==data){
return 1;
}
else if(root->data> data){
return Search(root->left,data);
}else{
return Search(root->right,data);
}
}


void FindCeil(TNode* root,TNode** tmpCeil,int* isSet,int key){
    if(!root){
    return;
    }

if(*isSet){
return;
}
if(key==root->data && !(*isSet)){
(*tmpCeil)=root;
(*isSet)=1;
return;
}


if(key > root->data && !(*isSet)){
FindCeil(root->right,tmpCeil,isSet,key);
}

if(key< root->data && !(*isSet)){
(*tmpCeil)=root;
FindCeil(root->left,tmpCeil,isSet,key);
}


}

void FindFloor(TNode* root,TNode** tmpFloor,int* isSet,int key){

if(!root){
return;
}

if(key==root->data && !(*isSet)){
(*tmpFloor)=root;
(*isSet)=1;
return;
}

if(key>root->data && !(*isSet)){
(*tmpFloor)=root;
FindFloor(root->right,tmpFloor,isSet,key);
}

if(key< root->data && !(*isSet)){
FindFloor(root->left,tmpFloor,isSet,key);
}

}



int main(){
printf("\nEnter the no of nodes you want to insert : ");
int n;
scanf("%d",&n);
int i,data;
TNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data for %d node : ",i);
scanf("%d",&data);
Insert(&root,data);
}
printf("\n%d nodes inserted in BST\n",i);

getch();
printf("\nEnter a number to find ceiling of : ");
scanf("%d",&data);
TNode* Ceil=NULL;
int isSet=0;
FindCeil(root,&Ceil,&isSet,data);
if(Ceil){
printf("\n\nCeil of %d is : %d",data,Ceil->data);
}
else{
printf("\nCeil doesnot exist");
}

getch();
printf("\nEnter a number to find floor of : ");
scanf("%d",&data);
TNode* Floor=NULL;
isSet=0;
FindFloor(root,&Floor,&isSet,data);
if(Floor){
printf("\n\Floor of %d is : %d",data,Floor->data);
}
else{
printf("\Floor doesnot exist");
}

return 0;
}
