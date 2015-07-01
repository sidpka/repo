#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Tree{
int data;
int vc;
struct Tree* left;
struct Tree* right;
};

typedef struct Tree TNode;

TNode* NewNode(int data){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->vc=0;
tmpNode->left=NULL;
tmpNode->right=NULL;

return tmpNode;
}

void Inorder(TNode* root){
if(!root){
return;
}

Inorder(root->left);
printf("%d  ",root->data);
Inorder(root->right);
}

int min(int a,int b){
return a<b?a:b;
}

int FindMinVertexCover(TNode* root){

if(!root || (!root->left && !root->right)){
return 0;
}

if(root->vc!=0){
return root->vc;
}




int inc=1+FindMinVertexCover(root->left)+FindMinVertexCover(root->right);

int exc=0;

if(root->left){
exc=1+ FindMinVertexCover(root->left->left)+FindMinVertexCover(root->left->right);
}

if(root->right){
exc+=1+ FindMinVertexCover(root->right->left)+FindMinVertexCover(root->right->right);
}


return root->vc= min(inc,exc);

}

int main(){

TNode* root=NewNode(10);
root->left=NewNode(20);
root->right=NewNode(30);
root->left->left=NewNode(40);
root->left->right=NewNode(50);
root->left->right->left=NewNode(70);
root->left->right->right=NewNode(80);
root->right->right=NewNode(60);

//Inorder(root);

printf("\nMinimum no of vertex cover : %d",FindMinVertexCover(root));






return 0;
}
