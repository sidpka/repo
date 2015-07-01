#include<stdio.h>
#include<conio.h>


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


void FindConvexHull(Point points[],int n){

int next[n];
int i;

for(i=0;i<n;i++){
next[i]=-1;
}

int l=0;

int p;
int q;

for(i=0;i<n;i++){

if(points[i].x<points[l].x){
l=i;
}

}

//printf("\nLeft most point is : %d",l);

p=l;

do{


q=(p+1)%n;

for(i=0;i<n;i++){

if(FindOrient(points[p],points[i],points[q])==2){
q=i;
}

}

next[p]=q;
p=q;





}while(p!=l);


printf("\nConvex Hull is :\n");
for(i=0;i<n;i++){
if(next[i]!=-1){
printf("{ %d , %d }\n",points[i].x,points[i].y);
}
}


}

int main(){

Point points[]={{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};

int n=sizeof(points)/sizeof(points[0]);

FindConvexHull(points,n);







return 0;
}
