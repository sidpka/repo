#include<stdio.h>
#include<conio.h>


struct Points{
int x;
int y;

};
typedef struct Points Point;

int FindIfOverlap(Point l1,Point r1,Point l2,Point r2){

if(l1.x>r2.x || l2.x>r1.x){
return 0;
}

if(l1.y<r2.y || l2.y<r1.y){
return 0;
}

return 1;
}

int main(){
Point l1={0,10};
Point r1={10,0};
Point l2={5,5};
Point r2={15,0};

FindIfOverlap(l1,r1,l2,r2)==1?printf("\nYes"):printf("\nNo");



return 0;
}
