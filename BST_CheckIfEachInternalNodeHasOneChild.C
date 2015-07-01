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

void InorderTraversal(TNode* root){

if(!root){
return;
}

InorderTraversal(root->left);
printf("%d  ",root->data);
InorderTraversal(root->right);
}

void AddMax(TNode** root,int* max,int* isSet){
if(!(*root)){
return;
}
if((*root)->right){
AddMax(&(*root)->right,max,isSet);
}
if((*root)->right==NULL && (*isSet)==0){
(*max)=(*root)->data;
(*isSet)=1;
}else{
int tmpData=(*root)->data;
(*root)->data+=(*max);
(*max)+=tmpData;
}

AddMax(&(*root)->left,max,isSet);

}

TNode* GetLeftMost(TNode* root){
if(!root){
return NULL;
}

while(root->left){
root=root->left;
}

return root;

}


TNode* RemoveNodesOutOfRange(TNode* root,int min,int max){

if(!root){
return NULL;
}

root->right=RemoveNodesOutOfRange(root->right,min,max);
root->left=RemoveNodesOutOfRange(root->left,min,max);

if(root->data < min  || root->data > max){

if(root->left && root->right){
TNode* tmpNode=GetLeftMost(root->right);
tmpNode->left=root->left;
return root->right;
}

else if(root->left){
return root->left;
}
else if(root->right){
return root->right;
}
else{
return NULL;
}


}



return root;
}

int IsFullNode(TNode* root){
return root->left !=NULL && root->right!=NULL;
}

int IsPartialNode(TNode* root){
return root->left || root->right;
}

int IsLeafNode(TNode* root){
return root->left==NULL & root->right==NULL;
}

int CheckIfInternalNodeHasOneChild(TNode* root){
if(!root){
return 1;
}

if(IsFullNode(root)){
return 0;
}
if(IsLeafNode(root)){
return 1;
}
if(IsPartialNode(root)){
return CheckIfInternalNodeHasOneChild(root->left) && CheckIfInternalNodeHasOneChild(root->right);
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
printf("\n%d nodes inserted in BST\n");

getch();
printf("\nPress enter to traverse \n\n: ");
getch();
InorderTraversal(root);
getch();
int result=CheckIfInternalNodeHasOneChild(root);
if(result){
printf("\nYes internal nodes have one child");
}else{
printf("\nNo internal nodes dont have just one child");
}
return 0;
}
