#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
/*

It is similar to dijkastra algorithm
we just need to check if the cost of
reaching a node is smaller tham already found
then we replace the distance of that node to
the distance of reaching from
other node

*/

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

int src;
int dest;
int weight;
};

typedef struct HeapHelper HHNode;

struct Heap{
int count;
int capacity;
HHNode** HArray;
};

typedef struct Heap HNode;

HNode* CreatePQueue(int v){

HNode* newNode=(HNode*)malloc(sizeof(HNode));
newNode->capacity=v;
newNode->count=0;
newNode->HArray=(HHNode**)malloc(sizeof(HHNode*)*v);
return newNode;
}


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
int pos;
while(i>0 && heap->HArray[(i-1)/2]->weight > node->weight){
heap->HArray[i]=heap->HArray[(i-1)/2];
//position[heap->HArray[i]->vertex]=i;
i=(i-1)/2;
}

heap->HArray[i]=node;
//position[node->vertex]=i;
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
heap->HArray[min]=tmpNode;
//position[heap->HArray[min]->vertex]=min;
PercolateDown(heap,min);
}


}

HHNode* DePQueue(HNode* heap){
HHNode* tmpNode=heap->HArray[0];
//position[heap->HArray[0]->vertex]=-1;
heap->HArray[0]=heap->HArray[heap->count-1];
//position[heap->HArray[heap->count-1]->vertex]=0;
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

void MakeSet(int* array,int n){

int i;

for(i=0;i<n;i++){
array[i]=-1;
}

}

int Find(int* array,int i){

if(array[i]<0){
return i;
}

return (array[i]=Find(array,array[i]));
}

void MakeUnion(int* array,int x,int y){
if(Find(array,x)==Find(array,y)){
return;
}

if(array[x]<array[y]){
array[x]+=array[y];
array[y]=x;
}else{
array[y]+=array[x];
array[x]=y;

}
}

HHNode* NewNode(int src,int dest,int weight){
HHNode* newNode=(HHNode*)malloc(sizeof(HHNode));
newNode->src=src;
newNode->dest=dest;
newNode->weight=weight;
return newNode;
}

int Kruskal(GNode* graph,int E){

HNode* heap=CreatePQueue(E);

int i;
HHNode* newNode;
ALNode* tmpNode;
for(i=0;i<graph->count;i++){
tmpNode=graph->GArray[i]->head;
while(tmpNode){
newNode=NewNode(i,tmpNode->destination,tmpNode->wait);
EnPQueue(heap,newNode);
tmpNode=tmpNode->next;
}
}

int sum=0;
int parentSrc;
int parentDest;
int* array=(int*)malloc(sizeof(int)*graph->count);

MakeSet(array,graph->count);

while(!IsEmptyPQueue(heap)){
newNode=DePQueue(heap);
parentSrc=Find(array,newNode->src);
parentDest=Find(array,newNode->dest);

if(parentDest!=parentSrc){
MakeUnion(array,parentDest,parentSrc);
sum+=newNode->weight;
}

}

return sum;

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
printf("\nPress enter to get MST using Kruskal\n");
getch();

int result=Kruskal(graph,E);
printf("\nMST is : %d",result);
getch();
return 0;
}
