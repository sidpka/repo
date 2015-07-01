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

void Inorder_Traversal(TNode* root){

if(!root){
return;
}

Inorder_Traversal(root->left);
printf("%d  ",root->data);
Inorder_Traversal(root->right);

}

TNode* ConstructTree(int* preOrder,int n,int* preIndex,int key,int min,int max){
if(*preIndex>=n){
return NULL;
}
TNode* root=NULL;
if(key > min && key < max){
root=NewNode(key);

*preIndex=*preIndex+1;

if(*preIndex<n){

root->left=ConstructTree(preOrder,n,preIndex,preOrder[*preIndex],min,key);
root->right=ConstructTree(preOrder,n,preIndex,preOrder[*preIndex],key,max);
}


}
return root;
}

int main(){
//printf("\nEnter the no of nodes you want to insert : ");
int n;
//scanf("%d",&n);
int i,data;
TNode* root=NULL;
int preOrder[]={10,5,2,6,16};

n=sizeof(preOrder)/sizeof(preOrder[0]);


int preIndex=0;
int min=INT_MIN;
int max=INT_MAX;
root=ConstructTree(preOrder,n,&preIndex,preOrder[preIndex],min,max);

printf("\n%d nodes inserted in BST\n");

getch();

printf("\nPress enter to traverse\n");
getch();
Inorder_Traversal(root);
getch();

return 0;
}
