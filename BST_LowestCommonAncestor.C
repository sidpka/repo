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


int BST_LCA(TNode* root,int a,int b){

if(!root){
return -1;
}

if(root->data>b){
return BST_LCA(root->left,a,b);
}

if(root->data < a){
return BST_LCA(root->right,a,b);
}

if(root->data <=b && root->data >=a){
return root->data;
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

printf("\nEnter the keys to find Lowest Common Ancestor of : ");
int a,b;
scanf("%d %d",&a,&b);
int ans=BST_LCA(root,a,b);
printf("\nLCA of %d and %d is : %d",a,b,ans);

getch();
return 0;
}
