#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct RedBlack{

int data;
char color;

struct RedBlack* parent;
struct RedBlack* left;
struct RedBlack* right;

};

typedef struct RedBlack RBNode;


RBNode* NewNode(int data){
RBNode* newNode=(RBNode*)malloc(sizeof(RBNode));
newNode->data=data;
//newNode->color='R';
newNode->left=NULL;
newNode->right=NULL;
newNode->parent=NULL;
}


void LeftRotate(RBNode** root,RBNode* node){


RBNode* x=node->right;

node->right=x->left;
if(node->right!=NULL){
node->right->parent=node;
}

x->parent=node->parent;

if(node->parent==NULL){
(*root)=x;
}else if(node->parent->left==node){
node->parent->left=x;
}else{
node->parent->right=x;
}

node->parent=x;

x->left=node;

}


void RightRotate(RBNode** root,RBNode* node){

RBNode* x=node->left;

node->left=x->right;

if(node->left!=NULL){
node->left->parent=node;
}

x->parent=node->parent;

if(node->parent==NULL){
(*root)=x;
}else if(node->parent->left==node){
node->parent->left=x;
}else{
node->parent->right=x;
}

node->parent=x;

x->right=node;


}



void BalanceTree(RBNode** root,RBNode* node){

while(node!=(*root) && node->parent->color=='R'){
RBNode* y;
if(node->parent->parent !=NULL &&  node->parent==node->parent->parent->left){
y=node->parent->parent->right;
}else{
y=node->parent->parent->left;
}

if(y->color=='R'){
node->parent->color='B';
node->parent->parent->color='R';
y->color='B';
node=node->parent->parent;
}else{
//printf("\nHere");
char ch;
if(node->parent==node->parent->parent->left && node==node->parent->left){
ch=node->parent->color;
node->parent->color=node->parent->parent->color;
node->parent->parent->color=ch;
RightRotate(&(*root),node->parent->parent);
}

if(node->parent==node->parent->parent->left && node==node->parent->right){
ch=node->color;
node->color=node->parent->parent->color;
node->parent->parent->color=ch;
LeftRotate(&(*root),node->parent);
RightRotate(&(*root),node->parent->parent);
}

if(node->parent==node->parent->parent->right && node==node->parent->right){
ch=node->parent->color;
node->parent->color=node->parent->parent->color;
node->parent->parent->color=ch;
//printf("\n134");
LeftRotate(&(*root),node->parent->parent);
//printf("\n136");
}

if(node->parent==node->parent->parent->right && node==node->parent->left){
ch=node->color;
node->color=node->parent->parent->color;
node->parent->parent->color=ch;
RightRotate(&(*root),node->parent);
LeftRotate(&(*root),node->parent->parent);
}
}
}
(*root)->color='B';
}


void InsertRedBlack(RBNode** root,int data){
//printf("\nhere");
RBNode* node=NewNode(data);
if(!(*root)){

    (*root)=node;
    (*root)->color='B';

}else{
RBNode* x,*z;
z=NULL;
x=(*root);
while(x!=NULL){
z=x;
if(data<x->data){
x=x->left;
}else{
x=x->right;
}
}
node->parent=z;
if(node->data<z->data){
z->left=node;
}else{
z->right=node;;
}
node->color='R';
}
//printf("\n184");
BalanceTree(&(*root),node);
}

void Traversal(RBNode* root){
if(!root){
return ;
}

printf("\n%d  %c",root->data,root->color);
Traversal(root->left);
Traversal(root->right);
}

int main(){
int n;
printf("\nEnter the number of nodes you want to enter : ");
scanf("%d",&n);
int i;
int data;
RBNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
InsertRedBlack(&root,data);
printf("\nTraversal\n");
Traversal(root);
printf("\nTraversal End\n");
}


return 0;
}
