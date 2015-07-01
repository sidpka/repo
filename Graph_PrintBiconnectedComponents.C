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


struct Edge{
int src;
int dest;
};
typedef struct Edge ENode;

struct stack{
ENode* data;
struct stack* next;

};
typedef struct stack SNode;


void Push(SNode** stack,ENode* data){
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

ENode* Pop(SNode** stack){

SNode* tmpNode=(*stack);
ENode* data=tmpNode->data;

(*stack)=(*stack)->next;

free(tmpNode);

return data;

}

int IsEmptyStack(SNode* stack){
return stack==NULL;
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
int visited[100];

void DFSTraversal(GNode* graphRoot,int u){
visited[u]=1;
printf("%d  ",u);
ALNode* tmpNode=graphRoot->GArray[u]->head;
while(tmpNode){
if(visited[tmpNode->destination]==0){
DFSTraversal(graphRoot,tmpNode->destination);
}
tmpNode=tmpNode->next;
}
}

void DFS(GNode* graphRoot){
int i;

for(i=0;i<graphRoot->count;i++){
visited[i]=0;
}

for(i=0;i<graphRoot->count;i++){
if(visited[i]==0){
DFSTraversal(graphRoot,i);
}
}
}

int min(int a ,int b){
return a<b?a:b;
}


void EmptyStack(SNode** stack){
ENode* data;

while(!IsEmptyStack(*stack)){
data=Pop(&(*stack));
printf(" %d -- %d ",data->src,data->dest);
}
printf("\n");
}

ENode* Top(SNode* stack){
if(!IsEmptyStack(stack)){
return stack->data;
}
}

void DFSUtil(GNode* graph,int* disc,int* low,int* parent,SNode** stack,int u){

static int time=0;
disc[u]=low[u]=++time;
ALNode* tmpNode;
tmpNode=graph->GArray[u]->head;
int v;
ENode* data;
int children=0;
while(tmpNode){
v=tmpNode->destination;
//printf("\nDisc[v] is : %d",disc[v]);
if(disc[v]==0){
parent[v]=u;
data=(ENode*)malloc(sizeof(ENode));
data->dest=v;
data->src=u;
Push(&(*stack),data);
children++;
DFSUtil(graph,disc,low,parent,&(*stack),v);

low[u]=min(low[u],low[v]);

if((children >1 && parent[u]==-1) || (parent[u]!=-1 && low[v]>=disc[u]) ){
while(Top(*stack)->src!=u || Top(*stack)->dest!=v){
data=Pop(&(*stack));
printf(" %d -- %d ",data->src,data->dest);
}
data=Pop(&(*stack));
printf(" %d -- %d ",data->src,data->dest);
printf("\n");
}

}else if(v!=parent[u] && low[u]> disc[v]){
low[u]=min(low[u],disc[v]);
data=(ENode*)malloc(sizeof(ENode));
data->dest=v;
data->src=u;
Push(&(*stack),data);
}
tmpNode=tmpNode->next;
}

}

void BiconnectedComp(GNode* graph){

int* disc=(int*)malloc(sizeof(int)*graph->count);
int* low=(int*)malloc(sizeof(int)* graph->count);
int* parent=(int*)malloc(sizeof(int)*graph->count);

int i;

for(i=0;i<graph->count;i++){
parent[i]=-1;
disc[i]=0;
low[i]=0;
}

SNode* stack=NULL;

for(i=0;i<graph->count;i++){
    if(disc[i]==0){
DFSUtil(graph,disc,low,parent,&stack,i);
if(!IsEmptyStack(stack)){
EmptyStack(&stack);
}
}
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
for(i=0;i<E;i++){
printf("\nEnter source destionation...");
scanf("%d %d",&source,&dest);
AddVertex(graph,source,dest);
}

printf("\nPress enter to traverse adjacency List\n");
getch();
TraverseAdjList(graph);
getch();

printf("\nPress enter to see biconnected components \n");
getch();
BiconnectedComp(graph);
getch();
return 0;
}
