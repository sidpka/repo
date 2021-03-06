#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

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

int max(int a,int b){
return a>b?a:b;
}

int Height(struct TNode* root){
if(!root){
return 0;
}
return max(Height(root->left),Height(root->right))+1;
}
int FindDiameter(struct TNode* root){
if(!root){
return 0;
}
int lHeight=Height(root->left);
int rHeight=Height(root->right);
int lDiameter=FindDiameter(root->left);
int rDiameter=FindDiameter(root->right);
return max(lHeight+rHeight+1,max(lDiameter,rDiameter));
}

int FindDiameterOptimised(struct TNode* root,int* height){
    int lHeight=0;
    int rHeight=0;


if(!root){
    (*height)=0;
return 0;
}

int lDiameter=FindDiameterOptimised(root->left,&lHeight);
int rDiameter=FindDiameterOptimised(root->right,&rHeight);

(*height)=max(lHeight,rHeight)+1;

return max(lHeight+rHeight+1,max(lDiameter,rDiameter));
}

int CheckforHeightBalance(struct TNode* root,int* height){

int lHeight=0;
int rHeight=0;

if(!root){
(*height)=0;
return 1;
}


int left=CheckforHeightBalance(root->left,&lHeight);
int right=CheckforHeightBalance(root->right,&rHeight);

if((left&1) && (right&1)){
    (*height)=max(lHeight,rHeight)+1;
if(abs(lHeight-rHeight)<=1){
return 1;
}else{
return 0;
}
return 0;
}
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

/*
struct TNode* tmpNode=(struct TNode*)malloc(sizeof(struct TNode));
tmpNode->data=15;
tmpNode->left=NULL;
tmpNode->right=NULL;
root->left->left->left=tmpNode;
*/

printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();
printf("\nCheck if binary tree is height balanced : \n\n");
int height=0;
int result=CheckforHeightBalance(root,&height);
getch();
if(result){
printf("\nYes Height Balanced\n");
}else{
printf("\No.. not height balanced..\n");
}
getch();
return 0;
}
