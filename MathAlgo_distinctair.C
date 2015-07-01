#include<stdio.h>
#include<conio.h>
#include<math.h>


void PrintDistinctPairs(int n){

int x;
int y;
int res=0;
for(x=0;x*x<n;x++){
for(y=0;x*x+y*y<n;y++){
res++;
}

}

printf("\n res : %d",res);
}

void PrintDistinctPairs2(int n){

int x=0;
int y=0;

for(y=0;y*y<n;y++);
//printf("%d",y);

int res=0;

while(y!=0){
res+=y;
x++;

while(y!=0 && x*x+(y-1)*(y-1)>=n){
y--;
}
}



printf("\n%d",res);
}

int main(){

int n=5;
//PrintDistinctPairs(n);
PrintDistinctPairs2(n);


return 0;
}
