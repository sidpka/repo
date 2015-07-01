#include<stdio.h>
#include<conio.h>
#define V 4



int IsSafeAssignment(int graph[V][V],int vertex,int color[],int currentColor){

int i;

for(i=0;i<V;i++){
if(graph[vertex][i] && color[i]==currentColor){
return 0;
}
}

return 1;

}


int FindColor_Util(int graph[V][V],int vertex,int color[],int m){
if(vertex==V){
return 1;
}

int i;

for(i=1;i<=m;i++){

if(IsSafeAssignment(graph,vertex,color,i)){
color[vertex]=i;

if(FindColor_Util(graph,vertex+1,color,m)){
return 1;
}else{
color[vertex]=0;
}

}

}


return 0;



}

void PrintColor(int color[]){

int i;

for(i=0;i<V;i++){
printf("%d  ",color[i]);
}

}

void FindColor(int graph[V][V],int m){

int color[V];

int i;

for(i=0;i<V;i++){
color[i]=0;
}

if(FindColor_Util(graph,0,color,m)){
PrintColor(color);
}else{
printf("\nGraph can not be colored \n");
}



}

int main(){


int graph[V][V]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};

int m=3;

FindColor(graph,m);






return 0;
}
