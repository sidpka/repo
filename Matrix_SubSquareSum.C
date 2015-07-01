#include<stdio.h>
#include<conio.h>
#define n 5

void PrintSumOfAllSubsquareWithSumK(int mat[n][n],int K){

int i;
int j;

int strip[n-K+1][n];

int sum;


for(j=0;j<n;j++){

sum=0;

for(i=0;i<K;i++){
sum+=mat[i][j];
}
strip[0][j]=sum;

for(i=1;i<n-K+1;i++){
sum+=(mat[i+K-1][j] - mat[i-1][j]);
strip[i][j]=sum;
}



}

/*
printf("\nSub\n");

for(i=0;i<n-K+1;i++){
for(j=0;j<n;j++){
printf("%d  ",strip[i][j]);
}
printf("\n");
}

printf("\nSub\n");

*/

printf("\nSum of all subarray with size : %d \n\n",K);


for(i=0;i<n-K+1;i++){
sum=0;
for(j=0;j<K;j++){

sum+=strip[i][j];

}
printf("%d  ",sum);

for(j=1;j<n-K+1;j++){
sum+=(strip[i][j+K-1] - strip[i][j-1]);
printf("%d  ",sum);
}
printf("\n");
}






}

int main(){

int mat[n][n]={{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4},{5,5,5,5,5}};
int K =3;
PrintSumOfAllSubsquareWithSumK(mat,K);










return 0;
}
