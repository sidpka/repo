#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>


struct EdgeNode{

int src;
int dest;
int wait;

};
typedef struct EdgeNode Edge;

struct GraphNode{

int V;
int E;

Edge* edges;


};
typedef struct GraphNode Graph;

Graph* CreateGraph(int V,int E){

Graph* tmpNode=(Graph*)malloc(sizeof(Graph));
tmpNode->V=V;
tmpNode->E=E;

tmpNode->edges=(Edge*)malloc(sizeof(Edge)*E);
return tmpNode;



}



void FindShortestPath(Graph* graph,int dp[],int source){


dp[source]=0;

int i;
int j;

int src;
int dest;
int wait;

for(i=0;i<graph->V-1;i++){

for(j=0;j<graph->E;j++){

src=graph->edges[j].src;
dest=graph->edges[j].dest;
wait=graph->edges[j].wait;

if(dp[src]!=INT_MAX && dp[src]+wait<dp[dest]){
dp[dest]=dp[src]+wait;
}
}


}

for(i=0;i<graph->E;i++){

src=graph->edges[i].src;
dest=graph->edges[i].dest;
wait=graph->edges[i].wait;

if(dp[src]!=0 && dp[src]+wait<dp[dest]){
printf("\nNegative weight cycle \n");
break;
}

}



}


int main(){

Graph* graph=CreateGraph(5,8);

graph->edges[0].src=0;
graph->edges[0].dest=1;
graph->edges[0].wait=-1;

graph->edges[1].src=0;
graph->edges[1].dest=2;
graph->edges[1].wait=4;

graph->edges[2].src=1;
graph->edges[2].dest=2;
graph->edges[2].wait=3;

graph->edges[3].src=1;
graph->edges[3].dest=3;
graph->edges[3].wait=2;

graph->edges[4].src=1;
graph->edges[4].dest=4;
graph->edges[4].wait=2;

graph->edges[5].src=3;
graph->edges[5].dest=2;
graph->edges[5].wait=5;

graph->edges[6].src=3;
graph->edges[6].dest=1;
graph->edges[6].wait=1;

graph->edges[7].src=4;
graph->edges[7].dest=3;
graph->edges[7].wait=-3;

int dp[graph->V];

int i;

for(i=0;i<graph->V;i++){
dp[i]=INT_MAX;
}

FindShortestPath(graph,dp,0);

printf("\nShortest path from Node[%d] to all nodes : \n",0);

for(i=0;i<graph->V;i++){
printf("\n%d   %d  : %d",0,i,dp[i]);
}


return 0;
}
