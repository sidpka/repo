#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

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


void PrintDistance(int* distance,int size){
int i;

for(i=0;i<size;i++){
printf("%d  ",distance[i]);
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

void DijkastraUtil(GNode* graph,int* distance,int sourceNode){
//printf("\n234");

//PopulatePosition(graph->count);
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
//pQueue->HArray[sourceNode]=NewNode(sourceNode,0);
//pQueue->pos[sourceNode]=sourceNode;
/*
HHNode* newNode=(HHNode*)malloc(sizeof(HHNode));
newNode->vertex=sourceNode;
newNode->weight=distance[sourceNode];
//printf("\nSource : %d Distance : %d",sourceNode,distance[sourceNode]);
EnPQueue(pQueue,newNode);
*/

ALNode* tmpLink;
int newDistance;

//printf("\nCount : %d",pQueue->count);
/*
int j;
printf("\nPosition\n");
for(j=0;j<graph->count;j++){
printf("%d  ",position[j]);
}
printf("\nPosition\n");
getch();
*/
while(!IsEmptyPQueue(pQueue)){
tmpNode=DePQueue(pQueue);
tmpLink=graph->GArray[tmpNode->vertex]->head;
//printf("\nCount : %d DQ : %d ",pQueue->count,tmpNode->vertex);
//printf("\n\nditsance \n\n");
/*
for(i=0;i<graph->count;i++){
printf("%d  ",distance[i]);
}
printf("\n\nditsance \n\n");
*/
/*
printf("\nPosition\n");
for(j=0;j<graph->count;j++){
printf("%d  ",position[j]);
}
printf("\nPosition\n");
getch();
*/
while(tmpLink){
newDistance=distance[tmpNode->vertex]+tmpLink->wait;
//printf("\n264");
/*
if(distance[tmpLink->destination]==-1){
distance[tmpLink->destination]=newDistance;
newNode=(HHNode*)malloc(sizeof(HHNode));
newNode->vertex=tmpLink->destination;
newNode->weight=distance[tmpLink->destination];
//printf("\n270");
EnPQueue(pQueue,newNode);
//printf("\n272");
}
*/


if(IsInQueue(pQueue,tmpLink->destination) && distance[tmpLink->destination]> newDistance){
distance[tmpLink->destination]=newDistance;
UpdateWeight(pQueue,tmpLink->destination,newDistance);
}





//else if(distance[tmpLink->destination]> newDistance){
    /*printf("\n276 n the vertex we are sending is : %d",tmpLink->destination);
    printf("\nHeap\n");
    for(i=0;i<graph->count;i++){
    printf("%d  ",pQueue->HArray[i]->vertex);
    }
    printf("\nHeap\n");
    */
//distance[tmpLink->destination]=newDistance;
//i=GetIndex(pQueue,tmpLink->destination);
//i=position[tmpLink->destination];

// for linear time to search in heap we track position of vertex
/*
int j;
printf("\nPosition\n");
for(j=0;j<graph->count;j++){
printf("%d  ",position[j]);
}
printf("\nPosition\n");
printf("\nIndex is : %d\n",i);
getch();
*/
/*
if(i==-1){
    //printf("\n280");
newNode=(HHNode*)malloc(sizeof(HHNode));
newNode->vertex=tmpLink->destination;
newNode->weight=distance[tmpLink->destination];
EnPQueue(pQueue,newNode);
//printf("\n285");
}else{
  //printf("\n287");
UpdateWeight(pQueue,i,newDistance);
//printf("\n289");
}

}
*/
tmpLink=tmpLink->next;
}


}

PrintDistance(distance,graph->count);
}

void DijkastraFinder(GNode* graph,int sourceNode){

int* distance=(int*)malloc(sizeof(int)*graph->count);
//static int* position=(int*)malloc(sizeof(int)*graph->count);
int i;

for(i=0;i<graph->count;i++){
distance[i]=INT_MAX;
//position[i]=-1;
}
distance[sourceNode]=0;
//printf("\nHere 295\n");
DijkastraUtil(graph,distance,sourceNode);
//printf("\nHere 297\n");
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
printf("\nEnter the source Node you want to find min dsitance from : ");
int sourceNode;
scanf("%d",&sourceNode);
printf("\nPress enter to find min distance from %d \n",sourceNode);
getch();

DijkastraFinder(graph,sourceNode);
getch();

return 0;
}
