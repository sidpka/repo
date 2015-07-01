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


void Push(SNode** stack,TNode* node){
SNode* newNode=(SNode*)malloc(sizeof(SNode));
newNode->data=node;
if(!(*stack)){
newNode->next=NULL;
(*stack)=newNode;
}else{
newNode->next=(*stack);
(*stack)=newNode;
}

}

struct TNode* Pop(SNode** stack){
SNode* tmpNode=(*stack);
(*stack)=(*stack)->next;
return tmpNode->data;
}

int IsEmptyStack(SNode* stack){
return stack==NULL;
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

void PreOrderTraversal(struct TNode* root,int n){
SNode* stack=NULL;
struct TNode* tmpNode;
while(1){

while(root){
printf("%d  ",root->data);
Push(&stack,root);
root=root->left;
}

if(!IsEmptyStack(stack)){
root=Pop(&stack);
root=root->right;
}else{
break;
}
}
}

void InOrderTraversal(struct TNode* root){
SNode* stack=NULL;

while(1){

while(root){
Push(&stack,root);
root=root->left;
}

if(IsEmptyStack(stack)){
break;
}

root=Pop(&stack);
printf("%d  ",root->data);
root=root->right;

}


}

struct TNode* Top(SNode* stack){
return stack->data;
}

void PostOrderTraversal(struct TNode* root){

SNode* stack=NULL;

while(1){

while(root){
Push(&stack,root);
root=root->left;
}

if(IsEmptyStack(stack)){
return;
}


if(Top(stack)->right==NULL){
root=Pop(&stack);
printf("%d  ",root->data);

if(root==Top(stack)->right){
printf("%d  ",Pop(&stack)->data);
}
}

if(!IsEmptyStack(stack)){
root=Top(stack)->right;

}
}

}

void SpiralLeveelOrder(struct TNode* root){

SNode* stack1=NULL;
SNode* stack2=NULL;

int level=1;

Push(&stack1,root);
struct TNode* tmpNode;
printf("\n\n");
while(!IsEmptyStack(stack1) || !IsEmptyStack(stack2)){
    if(level&1){
    tmpNode=Pop(&stack1);
    printf("%d  ",tmpNode->data);
    if(tmpNode->right){
    Push(&stack2,tmpNode->right);
    }
    if(tmpNode->left){
    Push(&stack2,tmpNode->left);
    }

    if(IsEmptyStack(stack1)){
    level++;
    printf("\n\n");
    }
    }
    else{

    tmpNode=Pop(&stack2);
    printf("%d  ",tmpNode->data);
    if(tmpNode->left){
    Push(&stack1,tmpNode->left);
    }
    if(tmpNode->right){
    Push(&stack1,tmpNode->right);
    }

    if(IsEmptyStack(stack2)){
    level++;
    printf("\n\n");
    }




    }

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

printf("\nInserted... %d nodes \n",n);
getch();
printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();
printf("\nPress enter to do spiral level order traversal: \n\n");
SpiralLeveelOrder(root);
getch();
return 0;
}
