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


void PrintRange(TNode* root,int k1,int k2){
if(!root){
return;
}
if(root->data>k1){
PrintRange(root->left,k1,k2);
}
if(root->data>=k1 &&  k2>=root->data){
printf("%d  ",root->data);
}
if(root->data<k2){
PrintRange(root->right,k1,k2);
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
printf("\n%d nodes inserted in BST\n");

getch();
int k1,k2;
printf("\nEnter range to see value between :\n\n");
scanf("%d %d",&k1,&k2);
PrintRange(root,k1,k2);
return 0;
}
