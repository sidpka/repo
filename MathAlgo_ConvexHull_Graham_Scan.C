#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Points{
int x;
int y;
};
typedef struct Points Point;

struct StackNode{

int capacity;
int top;
Point* array;
};
typedef struct StackNode SNode;

SNode* CreateStack(int n){

SNode* newNode=(SNode*)malloc(sizeof(SNode));
newNode->top=-1;
newNode->capacity=n;
newNode->array=(Point*)malloc(sizeof(Point)*n);

return newNode;
}

void Push(SNode* stack,Point p){
stack->array[++stack->top]=p;
}

Point Pop(SNode* stack){

return stack->array[stack->top--];
}

int IsStackEmpty(SNode* stack){

return stack->top==-1;
}

Point Top(SNode* stack){

return stack->array[stack->top];
}

Point NextTop(SNode* stack){

return stack->array[stack->top-1];
}

int FindOrient(Point p,Point q,Point r){

int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

if(val==0){
return 0;
}

return (val>0)?1:2;

}


int FindDistance(Point p1,Point p2){


return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}


Point p0;


int cmp(const void* a,const void* b){

Point* p1=(Point*)a;
Point* p2=(Point*)b;

int ornt=FindOrient(p0,*p1,*p2);

if(ornt==0){

return FindDistance(p0,*p2)>=FindDistance(p0,*p1)?-1:1;
}

return (ornt==2)?-1:1;

}



void FindConvexHull(Point points[],int n){

int miny=points[0].y;
int min=0;

int i;

for(i=1;i<n;i++){
if(points[i].y<=miny){

if(points[i].y==miny && points[i].x<points[min].x){
miny=points[i].y;
min=i;
}

}
}
Point tmp=points[0];
points[0]=points[min];
points[min]=tmp;

p0=points[0];

qsort(&points[1],n-1,sizeof(Point),cmp);


SNode* stack=CreateStack(n);

Push(stack,points[0]);
Push(stack,points[1]);
Push(stack,points[2]);

for(i=3;i<n;i++){

while(FindOrient(NextTop(stack),Top(stack),points[i])!=2){
Pop(stack);

}
Push(stack,points[i]);

}

while(!IsStackEmpty(stack)){
Point tmp=Pop(stack);
printf("\n{ %d , %d }",tmp.x,tmp.y);
}

}

int main(){

Point points[]={{0, 3}, {1, 1}, {2, 2}, {4, 4},
                       {0, 0}, {1, 2}, {3, 1}, {3, 3 }};


int n=sizeof(points)/sizeof(points[0]);

FindConvexHull(points,n);



return 0;
}
