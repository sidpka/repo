#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

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

int BFS(int** array,int* parent,int s,int t,int n){


int* visited=(int*)malloc(sizeof(int)*n);
QNode* queue=CreateQueue(n);
int i;

for(i=0;i<n;i++){
visited[i]=0;
}

int u,v;

parent[s]=-1;
visited[s]=1;

EnQueue(queue,s);

int data;

while(!IsEmptyQueue(queue)){
u=DeQueue(queue);

for(v=0;v<n;v++){
if(visited[v]==0 && array[u][v]>0){
EnQueue(queue,v);
parent[v]=u;
visited[v]=1;
}
}

}


return (visited[t]==1);
}


int min(int a,int b){
return a<b?a:b;
}


int FordFulkerson(int** array,int s,int t,int n){


int** rGraph=(int**)malloc(sizeof(int*)*n);
int i;
int j;

for(i=0;i<n;i++){
rGraph[i]=(int*)malloc(sizeof(int*)*n);
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){
rGraph[i][j]=array[i][j];
}
}


int* parent=(int*)malloc(sizeof(int)*n);


int max_flow=0;


int u;
int v;

while(BFS(rGraph,parent,s,t,n)){
int path_flow=INT_MAX;
for(v=t;v!=s;v=parent[v]){
u=parent[v];
path_flow=min(path_flow,rGraph[u][v]);
}

for(v=t;v!=s;v=parent[v]){
u=parent[v];
rGraph[u][v]-=path_flow;
rGraph[v][u]+=path_flow;
}

max_flow+=path_flow;
}

return max_flow;
}

int main(){


int n;



printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);
//GNode* graph=CreateGraph(n);
int i,source,dest;
int weight;
int E;
//GNode* rgraph=CreateGraph(n);


int** array=(int**)malloc(sizeof(int*)*n);

for(i=0;i<n;i++){
array[i]=(int*)malloc(sizeof(int)*n);
}

int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
array[i][j]=0;
}
}






printf("\nEnter the number of edges :  ");
scanf("%d",&E);
for(i=0;i<E;i++){
printf("\nEnter source destionation and weight...");
scanf("%d %d %d",&source,&dest,&weight);
array[source][dest]=weight;
//AddVertex(graph,source,dest);
//AddVertex(rgraph,source,dest);
}
printf("\nEnter value of source and destination to find max flow between : ");
scanf("%d %d",&source,&dest);
printf("\nPress enter to find max flow : n");
getch();
int result=FordFulkerson(array,source,dest,n);
printf("\nMax flow : %d",result);
getch();
return 0;
}
