#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct TNode{

int data;
struct TNode* left;
struct TNode* right;
int isVisited;
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
(*root)->isVisited=0;
return;
}

QNode* queue=CreateQueue(n);
EnQueue(queue,(*root));
struct TNode* node=(struct TNode*)malloc(sizeof(TNode));
node->left=NULL;
node->right=NULL;
node->data=data;
node->isVisited=0;
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

int IsLeafNode(struct TNode* node){
return (node->right==NULL && node->left==NULL);
}

void PrintNodeAtDistanceK(struct TNode* root,struct TNode** buffer,int index,int K){
if(K>=index){
return;
}

int i;
for(i=index-1;i>=0;i--){
    if(K==0 && buffer[i]->isVisited==0){
    printf("%d   ",buffer[i]->data);
    buffer[i]->isVisited=1;
    break;
    }
    K--;
}
}


void GetAllNodes(struct TNode* root,struct TNode** buffer,int index,int K){

if(!root){
return;
}
buffer[index++]=root;
if(IsLeafNode(root)){
PrintNodeAtDistanceK(root,buffer,index,K);
return;
}
GetAllNodes(root->left,buffer,index,K);
GetAllNodes(root->right,buffer,index,K);

}


void ExecuteMethod(struct TNode* root,int* Path,int index,int* Visited,int K){
if(!root){
return;
}

Path[index]=root->data;
Visited[index]=0;
index++;

if(IsLeafNode(root) && (index-K-1)>=0){
if(Visited[index-K-1]==0){
printf("%d  ",Path[index-K-1]);
Visited[index-K-1]=1;
return;
}
}

ExecuteMethod(root->left,Path,index,Visited,K);
ExecuteMethod(root->right,Path,index,Visited,K);


}

void PrintUtility(struct TNode* root,int level){
if(!root || level<0){
return;
}

if(level==0){
printf("%d   ",root->data);
return;
}

PrintUtility(root->left,level-1);
PrintUtility(root->right,level-1);

}

int PrintNodes(struct TNode* root,struct TNode* target,int K){

if(!root){
return -1;
}

if(root==target){
PrintUtility(root,K);
return 0;
}

int lDistance=PrintNodes(root->left,target,K);
if(lDistance!=-1){
if(lDistance+1==K){
printf("%d   ",root->data);
}
else{
PrintUtility(root->right,K-lDistance-1);
}
return lDistance+1;
}

int rDistance=PrintNodes(root->right,target,K);
if(rDistance!=-1){
if(rDistance+1==K){
printf("%d   ",root->data);
}
else{
PrintUtility(root->left,K-rDistance-1);
}
return rDistance+1;
}

return -1;

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
printf("\nEnter distance :   ");
int K;
scanf("%d",&K);
struct TNode* target=root->left;
PrintNodes(root,target,K);
getch();
return 0;
}
