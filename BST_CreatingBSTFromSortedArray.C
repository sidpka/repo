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


int GetMid(int start,int end){
return (end-start)/2 ;
}

TNode* CreateTree(int Array[],int start,int end){
if(start>end){
return NULL;
}
TNode* root;
if(start==end){
root=NewNode(Array[start]);
}
else{
    int pivot=GetMid(start,end);
    root=NewNode(Array[pivot+start]);
root->left=CreateTree(Array,start,start+pivot-1);
root->right=CreateTree(Array,start+pivot+1,end);
}
return root;
}

void Inorder(TNode* root){

if(!root){
return;
}

Inorder(root->left);
printf("%d  ",root->data);
Inorder(root->right);

}

int main(){
printf("\nEnter the no of nodes you want to insert : ");
int n;
scanf("%d",&n);
int i,data;
TNode* root=NULL;

int Array[5]={1,4,7,8,9};

root=CreateTree(Array,0,sizeof(Array)/sizeof(Array[0])-1);
printf("\nTree created");

getch();
printf("\nPress enter to traverse\n");
Inorder(root);
getch();
return 0;
}
