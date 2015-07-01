#include<stdio.h>
#include<conio.h>
#define V 4
#define max 9999

int min(int a,int b){
return a<b?a:b;
}

int FindShortestP(int path[V][V],int src,int dest,int K){

if(src==dest && K==0){
return 0;
}
else if(src==dest && K !=0){
return max;
}else if(K==1 && path[src][dest]){
return path[src][dest];
}


int i;
int result=max;

for(i=0;i<V;i++){

if(path[src][i]){
result=min(result,path[src][i]+FindShortestP(path,i,dest,K-1));
}
}



return result;

}

int FindShortestP_DP(int path[V][V],int src,int dest,int K){

if(src==dest && K==0){
return 0;
}

int minPath[V][V][K+1];

int i;
int j;
int k;
int m;
int result;

for(k=1;k<=K;k++){

for(i=0;i<V;i++){

for(j=0;j<V;j++){

if(k==1){
if(path[i][j]){
minPath[i][j][k]=path[i][j];
}else{
minPath[i][j][k]=max;
}

}else{

result=max;

for(m=0;m<V;m++){
if(path[i][m]){
result=min(result, path[i][m]+minPath[m][j][k-1]);
}
}
minPath[i][j][k]=result;




}

}

}



}





return minPath[src][dest][K];
}

int main(){

int path[V][V]={{0,10,3,2},{0,0,0,7},{0,0,0,6},{0,0,0,0}};
int src=0;
int dest=3;
int K=2;

//printf("\nShortest path form src[%d] to dest[%d] : %d",src,dest,FindShortestP(path,src,dest,K));
printf("\nShortest path form src[%d] to dest[%d] : %d",src,dest,FindShortestP_DP(path,src,dest,K));




return 0;
}
