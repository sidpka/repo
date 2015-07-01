#include<stdio.h>
#include<conio.h>




void PrintMagicSquare(int n){

int magic[n][n];

int i;
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
magic[i][j]=0;
}
}

i=n/2;
j=n-1;

int val=1;

while(val<=n*n){

if(i==-1 && j==n){
i=0;
j=n-2;
}else{

if(i<0){
i=n-1;
}

if(j==n){
j=0;
}

}

if(magic[i][j]){
i++;
j-=2;
continue;

}else{
magic[i][j]=val;
val++;

}
i--;
j++;


}



for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d  ",magic[i][j]);
}
printf("\n");
}


}


int main(){

//Magic square is a matrix in which all rows all columns all diagonals add up to same value callled magic number
//magic number M =n*(n^2 +1)/2

int n=7;

PrintMagicSquare(n);




return 0;
}
