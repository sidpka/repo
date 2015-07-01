#include<stdio.h>
#include<conio.h>
#define inf 1000


struct Points{
int x;
int y;
};
typedef struct Points Point;



int FindOrient(Point p,Point q,Point r){

int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);

if(val==0){
return 0;
}

return (val>0)?1:2;

}

int max(int a,int b){

return a>b?a:b;
}

int min(int a,int b){

return a<b?a:b;
}


int IsOnLine(Point p,Point q,Point r){


if(  (q.x <= max(p.x,r.x) && q.x>=min(p.x,r.x) ) && ( q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y)   )   ){

return 1;
}


return 0;
}


int FindIfIntersect(Point p1,Point q1,Point p2,Point q2){

int o1=FindOrient(p1,q1,p2);
int o2=FindOrient(p1,q1,q2);
int o3=FindOrient(p2,q2,p1);
int o4=FindOrient(p2,q2,q1);


if(o1!=o2 && o3!=o4){

return 1;
}


if(o1==0 && IsOnLine(p1,p2,q1)){

return 1;
}

if(o2==0 && IsOnLine(p1,q2,q1)){

return 1;
}

if(o3==0 && IsOnLine(p2,p1,q2)){

return 1;
}

if(o4==0 && IsOnLine(p2,q1,q2)){

return 1;
}


return 0;



}

int FindIfInside(Point polygon[],int n,Point p){

Point extreme={inf,p.y};

int i=0;
int next;
int count=0;

do{

next=(i+1)%n;

if(FindIfIntersect(polygon[i],polygon[next],p,extreme )){

if(FindOrient(polygon[i],polygon[next],p)==0){
//printf("\nHere for i : %d next : %d",i,next);
return IsOnLine(polygon[i],p,polygon[next]);

}
count++;

}



i=next;

}while(i!=0);


//printf("\nCount is : %d",count);
return count&1;

}


int main(){

Point polygon[]={{0,0},{10,0},{10,10},{0,10}};
//Point p={20,20};
Point p={5,5};
int n=sizeof(polygon)/sizeof(polygon[0]);



int result=FindIfInside(polygon,n,p);


result==1?printf("\nInside"):printf("\nOutside");




return 0;
}
