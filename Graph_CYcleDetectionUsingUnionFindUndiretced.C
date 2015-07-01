#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Edge{
int src;
int dest;
};
typedef struct Edge ENode;


struct Graph{
int V;
int E;

ENode** Array;

};
typedef struct Graph GNode;

GNode* CreateGraph(int V,int E){

GNode* graph=(GNode*)malloc(sizeof(GNode));

graph->V=V;
graph->E=E;

graph->Array=(ENode**)malloc(sizeof(ENode*)*E);

int i;

for(i=0;i<E;i++){
graph->Array[i]=(ENode*)malloc(sizeof(ENode));
}
return graph;
}

/*
int Find(int* Parent,int root){

if(Parent[root]==-1){
return root;
}
return Find(Parent,Parent[root]);
}


void Unify(int* Parent,int root,int child){
int x=Find(Parent,root);
int y=Find(Parent,child);

if(x==y){
return;
}

Parent[child]=root;

}

int FindCycle(GNode* graph){

int* Parent=(int*)malloc(sizeof(int)*graph->V);
int i;
for(i=0;i<graph->V;i++){
Parent[i]=-1;
}
int x;
int y;
for(i=0;i<graph->E;i++){
x=Find(Parent,graph->Array[i]->src);
y=Find(Parent,graph->Array[i]->dest);
if(x==y){
return 1;
}
Unify(Parent,x,y);
}

return 0;
}


*/


int Find(int* Parent,int root){

if(Parent[root]<0){
return root;
}
return (Parent[root]=Find(Parent,Parent[root]));
}


void Unify(int* Parent,int root,int child){
int x=Find(Parent,root);
int y=Find(Parent,child);

if(x==y){
return;
}

if(Parent[root]<Parent[child]){
Parent[root]+=Parent[child];
Parent[child]=root;
}else{
Parent[child]+=Parent[root];
Parent[root]=child;
}


}

int FindCycle(GNode* graph){

int* Parent=(int*)malloc(sizeof(int)*graph->V);
int i;
for(i=0;i<graph->V;i++){
Parent[i]=-1;
}
int x;
int y;
for(i=0;i<graph->E;i++){
x=Find(Parent,graph->Array[i]->src);
y=Find(Parent,graph->Array[i]->dest);
printf("\nRoot of %d is : %d",graph->Array[i]->src,x);
printf("\nRoot of %d is : %d",graph->Array[i]->dest,y);
if(x==y){
return 1;
}
Unify(Parent,x,y);
}

return 0;
}



int main(){

int V;
int E;
printf("\nNo of vertices n edges in graph : ");
scanf("%d %d",&V,&E);

GNode* graph=CreateGraph(V,E);

int i;

for(i=0;i<E;i++){
printf("Edge[%d]  : Src  and dest :  ",i);
scanf("%d %d",&graph->Array[i]->src,&graph->Array[i]->dest);
}

for(i=0;i<E;i++){
printf("\n%d  --  %d",graph->Array[i]->src,graph->Array[i]->dest);
}

getch();
// There are two functions but the one which is not commented is more efficient
int result=FindCycle(graph);

printf("\nPress enter to check if cycle exists");
getch();

if(result){
printf("\nCycle found");
}else{
printf("\nCycle not found");
}
getch();


return 0;
}
