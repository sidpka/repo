#include<stdio.h>
#include<conio.h>
#define row 5
#define col 4


void PrintDiagonally(int mat[row][col]){


int i=0;
int j=0;

int tmpI;
int tmpJ;
int targetI;
int targetJ;
//int rowEnd=0;
while(i<row || j<col){

tmpI=i;
tmpJ=j;

while(tmpI>=0 && tmpJ<col){
printf("%d  ",mat[tmpI][tmpJ]);
tmpI--;
tmpJ++;
}
printf("\n");

i++;
if(i>=row){
i=row-1;
j++;
}

if(j>=col){
break;
}
}


}

int main(){

int mat[row][col]={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}   };

PrintDiagonally(mat);






return 0;
}
