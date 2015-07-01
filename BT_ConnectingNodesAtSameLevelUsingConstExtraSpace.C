#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct TNode{

int data;
struct TNode* left;
struct TNode* right;
struct TNode* nextRight;
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
/*
struct TNode* GetNextRight(struct TNode* root){
struct TNode* tmpNode=root->adjacent;

while(tmpNode){

if(tmpNode->left){
return tmpNode->left;
}

if(tmpNode->right){
return tmpNode->right;
}
tmpNode=tmpNode->adjacent;
}
return NULL;
}

void ConnectNodesAtSameLevel(struct TNode* root){

struct TNode* p=root;
struct TNode* q=NULL;
root->adjacent=NULL;
while(p){
q=p;

while(q){

if(q->left){
if(q->right){
q->left->adjacent=q->right;
}
else{
q->left->adjacent=GetNextRight(q);
}
}

if(q->right){
q->right->adjacent=GetNextRight(q);
}
q=q->adjacent;
}

if(p->left){
p=p->left;
}
if(p->right){
p=p->right;
}
else{
p=GetNextRight(p);
}

}
}

*/



//
struct TNode *getNextRight(struct TNode *p)
{
    struct TNode *temp = p->nextRight;

    /* Traverse nodes at p's level and find and return
       the first node's first child */
    while (temp != NULL)
    {
        if (temp->left != NULL)
            return temp->left;
        if (temp->right != NULL)
            return temp->right;
        temp = temp->nextRight;
    }

    // If all the nodes at p's level are leaf nodes then return NULL
    return NULL;
}

/* Sets nextRight of all nodes of a tree with root as p */
void connect(struct TNode* p)
{
    struct node *temp;

    if (!p)
      return;

    // Set nextRight for root
    p->nextRight = NULL;

    // set nextRight of all levels one by one
    while (p != NULL)
    {
        struct TNode *q = p;

        /* Connect all childrem nodes of p and children nodes of all other nodes
          at same level as p */
        while (q != NULL)
        {
            // Set the nextRight pointer for p's left child
            if (q->left)
            {
                // If q has right child, then right child is nextRight of
                // p and we also need to set nextRight of right child
                if (q->right)
                    q->left->nextRight = q->right;
                else
                    q->left->nextRight = getNextRight(q);
            }

            if (q->right)
                q->right->nextRight = getNextRight(q);

            // Set nextRight for other nodes in pre order fashion
            q = q->nextRight;
        }

        // start from the first node of next level
        if (p->left)
           p = p->left;
        else if (p->right)
           p = p->right;
        else
           p = getNextRight(p);
    }
}

//

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

printf("\nPress enter to connect nodes at same level : \n\n");
getch();
//ConnectNodesAtSameLevel(root);
connect(root);
printf("\nAll Nodes connected....\n\n");
getch();
printf("\n%d ",root->data);
printf("\n%d ",root->left->data);
printf("%d ",root->left->nextRight->data);
printf("\n%d ",root->left->left->data);
printf("%d ",root->left->left->nextRight->data);
return 0;
}
