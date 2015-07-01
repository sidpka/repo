#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct AVL{
int data;
int height;
struct AVL* left;
struct AVL* right;

};
typedef struct AVL ANode;

ANode* NewNode(int data){
ANode* newNode=(ANode*)malloc(sizeof(ANode));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
newNode->height=1;
return newNode;
}

int max(int a,int b){
return a>b?a:b;
}

int Height(ANode* node){
    if(node==NULL){
    return 0;
    }

return node->height;
}

int BFactor(ANode* node){
if(node==NULL){
return 0;
}

return Height(node->left)-Height(node->right);
}

ANode* LeftRotate(ANode* node){
ANode* tmp1=node->right;
ANode* tmp2=tmp1->left;
tmp1->left=node;
node->right=tmp2;

node->height=max(Height(node->left),Height(node->right))+1;
tmp1->height=max(Height(tmp1->left),Height(tmp1->right))+1;

return tmp1;

}

ANode* RightRotate(ANode* node){

ANode* tmp1=node->left;
ANode* tmp2=tmp1->right;

tmp1->right=node;
node->left=tmp2;

node->height=max(Height(node->left),Height(node->right))+1;
tmp1->height=max(Height(tmp1->left),Height(tmp1->right))+1;

return tmp1;



}


ANode* InsertAVL(ANode* root,int data){
if(root==NULL){
return NewNode(data);
}


if(data< root->data){
root->left=InsertAVL(root->left,data);
}else if(data> root->data){
root->right=InsertAVL(root->right,data);
}

root->height=max(Height(root->left),Height(root->right))+1;
int bf=BFactor(root);
if(bf>1 && data< root->left->data){
return RightRotate(root);
}

if(bf<-1 && data> root->right->data){
return LeftRotate(root);
}

if(bf > 1 && data > root->left->data){
root->left=RightRotate(root->left);
return LeftRotate(root);
}

if(bf<-1 && data < root->right->data){

root->right=LeftRotate(root->right);
return RightRotate(root);
}

return root;
}

void Traversal(ANode* root){
if(!root){
return;
}

printf("%d  ",root->data);
Traversal(root->left);
Traversal(root->right);
}

int GetMinNode(ANode* node){
if(node==NULL){
return -1;
}

ANode* tmpNode=node;
while(tmpNode->left!=NULL){
tmpNode=tmpNode->left;
}
return tmpNode->data;
}

ANode* DeleteAVL(ANode* root,int data){
ANode* tmpNode;
if(root==NULL){
return root;
}

if(data< root->data){
root->left=DeleteAVL(root->left,data);
}else if(data>root->data){
root->right=DeleteAVL(root->right,data);
}else{
if(root->left && root->right){
root->data=GetMinNode(root->right);
root->right=DeleteAVL(root->right,root->data);
}else if(root->left){
tmpNode=root;
root=tmpNode->left;
free(tmpNode);
}else if(root->right){

tmpNode=root;
root=tmpNode->right;
free(tmpNode);

}else{
tmpNode=root;
root=NULL;
free(tmpNode);
}

}
if(root==NULL){
return root;
}


root->height=max(Height(root->left),Height(root->right))+1;

int bf=BFactor(root);


if(bf>1 && BFactor(root->left)>=0){
return RightRotate(root);
}

if(bf<-1 && BFactor(root->right) <=0){
return LeftRotate(root);
}

if(bf>1 && BFactor(root->left)<0){
root->left=LeftRotate(root->left);
return RightRotate(root);
}

if(bf<-1 && BFactor(root->right)>0){
root->right=RightRotate(root->right);
return LeftRotate(root);
}


return root;
}

int main(){

int n;
printf("\nEnter the number of nodes you want to enter : ");
scanf("%d",&n);
ANode* root=NULL;
int i;
int data;
for(i=0;i<n;i++){
printf("\nEnter data for your node : ");
scanf("%d",&data);
root=InsertAVL(root,data);
}

printf("\nPress enter to do traversal : \n");
getch();
Traversal(root);
getch();

printf("\nEnter data you want to delete : ");
scanf("%d",&data);

root=DeleteAVL(root,data);
printf("\nPress enter to traverse : \n");
getch();
Traversal(root);


return 0;
}
