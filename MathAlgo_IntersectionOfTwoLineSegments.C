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

int max(int a,int b){

return a>b?a:b;
}

int min(int a,int b){

return a<b?a:b;
}


int IsOnLine(Point p,Point q,Point r){

if( (q.x<= max(p.x,r.x) && q.x>= min(p.x,r.x) ) && (q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y)) ){

return 1;
}

return 0;
}

int FindIfIntersect(Point p1,Point q1,Point p2,Point q2){

int ornt1=FindOrient(p1,q1,p2);
int ornt2=FindOrient(p1,q1,q2);
int ornt3=FindOrient(p2,q2,p1);
int ornt4=FindOrient(p2,q2,q1);

if( (ornt1!=ornt2) && (ornt3!=ornt4) ){
return 1;
}

if(ornt1==0 && IsOnLine(p1,p2,q1)){
return 1;
}

if(ornt2==0 && IsOnLine(p1,q2,q1)){
return 1;
}

if(ornt3==0 && IsOnLine(p2,p1,q2)){
return 1;
}

if(ornt4==0 && IsOnLine(p2,q1,q2)){
return 1;
}

return 0;

}


int main(){

Point p1,q1,p2,q2;

/*
p1={1,1};
q1={10,1};
p2={1,2};
q2={10,2};
*/

p1 = {10, 0};
q1 = {0, 10};
p2 = {0, 0};
q2 = {10, 10};

int result=FindIfIntersect(p1,q1,p2,q2);

result?printf("\nYes"):printf("\nNo");





return 0;
}
