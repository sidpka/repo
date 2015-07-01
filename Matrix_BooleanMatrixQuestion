#include<stdio.h>
#include<conio.h>
#define R 3
#define C 4

void ModifyMatrix(int mat[R][C]){
int rowBuffer[R]={0};
int colBuffer[C]={0};

int i;
int j;

for(i=0;i<R;i++){
for(j=0;j<C;j++){
if(mat[i][j]){
rowBuffer[i]=1;
colBuffer[j]=1;
}
}
}

for(i=0;i<R;i++){
for(j=0;j<C;j++){
if(mat[i][j]==0 && (rowBuffer[i] || colBuffer[j]) ){
mat[i][j]=1;
}
}
}




}


void ModifyMatrix2(int mat[R][C]){


int rFlag=0;
int cFlag=0;

int i;
int j;

for(i=0;i<C;i++){
if(mat[0][i]){
rFlag=1;
}
}

for(i=0;i<R;i++){
if(mat[i][0]){
cFlag=1;
}
}

for(i=1;i<R;i++){
for(j=1;j<C;j++){
if(mat[i][j]){
mat[0][j]=1;
mat[i][0]=1;
}
}
}


for(i=1;i<R;i++){
for(j=1;j<C;j++){

if(mat[0][j] || mat[i][0]){
mat[i][j]=1;
}



}
}


if(rFlag==1){
for(i=0;i<C;i++){
mat[0][i]=1;
}
}

if(cFlag==1){
for(i=0;i<R;i++){
mat[i][0]=1;
}
}

}


int main(){


int mat[R][C]={{1,0,0,1},{0,0,1,0},{0,0,0,0} };
//ModifyMatrix(mat);


//Space Optimized

ModifyMatrix2(mat);
printf("\nPress enter to modify the matrix such that a[i][j] is 1 then all elments of that row n col are modified to 1 \n\n");
getch();
int i;
int j;
for(i=0;i<R;i++){
for(j=0;j<C;j++){
printf("%d  ",mat[i][j]);
}
printf("\n");
}




return 0;
}
