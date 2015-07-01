#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct AListNode{
int destination;
int wait;
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

ALNode* AddEdge(int dest,int weight){

ALNode* newNode=(ALNode*)malloc(sizeof(ALNode));
newNode->destination=dest;
newNode->wait=weight;
newNode->next=NULL;
return newNode;
}

void AddVertex(GNode* graph,int src,int dest,int weight){

ALNode* tmpNode=AddEdge(dest,weight);

tmpNode->next=graph->GArray[src]->head;
graph->GArray[src]->head=tmpNode;

tmpNode=AddEdge(src,weight);
tmpNode->next=graph->GArray[dest]->head;
graph->GArray[dest]->head=tmpNode;
}

void TraverseAdjList(GNode* graph){

int i;

for(i=0;i<graph->count;i++){

printf("[ %d ] :: --> ",i);
ALNode* tmpNode=graph->GArray[i]->head;

while(tmpNode){
printf("%d |  (  Wt: %d  )--> ",tmpNode->destination,tmpNode->wait);
tmpNode=tmpNode->next;
}

printf("\n");


}


}


int main(){


int n;



printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);
GNode* graph=CreateGraph(n);
int i,source,dest,weight;
int E;
printf("\nenter the num of edges : ");
scanf("%d",&E);
for(i=0;i<E;i++){
printf("\nEnter source destionation and weight...");
scanf("%d %d %d",&source,&dest,&weight);
AddVertex(graph,source,dest,weight);
}

printf("\nPress enter to traverse adjacency List\n");
getch();
TraverseAdjList(graph);
getch();










return 0;
}
