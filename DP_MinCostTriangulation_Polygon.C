#include<stdio.h>
#include<conio.h>
#include<math.h>


struct Point{
int x;
int y;
};
typedef struct Point Points;


double min(double a,double b){
return a<b?a:b;

}

double FindDistance(Points a,Points b){


double xLen=(a.x-b.x)*(a.x-b.x);
double yLen=(a.y-b.y)*(a.y-b.y);

return sqrt(xLen+yLen);

}

double FindCost(Points point[],int i,int k,int j){

Points a=point[i];
Points b=point[k];
Points c=point[j];

return FindDistance(a,b)+FindDistance(b,c)+FindDistance(a,c);


}

double FindMinTriangulationCost(Points point[],int i,int j){

if(j<i+2){
return 0;
}

double minCost=99999.0;

int k;

for(k=i+1;k<j;k++){

minCost=min(minCost,(FindMinTriangulationCost(point,i,k)+FindMinTriangulationCost(point,k,j)+FindCost(point,i,k,j)));
//printf("\nMin C; %d",minCost);
}
//printf("\nMin Cost : %d",minCost);
return minCost;

}


double FindMinTriangulationCost2(Points point[], int n){

if(n<3){
return 0.0;
}

double cost[n][n];

int i;
int j;
int k;
int gap;

for(gap=0;gap<n;gap++){

for(i=0,j=gap;j<n;i++,j++){

if(j<i+2){
cost[i][j]=0.0;
}else{

double val=9999.0;
cost[i][j]=val;
for(k=i+1;k<j;k++){
val=cost[i][k]+cost[k][j]+FindCost(point,i,k,j);
printf("\nVal : %d",val);
if(cost[i][j]>val){
cost[i][j]=val;
}
}


}

}



}

return cost[0][n-1];
}


int main(){

Points point[]={{0,0},{1,0},{2,1},{1,2},{0,2}};
int n=sizeof(point)/sizeof(point[0]);

//printf("\nMin cost of triangulation : %f",FindMinTriangulationCost(point,0,n-1));

printf("\nMin cost of triangulation : %f",FindMinTriangulationCost2(point,n));



return 0;
}
