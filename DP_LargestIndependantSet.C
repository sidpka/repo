#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct TreeNode{

int data;
struct TreeNode* left;
struct TreeNode* right;

int lis;
};

typedef struct TreeNode TNode;

TNode* NewNode(int data){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->left=NULL;
tmpNode->right=NULL;

tmpNode->lis=0;

return tmpNode;


}


void Traverse(TNode* root){
if(!root){
return;
}

Traverse(root->left);
printf("%d  ",root->data);
Traverse(root->right);


}

int max(int a,int b){

return a>b?a:b;
}


int FindLIS(TNode* root){

if(!root){
return 0;
}

if(root->lis!=0){
return root->lis;
}

int left=FindLIS(root->left);
int right=FindLIS(root->right);

int inc=1;
if(root->left){
inc+=FindLIS(root->left->left)+FindLIS(root->left->right);
}
if(root->right){
inc+=FindLIS(root->right->left)+FindLIS(root->right->right);
}

return root->lis=max(inc,left+right);

}



int main(){

TNode* root=NewNode(10);
root->left=NewNode(20);
root->left->left=NewNode(40);
root->right=NewNode(30);
root->right->right=NewNode(60);
root->left->right=NewNode(50);
root->left->right->left=NewNode(70);
root->left->right->right=NewNode(80);

//Traverse(root);

printf("\nLargest Independent Set is of size : %d",FindLIS(root));


return 0;
}
