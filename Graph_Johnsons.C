#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
#define max 9999
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

struct HeapHelper{

int vertex;
int weight;
};

typedef struct HeapHelper HHNode;

struct Heap{
int count;
int capacity;
int* pos;
HHNode** HArray;
};

typedef struct Heap HNode;

HNode* CreatePQueue(int v){

HNode* newNode=(HNode*)malloc(sizeof(HNode));
newNode->capacity=v;
newNode->count=0;
newNode->HArray=(HHNode**)malloc(sizeof(HHNode*)*v);
newNode->pos=(int*)malloc(sizeof(int)*v);
/*
int i;
for(i=0;i<v;i++){
newNode->HArray[i]=(HHNode*)malloc(sizeof(HHNode));
newNode->HArray[i]->vertex=-1;
newNode->HArray[i]->weight=INT_MAX;
}
*/
return newNode;
}

//int position[100];


int LeftChild(HNode* heap,int i){

int left=2*i+1;
if(left>=heap->count){
return -1;
}
return left;

}

int RightChild(HNode* heap,int i){

int right=2*i+2;
if(right>=heap->count){
return -1;
}
return right;

}

void EnPQueue(HNode* heap,HHNode* node){

int i=heap->count;

while(i>0 && heap->HArray[(i-1)/2]->weight > node->weight){
heap->HArray[i]=heap->HArray[(i-1)/2];
//position[heap->HArray[i]->vertex]=i;
heap->pos[heap->HArray[i]->vertex]=i;
i=(i-1)/2;
}

heap->HArray[i]=node;
//position[node->vertex]=i;
heap->pos[node->vertex]=i;
heap->count++;
}




int IsEmptyPQueue(HNode* heap){
return heap->count==0;
}

void PercolateDown(HNode* heap,int i){

int min;
int left=LeftChild(heap,i);
int right=RightChild(heap,i);

if(left!=-1 &&  heap->HArray[left]->weight<heap->HArray[i]->weight){
min=left;
}else{
min=i;
}

if(right!=-1 && heap->HArray[right]->weight<heap->HArray[min]->weight){
min=right;
}

if(i!=min){
HHNode* tmpNode=heap->HArray[i];
heap->HArray[i]=heap->HArray[min];
//position[heap->HArray[i]->vertex]=i;
heap->pos[heap->HArray[i]->vertex]=i;
heap->HArray[min]=tmpNode;
//position[heap->HArray[min]->vertex]=min;
heap->pos[heap->HArray[min]->vertex]=min;
PercolateDown(heap,min);
}


}

HHNode* DePQueue(HNode* heap){
HHNode* tmpNode=heap->HArray[0];
//position[heap->HArray[0]->vertex]=-1;
heap->pos[heap->HArray[0]->vertex]=heap->count-1;
heap->HArray[0]=heap->HArray[heap->count-1];
//position[heap->HArray[heap->count-1]->vertex]=0;
heap->pos[heap->HArray[heap->count-1]->vertex]=0;
heap->count--;
PercolateDown(heap,0);
return tmpNode;
}



