#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

struct TNode{

int data;
struct TNode* left;
struct TNode* right;
};
//typedef struct TreeNode TNode;

struct QueueNode{
int capacity;
int front;
int rear;
struct TNode** Array;
};
typedef struct QueueNode QNode;


QNode* CreateQueue(int capacity){
QNode* queue=(QNode*)malloc(sizeof(QNode));
if(!queue){
printf("\nMemory Error\n\n");
}
queue->capacity=capacity;
queue->front=-1;
queue->rear=-1;
queue->Array=(struct TNode**)malloc(sizeof(struct TNode*)*queue->capacity);
int i;
for(i=0;i<queue->capacity;i++){
queue->Array[i]=(struct TNode*)malloc(sizeof(struct TNode));
}

return queue;
}

int IsEmptyQueue(QNode* queue){
return queue->front==-1;
}

int IsFullQueue(QNode* queue){
return (queue->rear+1)%queue->capacity==queue->front;
}

void ResizeQueue(QNode* queue){



queue->Array=(struct TNode**)realloc(queue->Array,queue->capacity*2);
int i;
for(i=queue->capacity;i<queue->capacity*2;i++){
queue->Array[i]=(struct TNode*)malloc(sizeof(struct TNode));
}
//printf("\nhere\n");
if(queue->front>queue->rear){
int i;

for(i=0;i<queue->front;i++){
queue->Array[i+queue->capacity]=queue->Array[i];
}
queue->rear=queue->capacity+i;
}
queue->capacity*=2;
}

void EnQueue(QNode* queue,struct TNode* node){

if((queue->rear+1)%queue->capacity==queue->front){
ResizeQueue(queue);
}
queue->rear=(queue->rear+1)%queue->capacity;
queue->Array[queue->rear]=node;
if(queue->front==-1){
queue->front=0;
}

}

TNode* DeQueue(QNode* queue){
if(IsEmptyQueue(queue)){
printf("\nNo data");
return NULL;
}else{struct TNode* data=queue->Array[queue->front];

if(queue->front==queue->rear){
queue->front=-1;
queue->rear=-1;
}else{
queue->front=(queue->front+1)%queue->capacity;
}

return data;
}
}

void DeleteQueue(QNode* queue){
int i;
for(i=0;i<queue->capacity;i++){
free(queue->Array[i]);
}
free(queue->Array);
free(queue);

}
void InsertBinaryTree(TNode** root,int data,int n){

if((*root)==NULL){
(*root)=(struct TNode*)malloc(sizeof(TNode));
(*root)->data=data;
(*root)->left=NULL;
(*root)->right=NULL;
return;
}

QNode* queue=CreateQueue(n);
EnQueue(queue,(*root));
struct TNode* node=(struct TNode*)malloc(sizeof(TNode));
node->left=NULL;
node->right=NULL;
node->data=data;
struct TNode* tmpNode;
while(!IsEmptyQueue(queue)){
tmpNode=DeQueue(queue);
if(!tmpNode->left){
tmpNode->left=node;
return;
}else{
EnQueue(queue,tmpNode->left);
}

if(!tmpNode->right){
  tmpNode->right=node;
return;
}else{
EnQueue(queue,tmpNode->right);
}
}


}

void LevelOrderTraversal(struct TNode* root,int n){

if(!root){
return;
}

QNode* queue=CreateQueue(n);
EnQueue(queue,root);

struct TNode* tmpNode;

while(!IsEmptyQueue(queue)){

tmpNode=DeQueue(queue);
if(tmpNode){
printf("%d   ",tmpNode->data);
}
if(tmpNode->left){
EnQueue(queue,tmpNode->left);
}
if(tmpNode->right){
EnQueue(queue,tmpNode->right);
}

}




}

int FindSize(struct TNode* root){

int left,right;
if(!root){
return 0;
}

left=FindSize(root->left);
right=FindSize(root->right);

return left+right+1;
}

struct TNode* GetLeft(struct TNode* root){

if(!root){
return NULL;
}else{

while(root->left){
root=root->left;
}
return root;
}
}

struct TNode* GetRight(struct TNode* root){

if(!root){
return NULL;
}else{

while(root->right){
root=root->right;
}
return root;
}
}


int IsBST(struct TNode* root){
if(!root){
return 1;
}

if(root->left && root->data< GetRight(root->left)->data){
return 0;
}

if(root->right && root->data > GetLeft(root->right)->data){
return 0;
}
return IsBST(root->left) && IsBST(root->right);
//return 1;
}

int max(int a,int b){
return a>b?a:b;
}
/*
int MaxBST(struct TNode* root){

if(!root){
return 0;
}

if(IsBST(root)){
return FindSize(root);
}
return max(MaxBST(root->left),MaxBST(root->right));
}
*/

int MaxBSTUtil(struct TNode* root,int* minRef,int* maxRef,int* maxSize,int* isBST){
if(!root){
(*isBST)=1;
return 0;
}

int ls,rs;
int isLeftBST=0;
int isRightBST=0;
int tmpMin;
*maxRef=INT_MIN;
ls=MaxBSTUtil(root->left,minRef,maxRef,maxSize,isBST);
if((*isBST) && root->data > (*maxRef)){
isLeftBST=1;
}
tmpMin=(*minRef);
*minRef=INT_MAX;
rs=MaxBSTUtil(root->right,minRef,maxRef,maxSize,isBST);
if((*isBST) && root->data < (*minRef)){
isRightBST=1;
}

if(tmpMin<(*minRef)){
(*minRef)=tmpMin;
}
if(root->data<(*minRef)){
(*minRef)=root->data;
}
if(root->data > (*maxRef)){
(*maxRef)=root->data;
}


if(isLeftBST && isRightBST){

if(ls+rs+1 > (*maxSize)){
(*maxSize)=ls+rs+1;

}

return ls+rs+1;
}else{

(*isBST)=0;
return 0;
}
}

int MaxBST(struct TNode* root){

if(!root){
return 0;
}
int min=INT_MAX;
int max=INT_MIN;

int maxSize=0;
int isBST=0;
MaxBSTUtil(root,&min,&max,&maxSize,&isBST);
return maxSize;
}
int main(){


struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert : ");
int n;
scanf("%d",&n);

int i,data;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
InsertBinaryTree(&root,data,n);
}

printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();
printf("\nPress enter to see max size of BST in given binary tree\n\n");
int result=MaxBST(root);
getch();
printf("\nSize of MaxBST : %d",result);
return 0;
}
