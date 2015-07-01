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
struct stackNode{
struct TNode* data;
struct stackNode* next;
};
typedef struct stackNode SNode;

struct ListNode{
int data;
struct ListNode* next;
};
typedef struct ListNode LNode;

int IsEmptyStack(SNode* stack){
return stack==NULL;
}

void Push(SNode** stack,struct TNode* data){
SNode* newNode=(SNode*)malloc(sizeof(SNode));
newNode->data=data;
if(!(*stack)){
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
(*stack)=(*stack)->next;
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



void InsertLinkedList(LNode** head,int data,LNode** prev){
    LNode* newNode=(LNode*)malloc(sizeof(LNode));
    newNode->data=data;
    newNode->next=NULL;
if(!(*head)){
(*head)=newNode;
(*prev)=(*head);
}else{
(*prev)->next=newNode;
(*prev)=newNode;
}
}

void TraverseList(LNode* head){

LNode* tmpNode=head;

while(tmpNode){
printf("%d   ",tmpNode->data);
tmpNode=tmpNode->next;
}
}


struct TNode* ListToTree(LNode* head,int n){
struct TNode* root=NULL;
while(head){
InsertBinaryTree(&root,head->data,n);
head=head->next;
}
return root;
}

int main(){


struct TNode* root=NULL;
LNode* head=NULL;
printf("\nEnter the number of elements you want to insert in Linked List : ");
int n;
scanf("%d",&n);
LNode* prev=NULL;
int i,data;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
InsertLinkedList(&head,data,&prev);
}

printf("\nInserted... %d nodes \n",n);

getch();
printf("\nTraversing List\n\n");
getch();
TraverseList(head);
getch();

printf("\nPress enter to convert List to tree:\n\n");
getch();
root=ListToTree(head,n);
printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
getch();

return 0;
}
