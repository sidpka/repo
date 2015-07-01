#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



#define max 9999


void PrintAllNodesShortestPath(int** distance,int n){

int i;
int j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d       ",distance[i][j]);
}
printf("\n");
}

}

void FloydWarshall(int** graph,int n){

int** distance=(int**)malloc(sizeof(int*)*n);
int i;
for(i=0;i<n;i++){
distance[i]=(int*)malloc(sizeof(int)*n);
}
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
distance[i][j]=graph[i][j];
}
}

int k;


for(k=0;k<n;k++){
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(distance[i][j]> distance[i][k]+distance[k][j]){
distance[i][j]=distance[i][k]+distance[k][j];
}
}
}
}

PrintAllNodesShortestPath(distance,n);

}

int main(){



printf("\nEnter the number of vertices in graph...\n");
int n;
scanf("%d",&n);

printf("\nEnter the number of edges in graph : ");
int E;
scanf("%d",&E);

int i;
int j;

int** graph=(int**)malloc(sizeof(int*)*n);
for(i=0;i<n;i++){
graph[i]=(int*) malloc(sizeof(int)*n);
}


printf("\nEnter the edges of graph \n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
    if(i==j){
    graph[i][j]=0;
    }
    else{
graph[i][j]=max;
    }
}
}
int src,dest,weight;
for(i=0;i<E;i++){
printf("Enter source destination and weight :   ");
scanf("%d %d %d",&src,&dest,&weight);
graph[src][dest]=weight;
}

printf("\nPress enter to get shortest path to all nodes from all source \n");
getch();

FloydWarshall(graph,n);

return 0;
}
