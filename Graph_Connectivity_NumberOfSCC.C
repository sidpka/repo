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

void CountSCCUtil(GNode* graph,int* visited,int u){
ALNode* tmpNode=graph->GArray[u]->head;
visited[u]=1;
while(tmpNode){
if(visited[tmpNode->destination]==0){
CountSCCUtil(graph,visited,tmpNode->destination);
}
tmpNode=tmpNode->next;
}

}


int CountSCC(GNode* graph){

int* visited=(int*)malloc(sizeof(int)*graph->count);
int i;

for(i=0;i<graph->count;i++){
visited[i]=0;
}

int count=0;

for(i=0;i<graph->count;i++){
if(visited[i]==0){
CountSCCUtil(graph,visited,i);
count++;
}
}

return count;
}

void Push(SNode** stack,int data){
SNode* newNode=(SNode*)malloc(sizeof(SNode));
newNode->data=data;

if(!(*stack)){
newNode->next=NULL;
(*stack)=newNode;
}else{
newNode->next=(*stack);
(*stack)=newNode;
}

}

int Pop(SNode** stack){
SNode* tmpNode=(*stack);
(*stack)=(*stack)->next;
int data=tmpNode->data;
free(tmpNode);
return data;
}

void DfsFill(GNode* graph,int* visited,SNode** stack,int i){

ALNode* tmpNode=graph->GArray[i]->head;
visited[i]=1;
while(tmpNode){
if(visited[tmpNode->destination]==0){
DfsFill(graph,visited,stack,tmpNode->destination);
}
tmpNode=tmpNode->next;
}
Push(&(*stack),i);
}

int IsEmptyStack(SNode* stack){
return stack==NULL;
}


void DoDFS(GNode* graph,int* visited,int i){

ALNode* tmpNode=graph->GArray[i]->head;
visited[i]=1;
printf("%d  ",i);
while(tmpNode){
    int v=tmpNode->destination;
if(visited[v]==0){
DoDFS(graph,visited,v);
}
tmpNode=tmpNode->next;
}


}
void SccComponents(GNode* graph,GNode* graph1){
SNode* stack=NULL;

int* visited=(int*)malloc(sizeof(int)*graph->count);

int i;

for(i=0;i<graph->count;i++){
visited[i]=0;
}

for(i=0;i<graph->count;i++){
if(!visited[i]){
DfsFill(graph,visited,&stack,i);
}
}

int data;

for(i=0;i<graph->count;i++){
visited[i]=0;
}

while(!IsEmptyStack(stack)){
data=Pop(&stack);
if(visited[data]==0){
DoDFS(graph1,visited,data);
printf("\n");
}
}




}


int main(){
int n;

printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);
GNode* graph=CreateGraph(n);
GNode* graph1=CreateGraph(n);
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
AddVertex(graph1,dest,source);
degree[source]++;
degree[dest]++;
}

printf("\nPress enter to traverse adjacency List\n");
getch();
TraverseAdjList(graph);
getch();
printf("\nPress enter to traverse transpose adjacency List\n");
getch();
TraverseAdjList(graph1);
getch();
printf("\nPress enter to see alll strongly connected componenets \n");
getch();
SccComponents(graph,graph1);
//printf("\nPress enter to find strongly connected components : ");
//int result=CountSCC(graph);
//printf("%d ",result);
return 0;
}
