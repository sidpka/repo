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

qsort(arr,n,sizeof(Point),cmpY);
for(i=0;i<n;i++){
for(j=i+1;(j<n &&  (arr[j].y-arr[i].y) <d);j++ ){
if(FindDistance(arr[i],arr[j])<min)
min=FindDistance(arr[i],arr[j]);
}

}

return min;
}


float FindClosestDistance(Point arr[],int n){

if(n<=3){
return FindBrute(arr,n);
}

int mid=n/2;
Point midPoint=arr[mid];

float dl=FindClosestDistance(arr,n/2);
float dr=FindClosestDistance(arr+n/2,n-mid);
//printf("\nHere");
float d=min(dl,dr);
//printf("\nHere");
int i;

Point strip[n];
int j=0;
//printf("\nHere");
for(i=0;i<n;i++){
if( abs(arr[i].x-midPoint.x)<d ){
strip[j++]=arr[i];
}
}

//printf("\nHere");
//float x=FindStrip(strip,j,d);
//printf("\n%f\n",x);
//getch();
return min(d,FindStrip(arr,j,d));


}

int main(){

Point arr[]={{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
int n=sizeof(arr)/sizeof(arr[0]);
qsort(arr,n,sizeof(Point),cmpX);
printf("\nClosest distance : %f",FindClosestDistance(arr,n));
//printf("\n%f",FLT_MAX);


return 0;
}
