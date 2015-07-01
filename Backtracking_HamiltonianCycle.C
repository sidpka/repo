#include<stdio.h>
#include<conio.h>
#define V 5

int IsSafe(int v,int graph[V][V],int path[],int pos){

if(graph[path[pos-1]][v]==0){
return 0;
}

int i;

for(i=0;i<pos;i++){
if(path[i]==v){
return 0;
}
}

return 1;
}

int HamiltonianCycle_Util(int graph[V][V],int path[],int pos){
if(pos==V){
if(graph[path[pos-1]][path[0]]){
return 1;
}else{
return 0;
}
}

int i;

for(i=1;i<V;i++){
if(IsSafe(i,graph,path,pos)){
path[pos]=i;

if(HamiltonianCycle_Util(graph,path,pos+1)){
return 1;
}
path[pos]=-1;

}
}
return 0;
}

void HamiltonianCycle(int graph[V][V]){

int path[V];

int i;

for(i=1;i<V;i++){
path[i]=-1;
}

path[0]=0;

if(HamiltonianCycle_Util(graph,path,1)==0){
return;
}

for(i=0;i<V;i++){
printf("%d  ",path[i]);
}
printf("%d  ",path[0]);






}

int main(){


int graph[V][V]={ {0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0}};


HamiltonianCycle(graph);
return 0;
}
