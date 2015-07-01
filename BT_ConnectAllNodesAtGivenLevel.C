#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct TNode{

int data;
struct TNode* left;
struct TNode* right;
struct TNode* adjacent;
};
//typedef struct TreeNode TNode;

struct QueueNode{
int capacity;
int front;
int rear;
struct TNode** Array;
};
typedef struct QueueNode QNode;

struct Stack{
struct TNode* data;
struct Stack* next;
};

typedef struct Stack SNode;

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

int IsEmptyStack(SNode* stack){
return (stack==NULL);
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
(*stack)=(*stack)->next;
struct TNode* tmpData=tmpNode->data;
free(tmpNode);
return tmpData;
}
return NULL;
}

void ConnectAdjacent(struct TNode* root,int n){
QNode* queue1=CreateQueue(n);
QNode* queue2=CreateQueue(n);
int level=1;
EnQueue(queue1,root);
struct TNode* prev=NULL;
struct TNode* tmpNode;
while(!IsEmptyQueue(queue1) || (!IsEmptyQueue(queue2))){
if(level&1){
tmpNode=DeQueue(queue1);
if(prev!=NULL){
prev->adjacent=tmpNode;
prev=tmpNode;
}else{
prev=tmpNode;
}

if(tmpNode->left){
EnQueue(queue2,tmpNode->left);
}
if(tmpNode->right){
EnQueue(queue2,tmpNode->right);
}
if(IsEmptyQueue(queue1)){
tmpNode->adjacent=NULL;
prev=NULL;
level++;
continue;
}
}
//for even levels
if(!(level&1)){
tmpNode=DeQueue(queue2);
if(prev!=NULL){
prev->adjacent=tmpNode;
prev=tmpNode;
}else{
prev=tmpNode;
}

if(tmpNode->left){
EnQueue(queue1,tmpNode->left);
}
if(tmpNode->right){
EnQueue(queue1,tmpNode->right);
}
if(IsEmptyQueue(queue2)){
tmpNode->adjacent=NULL;
prev=NULL;
level++;
continue;
}
}
}


}




int main(){


struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert in Tree: ");
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
printf("\nPress enter to do level-order traversal of Tree : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();
printf("\nPress enter to connect all adjacent nodes :\n\n");
ConnectAdjacent(root,n);
getch();
printf("\nAll adjacent nodes connected  ");
getch();
/*
printf("\n%d ",root->data);
printf("\n%d  ",root->left->data);
printf("%d  ",root->left->adjacent->data);
printf("\n%d  ",root->left->left->data);
printf("%d  ",root->left->left->adjacent->data);
printf("%d  ",root->left->left->adjacent->adjacent->data);
printf("%d  ",root->left->left->adjacent->adjacent->adjacent->data);
printf("\n%d  ",root->left->left->left->data);
printf("%d  ",root->left->left->left->adjacent->data);
printf("%d  ",root->left->left->left->adjacent->adjacent->data);
printf("%d  ",root->left->left->left->adjacent->adjacent->adjacent->data);
*/
return 0;
}
