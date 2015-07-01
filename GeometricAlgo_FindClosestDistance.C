#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

struct Points{
int x;
int y;
};
typedef struct Points Point;


int cmpX(const void* a,const void* b){

Point* p1=(Point*)a;
Point* p2=(Point*)b;

return p1->x-p2->x;
}

int cmpY(const void* a,const void* b){

Point* p1=(Point*)a;
Point* p2=(Point*)b;
//printf("\nComing");
return (p1->y-p2->y);
}


float FindDistance(Point a,Point b){

return sqrt(  (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

float FindBrute(Point arr[],int n){

float min=FLT_MAX;

int i;
int j;

for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(FindDistance(arr[i],arr[j])<min){
min=FindDistance(arr[i],arr[j]);
}
}
}


return min;
}


float min(float a,float b){

return a<b?a:b;
}


float FindStrip(Point arr[],int n,float d){
//printf("\nHere");
float min=d;

int i;
int j;

//qsort(arr,n,sizeof(Point),cmpY);
for(i=0;i<n;i++){
for(j=i+1;(j<n &&  (arr[j].y-arr[i].y) <d);j++ ){
if(FindDistance(arr[i],arr[j])<min)
min=FindDistance(arr[i],arr[j]);
}

}

return min;
}


float FindClosestDistance(Point pX[],Point pY[],int n){

if(n<=3){
return FindBrute(pX,n);
}

int mid=n/2;
Point midPoint=pX[mid];

Point pYL[mid+1];
Point pYR[n-mid-1];

int li=0;
int ri=0;

int k;

for(k=0;k<n;k++){
if(pY[k].x<midPoint.x){
pYL[li++]=pY[k];
}else{
pYR[ri++]=pY[k];
}
}

float dl=FindClosestDistance(pX,pYL,mid);
float dr=FindClosestDistance(pX+mid,pYR,n-mid);
//printf("\nHere");
float d=min(dl,dr);
//printf("\nHere");
int i;

Point strip[n];
int j=0;
//printf("\nHere");
for(i=0;i<n;i++){
if( abs(pY[i].x-midPoint.x)<d ){
strip[j++]=pY[i];
}
}

//printf("\nHere");
//float x=FindStrip(strip,j,d);
//printf("\n%f\n",x);
//getch();
return min(d,FindStrip(strip,j,d));


}

float FindClosestDist(Point arr[],int n){

Point pX[n];
Point pY[n];

int i;

for(i=0;i<n;i++){
pX[i]=arr[i];
pY[i]=arr[i];
}


qsort(pX,n,sizeof(Point),cmpX);
qsort(pY,n,sizeof(Point),cmpY);

return FindClosestDistance(pX,pY,n);

}

int main(){

Point arr[]={{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
int n=sizeof(arr)/sizeof(arr[0]);
//qsort(arr,n,sizeof(Point),cmpX);
printf("\nClosest distance : %f",FindClosestDist(arr,n));
//printf("\n%f",FLT_MAX);


return 0;
}
