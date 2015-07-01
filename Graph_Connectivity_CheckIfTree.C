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

int DFSUtil(GNode* graph,int* visited,int* parent,int u){


ALNode* tmpNode=graph->GArray[u]->head;
visited[u]=1;
int v;
while(tmpNode){
v=tmpNode->destination;

if(!visited[v]){
parent[v]=u;
if(DFSUtil(graph,visited,parent,v)){
//printf("\nBreaking for %d\n",v);
return 1;
}
}else if(v!=parent[u] && parent[u]!=-1){
//printf("\nu and v are : %d and %d and their parent : %d %d",u,v,parent[u],parent[v]);
return 1;
}
tmpNode=tmpNode->next;
}

return 0;
}

int CheckIfTree(GNode* graph){

int* visited=(int*)malloc(sizeof(int)*graph->count);
int* parent=(int*)malloc(sizeof(int)*graph->count);

int i;

for(i=0;i<graph->count;i++){
visited[i]=0;
parent[i]=-1;
}

getch();
if(DFSUtil(graph,visited,parent,0)){
    printf("\nHere");
return 0;
}

for(i=0;i<graph->count;i++){
if(visited[i]==0){
return 0;
}
}
return 1;
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

printf("\nPress enter to see if given graph is tree");
int result=CheckIfTree(graph);
if(result){
printf("\nYes!");
}else{
printf("\nNo");
}
return 0;
}
