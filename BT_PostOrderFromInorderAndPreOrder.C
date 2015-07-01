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

int GetIndex(int* Inorder,int start,int end,int data){

int i;
for(i=start;i<=end;i++){
if(Inorder[i]==data){
break;
}
}
return i;
}
void PostFromPreAndIn_Order(int* Inorder,int* Preorder,int start,int end,int* index){
if(start>end){
return;
}
int data=Preorder[*index];
int pivot=GetIndex(Inorder,start,end,Preorder[(*index)++]);
if(start!=end){
PostFromPreAndIn_Order(Inorder,Preorder,start,pivot-1,index);
PostFromPreAndIn_Order(Inorder,Preorder,pivot+1,end,index);
}
printf("%d  ",data);

}
/*
struct TNode* Top(SNode* stack){
return stack->data;
}


void PostOrder(struct TNode* root){
SNode* stack=NULL;

while(1){

while(root){
Push(&stack,root);
root=root->left;
}
if(IsEmptyStack(stack)){
break;
}else{
if(Top(stack)->right==NULL){
    root=Pop(&stack);
    printf("%d  ",root->data);

    while(!IsEmptyStack(stack) && Top(stack)->right==root){
    root=Pop(&stack);
    printf("%d  ",root->data);
    }



}
}

if(IsEmptyStack(stack)){
root=NULL;
}
else{
root=Top(stack)->right;
}

}
}
*/

int main(){


struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert : ");
int n;
scanf("%d",&n);

int i,data;
printf("\nEnter inorder :\n ");
int *inorder=(int*)malloc(sizeof(int)*n);
int *preorder=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
scanf("%d",&inorder[i]);
}
printf("\nEnter preorder : \n");
for(i=0;i<n;i++){
scanf("%d",&preorder[i]);
}
/*
int preIndex=0;
root=PostFromPreAndIn_Order(inorder,preorder,0,n-1,&preIndex);
*/
printf("\nPostOrder Traversal \n\n");
getch();
int preIndex=0;
PostFromPreAndIn_Order(inorder,preorder,0,n-1,&preIndex);
/*
printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();

printf("\n\nPostorder:\n\n");
PostOrder(root);
*/
return 0;
}
