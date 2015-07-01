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

void Swap(TNode** a,TNode** b){

int tmpData=(*a)->data;
(*a)->data=(*b)->data;
(*b)->data=tmpData;
}

void Correct_TheTree(TNode* root,TNode** first,TNode** middle,TNode** last,TNode** previ){

if(!root){
return;
}

Correct_TheTree(root->left,first,middle,last,previ);

if((*previ) && (*previ)->data > root->data){

if(!(*first)){

(*first)=(*previ);
(*middle)=root;
}else{
(*last)=root;
}
}

(*previ)=root;


Correct_TheTree(root->right,first,middle,last,previ);

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

printf("\nPress enter to traverse\n");
getch();
Inorder_Traversal(root);
getch();
printf("\nPress enter to swap \n");
getch();
Swap(&root->left,&root->right);
printf("\nSwapped\n");
getch();
printf("\nPress enter to traverse \n");
getch();
Inorder_Traversal(root);
getch();
TNode* prev=NULL;
TNode* first=NULL;
TNode* middle=NULL;
TNode* last=NULL;
Correct_TheTree(root,&first,&middle,&last,&prev);
int tmpData;

if(!last){

    tmpData=(prev)->data;
(prev->data)=(middle->data);
(middle)->data=tmpData;
}else{
tmpData=last->data;
last->data=first->data;
first->data=tmpData;
}

printf("\nTree correcteed\n");
getch();
printf("\nPress enter to traverse\n");
getch();
Inorder_Traversal(root);
getch();
return 0;
}
