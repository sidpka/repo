#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


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

int FindIndex(int* postorder,int start,int end,int data){
int i;
for(i=start;i<=end;i++){
if(postorder[i]==data){
break;
}
}
return i;
}

/*
struct TNode* CreateTree(int* preorder,int* postorder,int postStartIndex,int postEndIndex,int* preOrderIndex){

//printf("\nHere for preorder : %d\n",preorder[*preOrderIndex]);
struct TNode* newNode=(struct TNode*)malloc(sizeof(struct TNode));
int index=(*preOrderIndex)++;
newNode->data=preorder[index];

if(postStartIndex==postEndIndex){
newNode->left=NULL;
newNode->right=NULL;
}
else{
int dataIndex,leftIndexPivot,rightIndexPivot;
dataIndex=postStartIndex+((int)(postEndIndex-postStartIndex)/2);
leftIndexPivot=dataIndex-1;
rightIndexPivot=dataIndex;

newNode->left=CreateTree(preorder,postorder,postStartIndex,leftIndexPivot,preOrderIndex);
newNode->right=CreateTree(preorder,postorder,rightIndexPivot,postEndIndex-1,preOrderIndex);
}
return newNode;
}
*/

struct TNode* CreateTree(int* preorder,int* postorder,int postStartIndex,int postEndIndex,int* preOrderIndex,int size){

if(*preOrderIndex>=size || postStartIndex>postEndIndex){
return NULL;
}
//printf("\nHere for preorder : %d\n",preorder[*preOrderIndex]);
struct TNode* newNode=(struct TNode*)malloc(sizeof(struct TNode));
int index=(*preOrderIndex)++;
newNode->data=preorder[index];

if(postStartIndex==postEndIndex){
newNode->left=NULL;
newNode->right=NULL;
}
else{
int dataIndex,leftIndexPivot,rightIndexPivot;
dataIndex=FindIndex(postorder,postStartIndex,postEndIndex,preorder[*preOrderIndex]);
leftIndexPivot=dataIndex;
rightIndexPivot=dataIndex+1;
newNode->left=CreateTree(preorder,postorder,postStartIndex,leftIndexPivot,preOrderIndex,size);
newNode->right=CreateTree(preorder,postorder,rightIndexPivot,postEndIndex-1,preOrderIndex,size);
}
return newNode;
}


int main(){

struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert : ");
int n;
scanf("%d",&n);

int i;
printf("\nEnter preorder traversal...\n");
int* preorder=(int*)malloc(sizeof(int)*n);
int* postorder=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
scanf("%d",&preorder[i]);
}

printf("\nPreorder sequence taken\n\n");
getch();
printf("\nEnter postorder traversal\n\n");
for(i=0;i<n;i++){
scanf("%d",&postorder[i]);
}
printf("\nPostorder sequence taken\n");
getch();

printf("\nPress enter to create tree\n");
getch();
int preOrderIndex=0;
int postOrderStartIndex=0;
int postOrderEndIndex=n-1;
root=CreateTree(preorder,postorder,postOrderStartIndex,postOrderEndIndex,&preOrderIndex,n);

printf("\nTree Created\n\n");
getch();
printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();

return 0;
}
