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

int FindMinimum(TNode* root){
if(!root){
return -1;
}
while(root->left){
root=root->left;
}
return root->data;
}

int FindMaximum(TNode* root){
if(!root){
return -1;
}
while(root->right){
root=root->right;
}
return root->data;
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
printf("\nPress enter to see the minimum elemnt present in BST :  ");
getch();
int result=FindMinimum(root);
if(result==-1){
printf("\nEmpty Tree");
}else{
printf("\nMimimum elemnt in BST is : %d",result);
}
getch();
printf("\nPress enter to see the maximum elemnt present in BST :  ");
getch();
result=FindMaximum(root);
if(result==-1){
printf("\nEmpty Tree");
}else{
printf("\nMaximum elemnt in BST is : %d",result);
}
getch();
return 0;
}
