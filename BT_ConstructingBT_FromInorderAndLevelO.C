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


/*
struct TNode* CreateTree(int* inOrder,int sIndex,int eIndex,int* levelOrder,int levelIndex,int n){
if(sIndex>eIndex || levelIndex>=n){
return NULL;
}

struct TNode* newNode=(struct TNode*)malloc(sizeof(struct TNode));
newNode->data=levelOrder[levelIndex];
int pivot=GetIndex(inOrder,sIndex,eIndex,levelOrder[levelIndex]);
newNode->left=CreateTree(inOrder,sIndex,pivot-1,levelOrder,2*levelIndex+1,n);
newNode->right=CreateTree(inOrder,pivot+1,eIndex,levelOrder,2*levelIndex+2,n);

return newNode;

}
*/

struct TNode* CreateNode(int data){
struct TNode* newNode=(struct TNode*)malloc(sizeof(struct TNode));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}

int GetIndex(int* inOrder,int sIndex,int eIndex,int data){
int i;
int index=-1;
for(i=sIndex;i<=eIndex;i++){
if(inOrder[i]==data){
index=i;
break;
}
}
return index;
}

/*
int GetRootNode(int* inOrder,int sIndex,int lIndex,int* levelOrder,int n){
int i;

for(i=0;i<n;i++){
if(GetIndex(inOrder,sIndex,lIndex,levelOrder[i]!=-1)){
    printf("\ngetting root : %d for index : %d",levelOrder[i],i);
return levelOrder[i];
}
}
}
*/

/*
int GetRootNode(int* inOrder,int sIndex,int lIndex,int* levelOrder,int n){
int i;
int j;
for(i=0;i<n;i++){
for(j=sIndex;j<=lIndex;j++){
if(levelOrder[i]==inOrder[j]){
return levelOrder[i];
}
}
}
}
*/

int GetRootNode(int* inOrder,int sIndex,int lIndex,int* levelOrder,int n){
int i;
int j;
int result;
for(i=0;i<n;i++){
  result=GetIndex(inOrder,sIndex,lIndex,levelOrder[i]);
  if(result!=-1){
  result=levelOrder[i];
  break;
  }
}
return result;
}

int* GetLevelOrder(int* inOrder,int sIndex,int lIndex,int* levelOrder,int n){
int* lOrder=(int*)malloc(sizeof(int)* lIndex);

int i;
int j=0;
int result;
for(i=0;i<n;i++){
result=GetIndex(inOrder,sIndex,lIndex-1,levelOrder[i]);
if(result!=-1){
lOrder[j++]=levelOrder[i];
}

}
return lOrder;
}

struct TNode* BuildTree(int* inOrder,int sIndex,int lIndex,int* levelOrder,int n){
if(sIndex>lIndex){
return NULL;
}
//printf("\nStarting : %d",rootNodeData);
struct TNode* root=CreateNode(levelOrder[0]);
if(sIndex==lIndex){
return root;
}

int pivot=GetIndex(inOrder,sIndex,lIndex,root->data);
//printf("\nPivot : %d",pivot);
//int leftRootData=GetRootNode(inOrder,sIndex,pivot-1,levelOrder,n);
//int rightRootData=GetRootNode(inOrder,pivot+1,lIndex,levelOrder,n);
//printf("\nleft : %d  right: %d",leftRootData,rightRootData);

int* levelOrderLeft=GetLevelOrder(inOrder,sIndex,pivot,levelOrder,n);
int* levelOrderRight=GetLevelOrder(inOrder,pivot+1,lIndex+1,levelOrder,n);

root->left=BuildTree(inOrder,sIndex,pivot-1,levelOrderLeft,(pivot-sIndex));
root->right=BuildTree(inOrder,pivot+1,lIndex,levelOrderRight,(lIndex-pivot));

//root->left=BuildTree(inOrder,sIndex,pivot-1,levelOrder,leftRootData,n);
//root->right=BuildTree(inOrder,pivot+1,lIndex,levelOrder,rightRootData,n);
free(levelOrderLeft);
free(levelOrderRight);
return root;
}
/*
struct TNode* BuildTree(int* inOrder,int sIndex,int lIndex,int* levelOrder,int rootNodeData,int n){
if(sIndex>lIndex){
return NULL;
}
printf("\nStarting : %d",rootNodeData);
struct TNode* root=CreateNode(rootNodeData);
if(sIndex==lIndex){
return root;
}

int pivot=GetIndex(inOrder,sIndex,lIndex,rootNodeData);
//printf("\nPivot : %d",pivot);
int leftRootData=GetRootNode(inOrder,sIndex,pivot-1,levelOrder,n);
int rightRootData=GetRootNode(inOrder,pivot+1,lIndex,levelOrder,n);
//printf("\nleft : %d  right: %d",leftRootData,rightRootData);

root->left=BuildTree(inOrder,sIndex,pivot-1,levelOrder,leftRootData,n);
root->right=BuildTree(inOrder,pivot+1,lIndex,levelOrder,rightRootData,n);
return root;
}
*/
int main(){


struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert : ");
int n;
scanf("%d",&n);

int i,data;
int* inOrder=(int*)malloc(sizeof(int)*n);
int* levelOrder=(int*)malloc(sizeof(int)*n);

printf("\nEnter inorder data : \n");
for(i=0;i<n;i++){
scanf("%d",&inOrder[i]);
}
printf("\nEnter data for levelorder :\n");
for(i=0;i<n;i++){
scanf("%d",&levelOrder[i]);
}
/*
int levelOrderIndex=0;
 This method works for complete binary tree
root=CreateTree(inOrder,0,n-1,levelOrder,levelOrderIndex,n);

*/
//This method works for all kind of trees
root =BuildTree(inOrder,0,n-1,levelOrder,n);
getch();
printf("\nInserted... %d nodes \n",n);
printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();

return 0;
}
