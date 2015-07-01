#include<stdio.h>
#include<conio.h>


void PrintMatrix(int m,int n){



int i;
int j;
int k;

int elm=1;

int arr[m][n];
int row=m;
int col=n;
i=0;
j=0;
while(i<row && j<col){


for(k=j;k<col;k++){
arr[i][k]=elm;
}
i++;

for(k=i;k<row;k++){
arr[k][col-1]=elm;
}
col--;

if(i<row){
for(k=col-1;k>=j;k--){
arr[row-1][k]=elm;
}
row--;
}

if(j<col){
for(k=row-1;k>=i;k--){
arr[k][j]=elm;
}
j++;
}

elm=(elm==1)?0:1;


}


for(i=0;i<m;i++){

for(j=0;j<n;j++){
printf("%d  ",arr[i][j]);
}
printf("\n");

}



}



int main(){
printf("\nMatrix With Alternating O and X's rectangle\n");
//PrintMatrix(3,3);
//PrintMatrix(4,5);
//PrintMatrix(5,5);
PrintMatrix(6,7);

return 0;
}
