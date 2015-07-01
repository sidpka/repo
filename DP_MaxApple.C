#include<stdio.h>
#include<conio.h>

int max(int a,int b){
return a>b?a:b;
}

int PickMaxApples(int apples[3][3]){


int S[3][3];

int i;
int j;

for(i=0;i<3;i++){
for(j=0;j<3;j++){


if(i>0 && j>0){
S[i][j]=max(S[i-1][j],S[i][j-1])+apples[i][j];
}else if(i>0){
S[i][j]=S[i-1][j]+apples[i][j];
}else if(j>0){
S[i][j]=S[i][j-1]+apples[i][j];
}else{
S[i][j]=apples[i][j];
}



}
}

/*
for(i=0;i<3;i++){
for(j=0;j<3;j++){
printf("%d  ",S[i][j]);
}
printf("\n");
}

getch();
*/

return  S[2][2];


}

int main(){

int apples[3][3]={{1,2,5},{3,7,10},{9,2,12}};

printf("\nMax apple picked : %d",PickMaxApples(apples));





return 0;



}
