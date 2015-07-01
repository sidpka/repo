#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct TreeNode{
int data;
struct TreeNode* left,*right;
int leftCount;
};
typedef struct TreeNode TNode;

TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->right=NULL;
newNode->left=NULL;
newNode->leftCount=0;
return newNode;
}

void Insert(TNode** root,int data){
if(!(*root)){
(*root)=NewNode(data);
}else{
if((*root)->data>data){
    (*root)->leftCount++;
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


TNode* GetSuccessor(TNode* root,int key,int* set){
if(!root){
return NULL;
}
TNode* left=GetSuccessor(root->left,key,set);
if((*set)){
(*set)=0;
return root;
}
if(root->data==key){
(*set)=1;
return NULL;
}
TNode* right=GetSuccessor(root->right,key,set);
return left!=NULL?left:right;
}

int KSmallestAugmented(TNode* root,int K)
{
    if(!root){
    return -1;
    }

   if(root->leftCount+1 ==K){
   return root->data;
   }else if(root->leftCount+1<K){
   return KSmallestAugmented(root->right,K-(root->leftCount+1));
   }else{
   return KSmallestAugmented(root->left,K);
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
printf("\nEnter the value of K : ");
int K;
scanf("%d",&K);
int result=KSmallestAugmented(root,K);
printf("\nAugmented Tree used : .... %d th smallest element || Result : %d",K,result);
getch();
return 0;
}
