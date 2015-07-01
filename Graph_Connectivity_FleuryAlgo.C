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

int min(int a,int b){
return a<b?a:b;
}

void FindAPUtility(GNode* graph,int* visited,int* parent,int* low,int* disc,int* ap,int u){
static int time=0;

low[u]=++time;
visited[u]=1;
disc[u]=low[u];
int children=0;
ALNode* tmpNode=graph->GArray[u]->head;

while(tmpNode){

int v=tmpNode->destination;

if(visited[v]==0){

parent[v]=u;
children++;
FindAPUtility(graph,visited,parent,low,disc,ap,v);

low[u]=min(low[u],low[v]);
/*
if(parent[u]==-1 && children>=2){
ap[u]=1;
}
*/
if(low[v]>disc[u]){
//ap[u]=1;
printf("\nB[%d] ------ B[%d]",u,v);
}

}else if(v!=parent[u]){
low[u]=min(low[u],disc[v]);
}

tmpNode=tmpNode->next;
}


}



void FindBridges(GNode* graph){
int* low=(int*)malloc(sizeof(int)*graph->count);
int* ap=(int*)malloc(sizeof(int)*graph->count);
int* disc=(int*)malloc(sizeof(int)*graph->count);
int* parent=(int*)malloc(sizeof(int)*graph->count);
int* visited=(int*)malloc(sizeof(int)*graph->count);

int i;

for(i=0;i<graph->count;i++){
ap[i]=0;
visited[i]=0;
parent[i]=-1;

}

for(i=0;i<graph->count;i++){
if(visited[i]==0){
FindAPUtility(graph,visited,parent,low,disc,ap,i);
}
}

}

void DFSUtil(GNode* graph,int* visited,int i){
ALNode* tmpNode;

visited[i]=1;

tmpNode=graph->GArray[i]->head;

while(tmpNode){
    if(!visited[tmpNode->destination]){
DFSUtil(graph,visited,tmpNode->destination);
    }
tmpNode=tmpNode->next;
}

}

int IsConnected(GNode* graph,int* degree){

int* visited=(int*)malloc(sizeof(int)*graph->count);
int i;
for(i=0;i<graph->count;i++){
visited[i]=0;
}
for(i=0;i<graph->count;i++){
if(degree[i]!=0){
break;
}
}
if(i==graph->count){
return 1;
}

DFSUtil(graph,visited,i);

for(i=0;i<graph->count;i++){
if(visited[i]==0 && degree[i]>0){
return 0;
}
}

return 1;


}


int IsEulerian(GNode* graph,int* degree){

if(IsConnected(graph,degree)==0){
return 0;
}
int odd=0;

int i;

for(i=0;i<graph->count;i++){
if(degree[i] & 1){
odd++;
}
}

if(odd>2){
return 0;
}
else if(odd==0){
return 2;
}else{
return 1;
}



}

int DfsCount(GNode* graph,int* visited,int u){
    //printf("\nIn DFS count\n");
ALNode* tmpNode=graph->GArray[u]->head;
visited[u]=1;
int count=1;
while(tmpNode){
if(tmpNode->destination!=-1 && visited[tmpNode->destination]==0){
count+=DfsCount(graph,visited,tmpNode->destination);
}
tmpNode=tmpNode->next;
}

return count;
}






void RemoveEdge(GNode* graph,int u,int v){
ALNode* tmpNode=graph->GArray[u]->head;
//printf("\nHere\n");
while(tmpNode){
if(tmpNode->destination!=-1 && tmpNode->destination==v){
tmpNode->destination=-1;
//printf("\nRemoved");
break;
}
tmpNode=tmpNode->next;
}

tmpNode=graph->GArray[v]->head;
while(tmpNode){
if(tmpNode->destination!=-1 && tmpNode->destination==u){
    //printf("\nRemoved");
tmpNode->destination=-1;
break;
}
tmpNode=tmpNode->next;
}
}


int IsValidEdge(GNode* graph,int u,int v){
//printf("\nEntering here");
int count=0;
int i;

ALNode* tmpNode=graph->GArray[u]->head;

while(tmpNode){
if(tmpNode->destination!=-1){
count++;
}
tmpNode=tmpNode->next;
}
//printf("\nEntering here 39");
if(count==1){
return 1;
}
int* visited=(int*)malloc(sizeof(int)*graph->count);
for(i=0;i<graph->count;i++){
visited[i]=0;
}
int count1=DfsCount(graph,visited,u);
//printf("\n377 Count : %d",count1);
//getch();

RemoveEdge(graph,u,v);
//printf("\nRemoved in testing");
for(i=0;i<graph->count;i++){
visited[i]=0;
}
int count2=DfsCount(graph,visited,u);
//printf("\nCount 1: %d and Count 2 : %d\n\n",count1,count2);
AddVertex(graph,u,v);
if(count1>count2){
return 0;
}

return 1;

}


void PrintEuler(GNode* graph,int u){
//printf("\nHere in printEuler\n");
ALNode* tmpNode=graph->GArray[u]->head;
int v;
int res;
while(tmpNode){
    v=tmpNode->destination;
    //printf("\nV is : %d",v);
    if(v==-1){
    tmpNode=tmpNode->next;
    continue;
    }
   else{
    res=IsValidEdge(graph,u,v);
if(res){
    //printf("\n401\n");
    //printf("\nEntering for : %d",v);
    //printf("\n\nTraversing\n\n");
    //TraverseAdjList(graph);
    //getch();
printf(" %d -- %d ",u,v);
RemoveEdge(graph,u,v);
//printf("\n404\n");
PrintEuler(graph,v);
}
    }
tmpNode=tmpNode->next;
}
}

void CheckEulerian(GNode* graph,int* degree){

int res=IsEulerian(graph,degree);
int i;

int* visited=(int*)malloc(sizeof(int)*graph->count);
for(i=0;i<graph->count;i++){
visited[i]=0;
}
if(res==0){
printf("\nNot Eulerian");
return;
}else if(res==1){
//printf("\nEulerian Path");

for(i=0;i<graph->count;i++){
if(degree[i]&1){
break;
}
}
//printf("\nI is : %d ",i);
PrintEuler(graph,i);
}else{
//printf("\nEulerian Circuit");
PrintEuler(graph,0);
}

}


int main(){
int n;

printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);
GNode* graph=CreateGraph(n);
int i,source,dest;
int E;
printf("\nEnter the number of edges :  ");
scanf("%d",&E);

int* degree=(int*)malloc(sizeof(int)*graph->count);

for(i=0;i<graph->count;i++){
degree[i]=0;
}

for(i=0;i<E;i++){
printf("\nEnter source destionation...");
scanf("%d %d",&source,&dest);
AddVertex(graph,source,dest);
degree[source]++;
degree[dest]++;
}

printf("\nPress enter to traverse adjacency List\n");
getch();
TraverseAdjList(graph);
getch();
printf("\nPress enter to print Eulerian path  : \n\n");
getch();
CheckEulerian(graph,degree);
getch();

return 0;
}
