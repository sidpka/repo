#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 999


/*

int CountPath(int** graph,int src,int dest,int K,int n){
if(K==0 && src==dest){
return 1;
}

if(K==1 && graph[src][dest]!=max){
return 1;
}

if(K<=0){
return 0;
}

int count=0;

int i;

for(i=0;i<n;i++){
    if(graph[src][i]!=max){
count+=CountPath(graph,i,dest,K-1,n);
    }
}

return count;
}
*/



int CountPath(int** graph,int src,int dest,int K,int n){

int Count[n][n][K+1];
int i,j,k;

int a;

for(k=0;k<K+1;k++){

for(i=0;i<n;i++){
for(j=0;j<n;j++){
Count[i][j][k]=0;
if(k==0 && i==j){
Count[i][j][k]=1;
}

if(k==1 && graph[i][j]!=max){
Count[i][j][k]=1;
}

if(k>1){
for(a=0;a<n;a++){
if(graph[i][a]!=max){
Count[i][j][k]+=Count[a][j][k-1];
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
printf("\n%d such path exists",result);
getch();
return 0;
}
