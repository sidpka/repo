#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

struct TNode{

int data;
struct TNode* left;
struct TNode* right;
int HD;
};
//typedef struct TreeNode TNode;

struct QueueNode{
int capacity;
int front;
int rear;
struct TNode** Array;
};
typedef struct QueueNode QNode;

struct ListNode{
int data;
struct ListNode* next;
};
typedef struct ListNode LNode;

struct HashNode{
LNode** HArray;
};
typedef struct HashNode HNode;


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

void GetHash(struct TNode* root,HNode* hash,int n){
if(!root){
return;
}

QNode* queue=CreateQueue(n);
root->HD=0;
EnQueue(queue,root);
struct TNode* tmpNode;
while(!IsEmptyQueue(queue)){
tmpNode=DeQueue(queue);

if(hash->HArray[tmpNode->HD]->next==NULL){
LNode* node=(LNode*)malloc(sizeof(LNode));
node->data=tmpNode->data;
node->next=NULL;
hash->HArray[tmpNode->HD]->next=node;
}
if(tmpNode->left){
tmpNode->left->HD=tmpNode->HD-1;
EnQueue(queue,tmpNode->left);
}
if(tmpNode->right){
tmpNode->right->HD=tmpNode->HD+1;
EnQueue(queue,tmpNode->right);
}
}


}

struct TNode* NewNode(int data){
struct TNode* newNode=(struct TNode*)malloc(sizeof(struct TNode));
newNode->data=data;
newNode->HD=-10;
newNode->left=NULL;
newNode->right=NULL;
}


int main(){


struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert : ");
int n;
scanf("%d",&n);

int i,data;
/*
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
InsertBinaryTree(&root,data,n);
}
*/

root=NewNode(1);
root->left=NewNode(2);
root->right=NewNode(3);
root->left->right=NewNode(4);
root->left->right->right=NewNode(5);
root->left->right->right->right=NewNode(6);
printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();
HNode* hash=(HNode*)malloc(sizeof(HNode));

hash->HArray=(LNode**)malloc(sizeof(LNode*)*2*n);

for(i=-n;i<n;i++){
hash->HArray[i]=(LNode*)malloc(sizeof(LNode));
hash->HArray[i]->next=NULL;
}


GetHash(root,hash,n);
printf("\nTOp View\n\n");
for(i=-n;i<n;i++){
if(hash->HArray[i]->next!=NULL){
printf("\n\nHD: %d || data :  %d  ",i,hash->HArray[i]->next->data);
}
}

for(i=-n;i<n;i++){
free(hash->HArray[i]);
}
free(hash->HArray);
free(hash);
return 0;
}
