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

struct StackNode{
struct TNode* data;
struct StackNode* next;
};
typedef struct StackNode SNode;

int IsEmptyStack(SNode* stack){
return stack==NULL;
}

void Push(SNode** stack,struct TNode* data){
SNode* newNode=(SNode*)malloc(sizeof(SNode));
newNode->data=data;

if(IsEmptyStack(*stack)){
newNode->next=NULL;
(*stack)=newNode;
}else{
newNode->next=(*stack);
(*stack)=newNode;
}

}

struct TNode* Pop(SNode** stack){
    if(!IsEmptyStack(*stack)){
SNode* tmpNode=(*stack);
struct TNode* tmpData=tmpNode->data;
(*stack)=tmpNode->next;
free(tmpNode);
return tmpData;
    }
}

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
int max(int a,int b){
return a>b?a:b;
}


int Height(struct TNode* root){
if(!root){
return 0;
}
return max(Height(root->left),Height(root->right))+1;
}

void PickNodes(struct TNode* root,SNode** stack,int level){
if(!root){
return;
}
if(level==1){
Push(&(*stack),root);
return;
}
if(level>1){
if(root->left){
PickNodes(root->left,&(*stack),level-1);
}
if(root->right){
PickNodes(root->right,&(*stack),level-1);
}
}

}

void PutNodes(struct TNode** root,SNode** stack,int level){
if(!(*root)){
return;
}
if(level==1){
    printf("\nInitially root data : %d \n",(*root)->data);
    struct TNode* tmpNode=Pop((stack));
(*root)->data=tmpNode->data;
  printf("\Finally root data : %d \n",tmpNode->data);
return;
}
if(level>1){
if((*root)->left){
PutNodes(&(*root)->left,stack,level-1);
}
if((*root)->right){
PutNodes(&(*root)->right,stack,level-1);
}
}
}
void ReverseAlternateLevels(struct TNode** root){
int i;
int height=Height((*root));
for(i=1;i<=height;i++){
if(i%2==0){
SNode* stack=NULL;
PickNodes(*root,&stack,i);
/*
printf("\nPrinting\n");
while(!IsEmptyStack(stack)){
printf("\nPopped : %d",Pop(&stack)->data);
}
printf("\nPrinting\n");

PutNodes(&(*root),&stack,i);
}
}
}
*/

void PickNodes(struct TNode* root,int* buffer,int* index,int level){
if(!root){
return;
}
PickNodes(root->left,buffer,index,level+1);
if(level&1){
buffer[(*index)++]=root->data;
}
PickNodes(root->right,buffer,index,level+1);
}

void PutNodes(struct TNode** root,int* buffer,int* index,int level){
if(!(*root)){
return;
}
PutNodes(&(*root)->left,buffer,index,level+1);
if(level&1){
(*root)->data=buffer[--(*index)];
}
PutNodes(&(*root)->right,buffer,index,level+1);
}


void ReverseAlternateLevels(struct TNode** root,int n){

int* buffer=(int*)malloc(sizeof(int)*n);
int index=0;

PickNodes((*root),buffer,&index,0);
PutNodes(&(*root),buffer,&index,0);
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
printf("\nReverse Alternate Levels\n");
getch();

ReverseAlternateLevels(&root,n);
printf("\nReversed\n");
getch();
printf("\nTraverse modified\n");
getch();
LevelOrderTraversal(root,n);
getch();
return 0;
}
