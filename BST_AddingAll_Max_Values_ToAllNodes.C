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
printf("\nPress enter to add max values in BST to all nodes\n\n");
getch();
int max=0;
int isSet=0;
AddMax(&root,&max,&isSet);
printf("\n\nDone\n\nPress enter to traverse\n\n");
getch();
InorderTraversal(root);
getch();
return 0;
}
