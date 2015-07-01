#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct TreeNode{
int data;
int liss;
struct TreeNode*left,*right;
};
typedef struct TreeNode TNode;

TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
newNode->liss=0;
return newNode;
}


int max(int a,int b){
return a>b?a:b;
}

int LISS(TNode* root){
if(!root){
return 0;
}



if(root->liss){
return root->liss;
}

if(!root->left && ! root->right){
return root->liss=1;
}

int lissExcludingThisNode=LISS(root->left)+LISS(root->right);

int lissIncludingThisNode=1;
if(root->left){
lissIncludingThisNode+=LISS(root->left->left)+LISS(root->left->right);
}
if(root->right){
lissIncludingThisNode+=LISS(root->right->left)+LISS(root->right->right);
}
root->liss=max(lissIncludingThisNode,lissExcludingThisNode);
return root->liss;
}

int main(){

TNode* root=NULL;

root=NewNode(10);
root->left=NewNode(20);
root->right=NewNode(30);
root->left->left=NewNode(40);
root->right->right=NewNode(60);
root->left->right=NewNode(50);
root->left->right->left=NewNode(70);
root->left->right->right=NewNode(80);

printf("\nLiss : %d",LISS(root));

getch();


return 0;
}
