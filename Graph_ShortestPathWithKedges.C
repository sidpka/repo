#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 999




/*

int CountPath(int** graph,int src,int dest,int K,int n){
if(K==0 && src==dest){
return 0;
}

if(K==1 && graph[src][dest]!=max){
graph[src][dest];
}


if(K<=0){
return max;
}

int count=max;
int tmpCount;
int i;

for(i=0;i<n;i++){
    if(graph[src][i]!=max){
tmpCount=CountPath(graph,i,dest,K-1,n) + graph[src][i];
if(tmpCount<count){
count=tmpCount;
}
    }
}

return count;
}

*/


int CountPath(int** graph,int src,int dest,int K,int n){

int Count[n][n][K+1];
int i,j,k;
int tmpCount;
int a;

for(k=0;k<K+1;k++){

for(i=0;i<n;i++){
for(j=0;j<n;j++){
Count[i][j][k]=max;
if(k==0 && i==j){
Count[i][j][k]=0;
}

if(k==1 && graph[i][j]!=max){
Count[i][j][k]=graph[i][j];
}

if(k>1){
for(a=0;a<n;a++){
if(graph[i][a]!=max && i!=a && j!=a){
tmpCount=Count[a][j][k-1]+graph[i][a];
if(tmpCount<Count[i][j][k]){
Count[i][j][k]=tmpCount;
}
}
}
}

}
}

}

return Count[src][dest][K];
}


int main(){

printf("\nEnter the no of vertices : ");
int n,E;
scanf("%d",&n);

printf("\nEnter the number of edges : ");
scanf("%d",&E);

int** graph=(int**)malloc(sizeof(int*)*n);

int i;

for(i=0;i<n;i++){
graph[i]=(int*)malloc(sizeof(int)*n);
}
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
graph[i][j]=max;
}
}

int src,dest,weight;

for(i=0;i<E;i++){
    printf("\nEnter src , dest, and weight :  ");
scanf("%d %d %d",&src,&dest,&weight);
graph[src][dest]=weight;
}

int K;
printf("\nEnter src,dest and K value to find path from src to dest with K intermediate nodes \n");
scanf("%d %d %d",&src,&dest,&K);
int result=CountPath(graph,src,dest,K,n);
printf("\nShortest path with : %d edges : %d",K,result);
getch();
return 0;
}
