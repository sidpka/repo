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
int recStack[100];
int IsCycleUtil(GNode* graphRoot,int u,int pre){
visited[u]=1;
recStack[u]=1;

ALNode* tmpNode=graphRoot->GArray[u]->head;
int prev=u;
while(tmpNode){
if(tmpNode->destination==pre){
tmpNode=tmpNode->next;
continue;
}
if(!visited[tmpNode->destination]  && IsCycleUtil(graphRoot,tmpNode->destination,prev)){
return 1;
}
else if(recStack[tmpNode->destination]){
return 1;
}
tmpNode=tmpNode->next;
}
recStack[u]=0;
return 0;
}
int IsCycle(GNode* graphRoot){
int i;

for(i=0;i<graphRoot->count;i++){
visited[i]=0;
recStack[i]=0;
}

for(i=0;i<graphRoot->count;i++){

if(!visited[i] && IsCycleUtil(graphRoot,i,i)){
return 1;
}

}
return 0;
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

printf("\nPress enter to check if cycle is found \n");
getch();
int result=IsCycle(graph);
if(result){
printf("\nCycle found\n");
}else{
printf("\nNo cycle");
}
getch();
return 0;
}
