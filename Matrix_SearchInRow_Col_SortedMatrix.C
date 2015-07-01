#include<stdio.h>
#include<conio.h>
#define n 4

void Find(int mat[n][n],int x){

int i=0;
int j=n-1;

while(i<n && j>=0){

if(mat[i][j]==x){

    printf("\nElm found at : (%d,%d)",i,j);
break;
}else if(mat[i][j]<x){
i++;
}else{
j--;
}





}



}

int main(){

int mat[4][4]={
                    {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},


               };



Find(mat,29);
return 0;
}
