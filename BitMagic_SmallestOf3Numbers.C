#include<stdio.h>
#include<conio.h>

int Min(int a,int b){
return b+((a-b) &(a-b)>>31);
}

int FindSmallest(int a,int b,int c){

return Min(Min(a,b),c);

}

int FindSmallest2(int a,int b,int c){
int count=0;
while( a && b && c){
a--;
b--;
c--;
count++;
}
return count;
}

int main(){

int a=10;
int b=20;
int c=15;
printf("\nSmallest : %d",FindSmallest2(a,b,c));
//printf("\nSmallest : %d",FindSmallest(a,b,c));


return 0;
}
