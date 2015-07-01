#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

struct TreeNode{
int data;
struct TreeNode* left,* right;
};
typedef struct TreeNode TNode;

TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}

int IsLeafNode(TNode* root){
return root->left==NULL && root->right==NULL;
}

int max(int a,int b){
return (a>b)?a:b;
}

TNode* GetTournament(int Array[],int height,int* index,int limitHeight){

if(height>limitHeight){
return NULL;
}

TNode* left=GetTournament(Array,height+1,index,limitHeight);
TNode* right=GetTournament(Array,height+1,index,limitHeight);

TNode* root;

if(height==limitHeight){
root=NewNode(Array[(*index)++]);
}
else{
root=NewNode(max(left->data,right->data));
}

root->left=left;
root->right=right;
return root;
}


void InOrder(TNode* root){
if(!root){
return;
}
InOrder(root->left);
printf("%d  ",root->data);
InOrder(root->right);
}


void GetSecondWinner(TNode* root,int Winner,int* secondWinner){
if(!root->left && !root->right){
return;
}

if(root->right->data==Winner){
if(root->left->data> (*secondWinner)){
(*secondWinner)=root->left->data;
}
GetSecondWinner(root->right,Winner,secondWinner);
}
if(root->left->data==Winner){
if(root->right->data> (*secondWinner)){
(*secondWinner)=root->right->data;
}
GetSecondWinner(root->left,Winner,secondWinner);
}
}

int main(){
int Array[]={1,4,6,8,9,10,11,4};

int n=sizeof(Array)/sizeof(Array[0]);

int index=0;
int height=log2(n);
//printf("%d",height);

TNode* Winner=GetTournament(Array,0,&index,height);

printf("\nWinner is : %d",Winner->data);

printf("\n\n");
InOrder(Winner);
getch();

printf("\nFind Second winner");
int SecondWinner=0;
GetSecondWinner(Winner,Winner->data,&SecondWinner);
printf("\nSecond Winner is : %d",SecondWinner);
return 0;
}
