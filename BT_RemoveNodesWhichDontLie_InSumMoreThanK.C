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

int max(int a,int b){
return a>b?a:b;
}
int Height(struct TNode* root){
if(!root){
return 0;
}
return max(Height(root->left),Height(root->right))+1;
}

/*
int IsLeafNode(struct TNode* root){
return root->left==NULL && root->right==NULL;
}


int GetSum(struct TNode** buffer,int index){
int i;
int sum=0;
for(i=0;i<index;i++){
sum+=buffer[i]->data;
}
printf("\n198 Sum: %d",sum);
return sum;
}

void RunDeletionProcess(struct TNode** buffer,int index){
int i;
struct TNode* tmpNode;
for(i=index-1;i>=0;i--){
if(IsLeafNode(buffer[i])){
free(buffer[i]);
buffer[i]=NULL;
}else{
break;
}
}
}

void RemoveBekarNodes(struct TNode** root,struct TNode** buffer,int K,int index){
if(!(*root)){
return;
}
printf("\n216\n");
buffer[index++]=(*root);

if(!(*root)->left && !(*root)->right){
int sum=GetSum(buffer,index);
 printf("\nEntering here: sum:%d\n",sum);
if(sum<K){

RunDeletionProcess(buffer,index);
return;
}
}
if((*root)->left){
RemoveBekarNodes(&(*root)->left,buffer,K,index);
}
if((*root)->right){
RemoveBekarNodes(&(*root)->right,buffer,K,index);
}
}
*/
struct TNode* RemoveNodes(struct TNode* root,int K,int* sum){
if(root==NULL){
return NULL;
}

int lSum=*sum+root->data;
int rSum=lSum;


root->left=RemoveNodes(root->left,K,&lSum);
root->right=RemoveNodes(root->right,K,&rSum);
(*sum)=max(lSum,rSum);
if(*sum<K){
    (*sum)-=root->data;
free(root);
root=NULL;
}
return root;

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
printf("\nEnter the value of K : ");
int K;
scanf("%d",&K);
printf("\nPress enter to remove unwanted nodes\n\n");
getch();
/*
struct TNode** buffer=(struct TNode**)malloc(sizeof(struct TNode*)*n);
for(i=0;i<n;i++){
buffer[i]=(struct TNode*)malloc(sizeof(struct TNode));
}

RemoveBekarNodes(&root,buffer,K,0);
*/
int sum=0;
root=RemoveNodes(root,K,&sum);

printf("\nPress enter to traverse modified tree\n\n");
getch();
LevelOrderTraversal(root,n);
return 0;
}