GNode* CreateGraph(int n){

GNode* graph=(GNode*)malloc(sizeof(GNode));
if(!graph){
printf("\nMemory Error");
}
graph->count=n;
graph->GArray=(AList**)malloc(sizeof(AList*)*(n+1));
if(!graph->GArray){
printf("\nMemory Error");
}
int i;
for(i=0;i<n+1;i++){
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
/*
tmpNode=AddEdge(src,weight);
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
printf("%d |  (  Wt: %d  )--> ",tmpNode->destination,tmpNode->wait);
tmpNode=tmpNode->next;
}

printf("\n");


}


}

/*
void UpdateWeight(HNode* heap,int index,int newWeight){

int i=index;

heap->HArray[i]->weight=newWeight;
HHNode* tmpNode=heap->HArray[i];
while(i>0 && heap->HArray[(i-1)/2]->weight > newWeight){

heap->HArray[i]=heap->HArray[(i-1)/2];
position[heap->HArray[i]->vertex]=i;
i=(i-1)/2;
}

heap->HArray[i]=tmpNode;
position[heap->HArray[i]->vertex]=i;
}
*/


void UpdateWeight(HNode* heap,int vertex,int newWeight){

int i=heap->pos[vertex];

heap->HArray[i]->weight=newWeight;
HHNode* tmpNode=heap->HArray[i];
while(i>0 && heap->HArray[(i-1)/2]->weight > newWeight){
heap->HArray[i]=heap->HArray[(i-1)/2];
//position[heap->HArray[i]->vertex]=i;
heap->pos[heap->HArray[i]->vertex]=i;
i=(i-1)/2;
}

heap->HArray[i]=tmpNode;
heap->pos[heap->HArray[i]->vertex]=i;
//position[heap->HArray[i]->vertex]=i;
}

int GetIndex(HNode* heap,int v){
int i;
/*printf("\nVertex : %d\n",v);
for(i=0;i<heap->count;i++){
printf("%d  ",heap->HArray[i]->vertex);
}

getch();
*/

for(i=0;i<heap->count;i++){
if(heap->HArray[i]->vertex==v){
break;
}
}
if(i==heap->count){
return -1;
}
return i;
}


void PrintDistance(int** distance,int size){
int i;

int j;

for(i=0;i<size;i++){
    for(j=0;j<size;j++){
printf("%d  ",distance[i][j]);
}
printf("\n");
}

}
/*
void PopulatePosition(int size){

int i;

for(i=0;i<size;i++){
position[i]=-1;
}

}

*/

HHNode* NewNode(int vertex,int weight){
HHNode* tmpNode=(HHNode*)malloc(sizeof(HHNode));
tmpNode->vertex=vertex;
tmpNode->weight=weight;
return tmpNode;
}

int IsInQueue(HNode* heap,int vertex){
if(heap->pos[vertex]<heap->count){
return 1;
}
return 0;
}

void DijkastraUtil(GNode* graph,int** distance,int sourceNode){

HNode* pQueue=CreatePQueue(graph->count);
int i;

for(i=0;i<graph->count;i++){
pQueue->HArray[i]=NewNode(i,INT_MAX);
pQueue->pos[i]=i;
}

pQueue->count=graph->count;
HHNode* tmpNode=pQueue->HArray[0];
pQueue->HArray[0]=pQueue->HArray[sourceNode];
pQueue->HArray[sourceNode]=tmpNode;
pQueue->pos[sourceNode]=0;
pQueue->pos[0]=sourceNode;

ALNode* tmpLink;
int newDistance;

while(!IsEmptyPQueue(pQueue)){
tmpNode=DePQueue(pQueue);
tmpLink=graph->GArray[tmpNode->vertex]->head;

while(tmpLink){
newDistance=distance[sourceNode][tmpNode->vertex]+tmpLink->wait;

if(IsInQueue(pQueue,tmpLink->destination) && distance[sourceNode][tmpLink->destination]> newDistance){
distance[sourceNode][tmpLink->destination]=newDistance;
UpdateWeight(pQueue,tmpLink->destination,newDistance);
}

tmpLink=tmpLink->next;
}
}

//PrintDistance(distance,graph->count);
}




void DijkastraFinder(GNode* graph){

int** distance=(int**)malloc(sizeof(int*)*graph->count);
//static int* position=(int*)malloc(sizeof(int)*graph->count);
int i;
for(i=0;i<graph->count;i++){
distance[i]=(int*)malloc(sizeof(int)*graph->count);
}
int j,u,v;
for(i=0;i<graph->count;i++){
    for(j=0;j<graph->count;j++){
        if(i==j){
        distance[i][j]=0;
        }else{
distance[i][j]=max;
//position[i]=-1;
}
    }
}

int* h=(int*)malloc(sizeof(int)*(graph->count)+1);

for(i=0;i<graph->count+1;i++){
h[i]=max;
}
h[graph->count]=0;

for(i=0;i<graph->count;i++){
AddVertex(graph,graph->count,i,0);
}

ALNode* tmpLink;
int newDistance;
tmpLink=graph->GArray[graph->count]->head;
while(tmpLink){
newDistance=tmpLink->wait+h[graph->count];
if(newDistance < h[tmpLink->destination]){
h[tmpLink->destination]=newDistance;
}
tmpLink=tmpLink->next;
}

for(i=0;i<graph->count;i++){
    int u=i;
tmpLink=graph->GArray[i]->head;
while(tmpLink){
newDistance=tmpLink->wait+h[u];
if(newDistance < h[tmpLink->destination]){
h[tmpLink->destination]=newDistance;
}
tmpLink=tmpLink->next;
}
}
/*
printf("\n\nBellman\n\n");
for(i=0;i<graph->count;i++){
printf("%d  ",h[i]);
}
printf("\n\nBellman\n\n");
*/




for(i=0;i<graph->count;i++){
 u=i;
tmpLink=graph->GArray[i]->head;
while(tmpLink){

v=tmpLink->destination;
tmpLink->wait+=h[u]-h[v];
//printf("\nUpdating : for u :%d v: %d :  %d",u,v,tmpLink->wait);
distance[u][v]=tmpLink->wait;
tmpLink=tmpLink->next;
}
}
/*
printf("\nDistance\n");

for(i=0;i<graph->count;i++){

for(j=0;j<graph->count;j++){

printf("%d  ",distance[i][j]);

}
printf("\n");

}

printf("\nDistance\n");
getch();
*/
//distance[sourceNode]=0;
//printf("\nHere 295\n");
for(i=0;i<graph->count;i++){
DijkastraUtil(graph,distance,i);
}
//printf("\nHere 297\n");
PrintDistance(distance,graph->count);
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

printf("\nPress enter to find min distance from all nodes to all nodes  \n");
getch();

DijkastraFinder(graph);
getch();

return 0;
}
