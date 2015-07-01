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

struct TNode* GetLCA(struct TNode* root,struct TNode* lNode,struct TNode* rNode,int* isLeftSet,int* isRightSet){
if(!root){
return NULL;
}
if(root==lNode || root==rNode){
    if(root==lNode){
    (*isLeftSet)=1;
    }
    if(root==rNode){
    (*isRightSet)=1;
    }
return root;
}

struct TNode* lResult=GetLCA(root->left,lNode,rNode,isLeftSet,isRightSet);
struct TNode* rResult=GetLCA(root->right,lNode,rNode,isLeftSet,isRightSet);

if(lResult && rResult){
return root;
}

return lResult!=NULL?lResult:rResult;

}

int max(int a,int b){
return a>b?a:b;
}

int GetDistance(struct TNode* root,struct TNode* node,int distance){
if(!root){
return 0;
}
if(root==node){
return distance;
}
return GetDistance(root->left,node,distance+1)!=0 ?GetDistance(root->left,node,distance+1):GetDistance(root->right,node,distance+1);
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
int isLeftSet=0;
int isRightSet=0;
struct TNode* tmpNode1=root->left->left;
struct TNode* tmpNode2=root->left->left;


struct TNode* ancestorNode=GetLCA(root,tmpNode1,tmpNode2,&isLeftSet,&isRightSet);
if(isLeftSet && isRightSet){
printf("\nAncestor : %d\n",ancestorNode->data);
}else{
printf("\nNULL\n");
}

if(isLeftSet && isRightSet){
int firstNodeDistance=GetDistance(root,tmpNode1,0);
printf("\n\nfirstNodeDistance : %d",firstNodeDistance);
int secondNodeDistance=GetDistance(root,tmpNode2,0);
printf("\n\secondNodeDistance : %d",secondNodeDistance);
int ancestorNodeDistance=GetDistance(root,ancestorNode,0);
printf("\n\ancestorNodeDistance : %d",ancestorNodeDistance);
int result=(firstNodeDistance+secondNodeDistance)-(2*ancestorNodeDistance);
printf("\n\nresult: %d",result);
printf("\n\nDistance between %d & %d is : %d",tmpNode1->data,tmpNode2->data,result);
}
else{
printf("\nCant find distance between : %d & %d",tmpNode1->data,tmpNode2->data);

}

return 0;
}
