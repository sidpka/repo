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


void GraphColoring(GNode* graph){


int* result=(int*)malloc(sizeof(int)*graph->count);
int* available=(int*)malloc(sizeof(int)*graph->count);

int i;
for(i=0;i<graph->count;i++){
result[i]=-1;
available[i]=0;
}

ALNode* tmpNode;

result[0]=0;

int u;

for(u=1;u<graph->count;u++){
int v;
tmpNode=graph->GArray[u]->head;
while(tmpNode){
v=tmpNode->destination;
if(result[v]!=-1){
available[result[v]]=1;
}
tmpNode=tmpNode->next;
}

int color;

for(i=0;i<graph->count;i++){
if(available[i]==0){
color=i;
break;
}
}

result[u]=color;
//printf("\nAssigning color %d to vertex %d",result[u],u);
tmpNode=graph->GArray[u]->head;
while(tmpNode){
v=tmpNode->destination;
if(result[v]!=-1){
available[result[v]]=0;
}
tmpNode=tmpNode->next;
}


}

for(i=0;i<graph->count;i++){
printf("\nVertex : %d  has color : %d",i,result[i]);
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

printf("\nPress enter to see graph coloring scheme \n");
GraphColoring(graph);
getch();
return 0;
}
