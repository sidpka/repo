#include<stdio.h>
#include<conio.h>
#define inf 10000
#define n 4

int FindMinCost(int cost[n][n]){


int minCost[n];

int i;
int j;

for(i=0;i<n;i++){
minCost[i]=cost[0][i];
}

for(i=1;i<n;i++){
for(j=i+1;j<n;j++){
if(minCost[i]+cost[i][j]<minCost[j]){
minCost[j]= cost[i][j]+minCost[i];
}
}
}

return minCost[n-1];



}

int main(){


int cost[n][n]={
                 {0,15,80,90},
                  {inf,0,40,50},
                  {inf,inf,0,70},
                   {inf,inf,inf,0} };



printf("\nMin Cost of travelling from station[0] to station[%d] : %d",n,FindMinCost(cost));



return 0;
}
