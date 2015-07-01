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

int CheckForTreeIsomorphism(struct TNode* root1,struct TNode* root2){

if(!root1 && !root2){
return 1;
}
if(!root1 || !root2){
return 0;
}

if(root1->data!=root2->data){
return 0;
}

return (CheckForTreeIsomorphism(root1->left,root2->left)&&CheckForTreeIsomorphism(root1->right,root2->right))
    ||(CheckForTreeIsomorphism(root1->left,root2->right)&&CheckForTreeIsomorphism(root1->right,root2->left));


}



struct TNode* NewNode(int data){

struct TNode* newNode=(struct TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}
int main(){


struct TNode* root=NULL;
printf("\nEnter the number of elements you want to insert : ");
struct TNode* root1=NULL;
int n;
scanf("%d",&n);

int i,data;

root=NewNode(1);
root->left=NewNode(2);
root->right=NewNode(3);
root->right->left=NewNode(6);
root->left->left=NewNode(4);
root->left->right=NewNode(5);
root->left->right->left=NewNode(7);
root->left->right->right=NewNode(8);


root1=NewNode(1);
root1->right=NewNode(2);
root1->left=NewNode(3);
root1->left->right=NewNode(6);
root1->right->left=NewNode(4);
root1->right->right=NewNode(5);
root1->right->right->right=NewNode(7);
root1->right->right->left=NewNode(8);



printf("\nInserted... %d nodes \n",n);

getch();

printf("\nPress enter to do level-order traversal : \n\n");
getch();
LevelOrderTraversal(root,n);
printf("\n\n");
LevelOrderTraversal(root1,n);
getch();
int result=CheckForTreeIsomorphism(root,root1);
if(result){
printf("\nYes Isomorphic");
}else{
printf("\nNot isomorphic");
}
return 0;
}
