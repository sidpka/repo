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

int GetLeftMost(TNode* root){
while(root->left){
root=root->left;
}
return root->data;
}

int GetRightMost(TNode* root){
while(root->right){
root=root->right;
}
return root->data;
}


void FindPredecessor_Successor(TNode* root,int data,int* pre,int* suc){

if(!root){
return;
}

if(root->data==data){

if(root->left){
(*pre)=GetRightMost(root->left);
}
if(root->right){
(*suc)=GetLeftMost(root->right);
}
return;
}
else if(root->data > data){
(*suc)=root->data;
FindPredecessor_Successor(root->left,data,pre,suc);
}
else{
(*pre)=root->data;
FindPredecessor_Successor(root->right,data,pre,suc);
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

printf("\nEnter the key you want to find inorder predecessor and successor of \n");
scanf("%d",&data);

int predecessor=-1;
int sucessor=-1;
int set=0;
FindPredecessor_Successor(root,data,&predecessor,&sucessor);
printf("\nPredecessor of %d is : %d and successor is : %d",data,predecessor,sucessor);

return 0;
}
