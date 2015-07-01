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


struct StackNode{

TNode* data;
struct StackNode* next;

};
typedef struct StackNode SNode;

void Push(SNode** stack,TNode* data){
    SNode* newNode=(SNode*)malloc(sizeof(SNode));
    newNode->data=data;

if(!(*stack)){
newNode->next=NULL;
(*stack)=newNode;
}
else{
newNode->next=(*stack);
(*stack)=newNode;
}

}

TNode* Pop(SNode** stack){
SNode* tmpNode=(*stack);
TNode* tmpData=(*stack)->data;
(*stack)=(*stack)->next;

free(tmpNode);
return tmpData;



}

int IsEmptyStack(SNode* stack){
return stack==NULL;
}


void MergeBStS(TNode* root,TNode* root1,int n,int m){

SNode* stack1=NULL;
SNode* stack2=NULL;

TNode* current1=root;
TNode* current2=root1;

if(root==NULL){
InorderTraversal(root1);
return;
}

if(root1==NULL){
InorderTraversal(root);
return;
}

while(current1!=NULL && !IsEmptyStack(stack1)  || current2!=NULL && !IsEmptyStack(stack2)){

if(current1!=NULL || current2!=NULL){

if(current1!=NULL){
Push(&stack1,current1);
current1=current1->left;

}

if(current2!=NULL){
Push(&stack2,current2);
current2=current2->left;
}


}else{

if(IsEmptyStack(stack1)){
while(!IsEmptyStack(stack2)){
printf("%d  ",Pop(&stack2));
}
return;
}

if(IsEmptyStack(stack2)){
while(!IsEmptyStack(stack1)){
printf("%d  ",Pop(&stack1));
}
return;
}


}

current1=Pop(&stack1);
current2=Pop(&stack2);


if(current1->data<current2->data){
printf("%d  ",current1->data);
current1=current1->right;
Push(&stack2,current2);
current2=NULL;
}else{
printf("%d  ",current2->data);
current2=current2->right;
Push(&stack1,current1);
current1=NULL;

}

}






}

int main(){
printf("\nEnter the no of nodes you want to insert in first BST: ");
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

printf("\nEnter the no of nodes you want to insert in second BST: ");
int m;
scanf("%d",&m);
TNode* root1=NULL;
for(i=0;i<m;i++){
printf("\nEnter data for %d node : ",i);
scanf("%d",&data);
Insert(&root1,data);
}
printf("\n%d nodes inserted in BST\n");
getch();
printf("\nPress enter to traverse first BST\n\n: ");
getch();
InorderTraversal(root);
getch();
printf("\nPress enter to traverse second BST\n\n: ");
getch();
InorderTraversal(root1);
getch();
printf("\n\n");
printf("\nPress enter to merge two BSTs\n\n");
getch();
MergeBSTs(root,root1,n,m);
getch();
return 0;
}
