#include<stdio.h>
#include<conio.h>
#define n 4

void PrintSpiral(int mat[n][n],int R,int C){

int i;
int j;
int k;


i=0;
j=0;


while(i<R && j<C){

//first row
for(k=j;k<C;k++){
printf("%d  ",mat[i][k]);
}
i++;

for(k=i;k<R;k++){
printf("%d  ",mat[k][C-1]);
}
C--;

if(i<R){
for(k=C-1;k>=j;k--){
printf("%d  ",mat[R-1][k]);
}
R--;
}
if(j<C){
for(k=R-1;k>=i;k--){
printf("%d  ",mat[k][j]);
}
j++;



}

}

}

int main(){

int mat[n][n]={{1,2,3,4},
              {5,6,7,8},
              {9,10,11,12},
              {13,14,15,16},

};


PrintSpiral(mat,4,4);



return 0;
}
