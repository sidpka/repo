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

void PrintTransitiveClosure(int** reach,int n){

int i;
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d  ",reach[i][j]);
}
printf("\n");
}

}

void TransitiveClosure(int** array,int n){

int i;
int j;
int** reach=(int**)malloc(sizeof(int*)*n);

for(i=0;i<n;i++){
reach[i]=(int*)malloc(sizeof(int)*n);
}

int k;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
reach[i][j]=array[i][j];
}
}


for(k=0;k<n;k++){

for(i=0;i<n;i++){
for(j=0;j<n;j++){
reach[i][j]=(reach[i][j])|| (reach[i][k] && reach[k][j]);
}
}
}

PrintTransitiveClosure(reach,n);
}



int CountPath(int** array,int src,int dest,int K,int n){

int Count[n][n][K+1];
int i,j,e,a;

for(e=0;e<=K;e++){

for(i=0;i<n;i++){
for(j=0;j<n;j++){
Count[i][j][e]=0;

if(e==0 && i==j){
Count[i][j][e]=1;
}

if(e==1 && array[i][j]){
Count[i][j][e]=1;
}

if(e>1){

for(a=0;a<n;a++){

if(array[i][a]){
Count[i][j][e]+=Count[a][j][e-1];
}

}

}


}
}




}
return Count[src][dest][K];
}




int countwalks(int** graph, int u, int v, int k,int n)
{
    // Table to be filled up using DP. The value count[i][j][e] will
    // store count of possible walks from i to j with exactly k edges
    int count[n][n][k+1];

    // Loop for number of edges from 0 to k
    for (int e = 0; e <= k; e++)
    {
        for (int i = 0; i < n; i++)  // for source
        {
            for (int j = 0; j < n; j++) // for destination
            {
                // initialize value
                count[i][j][e] = 0;

                // from base cases
                if (e == 0 && i == j)
                    count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;

                // go to adjacent only when number of edges is more than 1
                if (e > 1)
                {
                    for (int a = 0; a < n; a++) // adjacent of source i
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e-1];
                }
           }
        }
    }
    return count[u][v][k];
}

int main(){
int n;

printf("\nEnter the number of nodes in graph :  ");
scanf("%d",&n);

int** array=(int**)malloc(sizeof(int*)*n);

int i;

for(i=0;i<n;i++){
array[i]=(int*)malloc(sizeof(int)*n);
}

int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
    if(i==j){
    array[i][j]=1;
    }else{
    array[i][j]=0;
    }
}
}

printf("\nEnter the no of edges : ");
int E;
scanf("%d",&E);

int src,dest;

for(i=0;i<E;i++){
printf("\nEnter  src n dest :  ");
scanf("%d %d",&src,&dest);
array[src][dest]=1;
}

//TransitiveClosure(array,n);return 0;

int k;

printf("\nEnter src,dest and K to see no of path using k edges : ");
scanf("%d %d %d",&src,&dest,&k);
printf("\nPress enter to see no of path : ");
int result=countwalks (array,src,dest,k,n);
getch();
printf("%d ",result);

return 0;
}
