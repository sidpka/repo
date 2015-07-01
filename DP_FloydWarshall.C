#include<stdio.h>
#include<conio.h>
#define inf 9999
#define V 4

void FindAllPairShortestPath(int graph[V][V]){


int i;
int j;
int k;

int dp[V][V];

for(i=0;i<V;i++){

for(j=0;j<V;j++){
dp[i][j]=graph[i][j];
}

}

for(k=0;k<V;k++){

for(i=0;i<V;i++){

for(j=0;j<V;j++){

if(dp[i][k]!=inf && dp[k][j]!=inf && dp[i][k]+dp[k][j]<dp[i][j]){
dp[i][j]=dp[i][k]+dp[k][j];
}

}

}



}

for(i=0;i<V;i++){

for(j=0;j<V;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");
}



}

int main(){

int graph[V][V]={{0,5,inf,10},{inf,0,3,inf},{inf,inf,0,1},{inf,inf,inf,0} };

FindAllPairShortestPath(graph);







return 0;
}
