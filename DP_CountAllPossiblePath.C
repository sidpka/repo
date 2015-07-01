#include<stdio.h>
#include<conio.h>
#define V 4
#define max 9999

int min(int a,int b){
return a<b?a:b;
}

int FindShortestP(int path[V][V],int src,int dest,int K){

if(src==dest && K==0){
return 1;
}
else if(src==dest && K !=0){
return 0;
}else if(K==1 && path[src][dest]){
return 1;
}


int i;
int result=0;

for(i=0;i<V;i++){

if(path[src][i]){
result+=FindShortestP(path,i,dest,K-1);
}
}



return result;

}

int FindShortestP_DP(int path[V][V],int src,int dest,int K){

if(src==dest && K==0){
return 1;
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
minPath[i][j][k]=1;
}else{
minPath[i][j][k]=0;
}

}else{

result=0;

for(m=0;m<V;m++){
if(path[i][m]){
result+=minPath[m][j][k-1];
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

//printf("\No of path form src[%d] to dest[%d] : %d",src,dest,FindShortestP(path,src,dest,K));
printf("\nShortest path form src[%d] to dest[%d] : %d",src,dest,FindShortestP_DP(path,src,dest,K));




return 0;
}
