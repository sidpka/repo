#include<stdio.h>
#include<conio.h>
#define V 4


int min(int a,int b){
return a<b?a:b;
}

int IsSafe(int v,int path[V][V],int route[],int pos){

if(path[route[pos-1] ][v]==0){
return 0;
}

int i;

for(i=0;i<pos;i++){
if(route[i]==v){
return 0;
}
}
return 1;

}

void FindTSP_Util(int path[V][V],int route[],int pos,int sum,int* minSum,int tspPath[]){

if(pos==V){
if(path[route[pos-1]][0]){
sum+=path[route[pos-1] ][0];
if(sum<(*minSum)){
(*minSum)=sum;
int i;
for(i=0;i<V;i++){
tspPath[i]=route[i];
}

}
}
return;
}

int v;

for(v=1;v<V;v++){

if(IsSafe(v,path,route,pos)){

route[pos]=v;
sum+=path[route[pos-1] ][v];
FindTSP_Util(path,route,pos+1,sum,minSum,tspPath);
sum-=path[route[pos-1]][v];
route[pos]=-1;


}




}





}
int FindTSP(int path[V][V]){
int i;
int route[V];


for(i=1;i<V;i++){
route[i]=-1;
}

int sum=0;
int minSum=99999;
route[0]=0;
int tspPath[V];
FindTSP_Util(path,route,1,sum,&minSum,tspPath);
printf("\nTravelling salesman takes path \n\n");


for(i=0;i<V;i++){
printf("%d  ",tspPath[i]);
}
printf("%d\n",tspPath[0]);
return minSum;
}

int main(){

int path[V][V]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};


printf("\nMin Path Cost : %d",FindTSP(path));





return 0;
}
