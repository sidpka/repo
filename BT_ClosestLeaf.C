#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

int min(int a,int b){
return a<b?a:b;
}

int GetLeafDistance(struct TNode* root){
if(!root){
return INT_MAX;
}

if(root->left==NULL && root->right==NULL){
return 0;
}
int lR=GetLeafDistance(root->left);
int rR=GetLeafDistance(root->right);

return min(lR,rR)+1;
}


void CheckMinDistance(struct TNode** buffer,int index){
int minDistance=INT_MAX;

int i;
int tmpMin;
int pathAdder=0;
for(i=index-1;i>=0;i--){
tmpMin=GetLeafDistance(buffer[i])+pathAdder;
pathAdder++;
if(tmpMin<minDistance){
minDistance=tmpMin;
}
}

printf("\nMin Leaf Distance : %d",minDistance);
}


void ClosestLeafNode(struct TNode* root,struct TNode* target,struct TNode** buffer,int index){
if(!root){
return;
}

buffer[index++]=root;

if(root==target){
CheckMinDistance(buffer,index);
return;
}
ClosestLeafNode(root->left,target,buffer,index);
ClosestLeafNode(root->right,target,buffer,index);

}

struct TNode* newNode(int data){
struct TNode* tmpNode=(struct TNode*)malloc(sizeof(struct TNode));
tmpNode->data=data;
tmpNode->left=NULL;
tmpNode->right=NULL;
return tmpNode;
}

int main(){
printf("\nEnter the number of elements you want to insert : ");
int n;
int i,data;
scanf("%d",&n);
/*
struct TNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
InsertBinaryTree(&root,data,n);
}
*/
   struct TNode *root        = newNode(1);
    root->left               = newNode(2);
    root->right              = newNode(3);
    root->right->left        = newNode(4);
    root->right->right       = newNode(5);
    root->right->left->left  = newNode(6);
    root->right->left->left->left  = newNode(7);
    root->right->left->left->right = newNode(8);
    root->right->right->right      = newNode(9);
    root->right->right->right->left = newNode(10);




printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();

struct TNode** buffer=(struct TNode**)malloc(sizeof(struct TNode*)*n);
for(i=0;i<n;i++){
buffer[i]=(struct TNode*)malloc(sizeof(struct TNode));
}
struct TNode* target=root->right->left;
ClosestLeafNode(root,target,buffer,0);
//printf("\nResult: %d",result);
return 0;
}
