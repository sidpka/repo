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

void PrintHamiltonian(int* path,int n){

int i;

for(i=0;i<n;i++){
printf("%d  ",path[i]);
}
printf("%d  ",path[0]);
}

int IsSafe(int** array,int* path,int v,int pos,int n){

if(array[path[pos-1]][v]==0){
return 0;
}

int i;

for(i=0;i<n;i++){
if(path[i]==v){
return 0;
}
}

return 1;


}

int HamiltonianUtil(int** array,int* path,int n,int pos){

if(pos==n){
if(array[path[pos-1]][path[0]]){
return 1;
}else{
return 0;
}
}

int i;

for(i=1;i<n;i++){
if(IsSafe(array,path,i,pos,n)){
path[pos]=i;
if(HamiltonianUtil(array,path,n,pos+1)){
return 1;
}
path[pos]=-1;
}
}
return 0;
}

void Hamiltonian(GNode* graph){

int** array=(int**)malloc(sizeof(int*)*graph->count);

int i;

for(i=0;i<graph->count;i++){
array[i]=(int*)malloc(sizeof(int)*graph->count);
}

int j;

for(i=0;i<graph->count;i++){
for(j=0;j<graph->count;j++){
if(i==j){
array[i][j]=1;
}else{
array[i][j]=0;
}
}
}

ALNode* tmpNode;
int v;
for(i=0;i<graph->count;i++){
tmpNode=graph->GArray[i]->head;
while(tmpNode){
v=tmpNode->destination;
array[i][v]=1;
tmpNode=tmpNode->next;
}

}

int* path=(int*)malloc(sizeof(int)*graph->count);

for(i=0;i<graph->count;i++){
path[i]=-1;
}
path[0]=0;
if(HamiltonianUtil(array,path,graph->count,1)==0){
printf("\nNo such hamiltonian path exists");
return;
}
int n=graph->count;
PrintHamiltonian(path,n);

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

printf("\nPress enter to see hamiltonian pat...\n");
getch();
Hamiltonian(graph);
getch();
return 0;
}
