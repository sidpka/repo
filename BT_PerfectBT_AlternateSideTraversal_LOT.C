#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

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

int max(int a,int b){
return a>b?a:b;
}

int Height(struct TNode* root){
if(!root){
return 0;
}

return max(Height(root->left),Height(root->right))+1;

}

void PopulateLevel(struct TNode* root,int level,int* buffer,int* index){
if(!root){
return;
}
if(level==1){
buffer[(*index)++]=root->data;
return;
}

if(level>1){
if(root->left){
PopulateLevel(root->left,level-1,buffer,index);
}
if(root->right){
PopulateLevel(root->right,level-1,buffer,index);
}
}
}

void PrintNodes(int* buffer,int index){

int i=0;
int j=index;

while(1){
    if(i>j){
    break;
    }
    printf("%d  ",buffer[i]);
    i++;
    if(i>j){
    break;
    }else{
      printf("%d  ",buffer[j]);
      j--;
    }

}
}
void AlternateLevelOrderTraversal(struct TNode* root){
int i;
int height=Height(root);
int index;
int size;
printf("\n\n");
for(i=1;i<=height;i++){
index=0;
size=(int)pow(2,i-1);
int* buffer=(int*)malloc(sizeof(int*)*size);
PopulateLevel(root,i,buffer,&index);
PrintNodes(buffer,index-1);
free(buffer);
}
}

void AlternateLOTS(struct TNode* root,int n){


if(!root){
return;
}
struct TNode* tmp1,*tmp2;
printf("%d ",root->data);
if(root->left){
printf("%d  %d  ",root->left->data,root->right->data);
}

if(!root->left->left){
return;
}
QNode* queue=CreateQueue(n);
EnQueue(queue,root->left);
EnQueue(queue,root->right);

while(!IsEmptyQueue(queue)){
tmp1=DeQueue(queue);
tmp2=DeQueue(queue);

printf("%d  %d  ",tmp1->left->data,tmp2->right->data);
printf("%d  %d  ",tmp1->right->data,tmp2->left->data);

if(tmp1->left->left){
EnQueue(queue,tmp1->left);
EnQueue(queue,tmp2->right);
EnQueue(queue,tmp1->right);
EnQueue(queue,tmp2->left);
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
AlternateLevelOrderTraversal(root);
//Another method
printf("\n\n");
AlternateLOTS(root,n);
return 0;
}
