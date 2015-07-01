#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct  Splay{
int data;
struct Splay* left;
struct Splay* right;

};

typedef struct Splay SNode;

SNode* LeftRotate(SNode* node){

SNode* tmpNode=node->right;
node->right=tmpNode->left;
tmpNode->left=node;

return tmpNode;

}


SNode* RightRotate(SNode* node){

SNode* tmpNode=node->left;
node->left=tmpNode->right;
tmpNode->right=node;

return tmpNode;

}


SNode* SplayNodes(SNode* root,int data){

if(root==NULL || root->data==data){

return root;

}


if(root->data> data){

if(root->left==NULL){
return root;
}

if(root->left->data>data){
root->left->left=SplayNodes(root->left->left,data);
root=RightRotate(root);
}else if(root->left->data<data){
root->left->right=SplayNodes(root->left->right,data);
if(root->left->right!=NULL){
root->left=LeftRotate(root->left);
}
}
return (root->left==NULL)?(root):RightRotate(root);

}else{

if(root->right==NULL){
return root;
}

if(root->right->data< data){
root->right->right=SplayNodes(root->right->right,data);
root=LeftRotate(root);
}
else if(root->right->data>data){
root->right->left=SplayNodes(root->right->left,data);
if(root->right->left!=NULL){
root->right=RightRotate(root->right);
}
}
return root=(root->right==NULL)?root:LeftRotate(root);

}


}

SNode* Search(SNode* root,int key){

return SplayNodes(root,key);

}

SNode* NewNode(int data){
SNode* tmpNode=(SNode*)malloc(sizeof(SNode));
tmpNode->data=data;
tmpNode->left=NULL;
tmpNode->right=NULL;
return tmpNode;
}


SNode* InsertSplay(SNode* root,int data){

root=Search(root,data);
SNode* tmpNode;
if(root==NULL){

return NewNode(data);
}

if(root->data< data){
tmpNode=NewNode(data);
tmpNode->right=root->right;
tmpNode->left=root;
root->right=NULL;
root=tmpNode;
return root;
}else{

tmpNode=NewNode(data);
tmpNode->left=root->left;
tmpNode->right=root;
root->left=NULL;
root=tmpNode;
return root;



}

}

void Traverse(SNode* root){
if(root==NULL){
return;
}

printf("%d  ",root->data);
Traverse(root->left);
Traverse(root->right);
}

int main(){

int n;
printf("\nEnter the number of nodes you want to enter : ");
scanf("%d",&n);

int i;
int data;
SNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data for your node : ");
scanf("%d",&data);
root=InsertSplay(root,data);
}

printf("\nPress enter to traverse : \n");
Traverse(root);
getch();
printf("\nEnter a number to search : ");
scanf("%d",&data);
root=Search(root,data);
printf("\nPress enter to traverse \n");
getch();

Traverse(root);
getch();
return 0;
}
