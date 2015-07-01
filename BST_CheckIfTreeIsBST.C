#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>


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

int GetLeft(TNode* root){
while(root->left){
root=root->left;
}
return root->data;
}

int GetRight(TNode* root){
while(root->right){
root=root->right;
}
return root->data;
}

int CheckIfBST(TNode* root){
if(!root){
return 1;
}
if(root->left && root->data < GetRight(root->left)){
    return 0;
}
if(root->right && root->data > GetLeft(root->right)){
return 0;
}

return CheckIfBST(root->left)&& CheckIfBST(root->right);

}

void Inorder(TNode* root){
if(!root){
return;
}

Inorder(root->left);
printf("%d  ",root->data);
Inorder(root->right);

}

int BST_Efficient(TNode* root,int min,int max){
if(!root){
return 1;
}
if(root->data<=min || root->data>=max){
return 0;
}
return BST_Efficient(root->left,min,root->data)&& BST_Efficient(root->right,root->data,max);

}

int BST_More_Efficient(TNode* root,int* prev){
if(!root){
return 1;
}
int left=BST_More_Efficient(root->left,prev);
if(!left){
return 0;
}
if(root->data<(*prev)){
return 0;
}else{
(*prev)=root->data;
}
int right=BST_More_Efficient(root->right,prev);

return right;


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
//root->left->data=150;
getch();
/*
Inorder(root);
int result=CheckIfBST(root);
*/

//Efficeint method

int result=BST_Efficient(root,INT_MIN,INT_MAX);

if(result){
printf("\nYes");
}else{
printf("\nNo");
}
int prev=INT_MIN;
result=BST_More_Efficient(root,&prev);
if(result){
printf("\nYes");
}else{
printf("\nNo");
}
return 0;
}
