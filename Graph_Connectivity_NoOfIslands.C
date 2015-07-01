#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct AListNode{
int destination;
struct AListNode* next;
};
typedef struct AListNode ALNode;

struct AdjList{
ALNode* head;
};

typedef struct AdjList AList;

struct GraphNode{
int count;
AList** GArray;
};
typedef struct GraphNode GNode;

struct Stack{
int data;
struct Stack* next;
};
typedef struct Stack SNode;

struct QueueNode{
int capacity;
int front;
int rear;
int* Array;
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
queue->Array=(int* )malloc(sizeof(int)*queue->capacity);


return queue;
}

int IsEmptyQueue(QNode* queue){
return queue->front==-1;
}

int IsFullQueue(QNode* queue){
return (queue->rear+1)%queue->capacity==queue->front;
}

void ResizeQueue(QNode* queue){



queue->Array=(int*)realloc(queue->Array,queue->capacity*2);
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

void EnQueue(QNode* queue,int node){

if((queue->rear+1)%queue->capacity==queue->front){
ResizeQueue(queue);
}
queue->rear=(queue->rear+1)%queue->capacity;
queue->Array[queue->rear]=node;
if(queue->front==-1){
queue->front=0;
}

}

int DeQueue(QNode* queue){
if(IsEmptyQueue(queue)){
printf("\nNo data");
return NULL;
}else{int data=queue->Array[queue->front];

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

free(queue->Array);
free(queue);

}

GNode* CreateGraph(int n){

GNode* graph=(GNode*)malloc(sizeof(GNode));
if(!graph){
printf("\nMemory Error");
}
graph->count=n;
graph->GArray=(AList**)malloc(sizeof(AList*)*n);
if(!graph->GArray){
printf("\nMemory Error");
}
int i;
for(i=0;i<n;i++){
   graph->GArray[i]=(AList*)malloc(sizeof(AList));
graph->GArray[i]->head=NULL;
}
return graph;
}

ALNode* AddEdge(int dest){

ALNode* newNode=(ALNode*)malloc(sizeof(ALNode));
newNode->destination=dest;
newNode->next=NULL;
return newNode;
}

void AddVertex(GNode* graph,int src,int dest){

ALNode* tmpNode=AddEdge(dest);
tmpNode->next=graph->GArray[src]->head;
graph->GArray[src]->head=tmpNode;

/*
tmpNode=AddEdge(src);
tmpNode->next=graph->GArray[dest]->head;
graph->GArray[dest]->head=tmpNode;
*/
}

void TraverseAdjList(GNode* graph){

int i;

for(i=0;i<graph->count;i++){

printf("[ %d ] :: --> ",i);
ALNode* tmpNode=graph->GArray[i]->head;

while(tmpNode){
printf("%d --> ",tmpNode->destination);
tmpNode=tmpNode->next;
}

printf("\n");

}

}

void PrintTransitiveClosure(int** reach,int n){

int i;
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d  ",reach[i][j]);
}
printf("\n");
}

}

void TransitiveClosure(int** array,int n){

int i;
int j;
int** reach=(int**)malloc(sizeof(int*)*n);

for(i=0;i<n;i++){
reach[i]=(int*)malloc(sizeof(int)*n);
}

int k;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
reach[i][j]=array[i][j];
}
}


for(k=0;k<n;k++){

for(i=0;i<n;i++){
for(j=0;j<n;j++){
reach[i][j]=(reach[i][j])|| (reach[i][k] && reach[k][j]);
}
}
}

PrintTransitiveClosure(reach,n);
}


int IsSafe(int** array,int** visited,int n,int row,int col){

return (array[row][col] && !visited[row][col] && (row>=0) &&( row<n) && (col>=0) && (col<n));

}

void DFS(int** array,int** visited,int n,int row,int col){


int i;
int j;
visited[row][col]=1;
static int rowNum[]={-1,-1,-1,0,0,1,1,1};
static int colNum[]={-1,0,1,-1,1,-1,0,1};

int k;

for(k=0;k<8;k++){
if(IsSafe(array,visited,n,row+rowNum[k],col+colNum[k])){
DFS(array,visited,n,row+rowNum[k],col+colNum[k]);
}

}



}

int GetIslands(int** array,int n){


int i;
int j;

int count=0;
int** visited=(int**)malloc(sizeof(int*)*n);
for(i=0;i<n;i++){
visited[i]=(int*)malloc(sizeof(int)*n);
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){
visited[i][j]=0;
}
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){

if(array[i][j] && ! visited[i][j]){
DFS(array,visited,n,i,j);
count++;
}

}
}
return count;
}



int main(){
int n;

printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);

int** array=(int**)malloc(sizeof(int*)*n);

int i;

for(i=0;i<n;i++){
array[i]=(int*)malloc(sizeof(int)*n);
}

int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
    if(i==j){
    array[i][j]=1;
    }else{
    array[i][j]=0;
    }
}
}

printf("\nEnter the no of edges : ");
int E;
scanf("%d",&E);

int src,dest;

for(i=0;i<E;i++){
printf("\nENter  src n dest :  ");
scanf("%d %d",&src,&dest);
array[src][dest]=1;
}

//TransitiveClosure(array,n);

printf("\nPress enter to see number of islands : ");
int islands=GetIslands(array,n);
getch();
printf("%d ",islands);




return 0;
}
