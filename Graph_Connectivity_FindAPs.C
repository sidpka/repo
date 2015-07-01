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

tmpNode=AddEdge(src);
tmpNode->next=graph->GArray[dest]->head;
graph->GArray[dest]->head=tmpNode;

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

void BFSTraversal(GNode* graphRoot,int* visited,int u){

QNode* queue=CreateQueue(graphRoot->count);

EnQueue(queue,u);

int data;
ALNode* tmpNode;
while(!IsEmptyQueue(queue)){

data=DeQueue(queue);
if(visited[data]==0){
//printf("%d  ",data);
tmpNode=graphRoot->GArray[data]->head;
while(tmpNode){
if(visited[tmpNode->destination]==0){
EnQueue(queue,tmpNode->destination);
}
tmpNode=tmpNode->next;
}
visited[data]=1;
}


}



}

int min(int a,int b){
return a<b?a:b;
}

void DFS(GNode* graph,int* visited,int* dis,int* low,int* parent,int* AP,int u){

static int time=0;
int children =0;
ALNode* tmpNode;

visited[u]=1;
low[u]=dis[u]=++time;
tmpNode=graph->GArray[u]->head;
int v;
while(tmpNode){
v=tmpNode->destination;

if(!visited[v]){
children++;
parent[v]=u;
DFS(graph,visited,dis,low,parent,AP,v);
low[u]=min(low[u],low[v]);
if(parent[u]==-1 && children>1){
    //printf("\nNtering here for : %d fot no child\n",u);
AP[u]=1;
}
//if(u==3){
//printf("\nYes\n");
//printf("\nparent[%d] : %d\n",u,parent[u]);

//printf("\ndis[%d] : %d",u,dis[u]);
//}
if(parent[u]!=-1 && low[v]>=dis[u]){
    //printf("\n Entering here for : %d in no path back\n",u);
AP[u]=1;
}
}
else if(v!=parent[u]){
low[u]=min(low[u],dis[v]);
}
tmpNode=tmpNode->next;
}
}

void GetAPs(GNode* graph){

int n=graph->count;

int* visited=(int*)malloc(sizeof(int)*n);
int* dis=(int*)malloc(sizeof(int)*n);
int* low=(int*)malloc(sizeof(int)*n);
int* parent=(int*)malloc(sizeof(int)*n);
int* AP=(int*)malloc(sizeof(int)*n);

int i;
for(i=0;i<n;i++){
visited[i]=0;
parent[i]=-1;
low[i]=0;
dis[i]=0;
AP[i]=0;
}
for(i=0;i<n;i++){
if(!visited[i]){
DFS(graph,visited,dis,low,parent,AP,i);
}
}

for(i=0;i<n;i++){
printf("%d  ",AP[i]);
}


}


int main(){


int n;



printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);
GNode* graph=CreateGraph(n);
//GNode* graph1=CreateGraph(n);
int i,source,dest;
int E;
int* inOrder=(int*)malloc(sizeof(int)*n);
int* outOrder=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
inOrder[i]=0;
outOrder[i]=0;
}
printf("\nEnter the number of edges :  ");
scanf("%d",&E);
for(i=0;i<E;i++){
printf("\nEnter source destionation...");
scanf("%d %d",&source,&dest);
AddVertex(graph,source,dest);
//AddVertex(graph1,dest,source);
inOrder[dest]=1;
outOrder[source]=1;
}

printf("\nPress enter to traverse adjacency List\n");
getch();
TraverseAdjList(graph);
getch();

printf("\nPress enter to see all articulation points \n");
getch();
GetAPs(graph);
getch();
return 0;
}
