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

void SetPAndS(TNode* root,TNode** PR,TNode** SR,int key){

if(!root){
return;
}

if(root->data==key){
return;
}
if(root->data<key){
(*PR)=root;
SetPAndS(root->right,PR,SR,key);
}
if(root->data>key){
(*SR)=root;
SetPAndS(root->left,PR,SR,key);
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
printf("\n%d nodes inserted in BST\n",i);

getch();

TNode* PR=NULL;
TNode* SR=NULL;
printf("\nEnter a number to find predecessor and successor :");
scanf("%d",&data);
SetPAndS(root,&PR,&SR,data);

if(PR){
printf("\nPredecessor of %d is : %d",data,PR->data);
}else{
printf("\nPredecessor of %d doesnt exist",data);
}
if(SR){
printf("\nSucessor of %d is : %d",data,SR->data);
}else{
printf("\nSucessor of %d doesnt exist",data);
}
return 0;
}
