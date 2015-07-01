#include<stdio.h>
#include<conio.h>
#define row 5
#define col 7

void Rotate90(char arr[row][col]){

char tmp[col][row];



int i;
int j;





/*
printf("\nrow : %d col : %d\n",row,col);
*/

for(i=0;i<col;i++){
for(j=0;j<row;j++){
tmp[i][j]='\0';
}
}


/*
for(i=0;i<row;i++){
for(j=0;j<col;j++){
tmp[j][col-1-i]=arr[i][j];
printf("\n%c",tmp[j][col-1-i]);
}
}
*/


for(i=0;i<col;i++){
for(j=0;j<row;j++){
tmp[i][j]=arr[row-1-j][i];
}
}


for(i=0;i<col;i++){
for(j=0;j<row;j++){
printf("%c  ",tmp[i][j]);
}
printf("\n");
}
}

int main(){

char arr[row][col]={{'*','*','*','^','*','*','*'},
                {'*','*','*','|','*','*','*'},
                {'*','*','*','|','*','*','*'},
                {'*','*','*','|','*','*','*'},
                {'*','*','*','|','*','*','*'}
               };


int i;
int j;

for(i=0;i<row;i++){
for(j=0;j<col;j++){
printf("%c  ",arr[i][j]);
}
printf("\n");
}


printf("\nPress enter to rotate by 90 degree :\n\n");

getch();

Rotate90(arr);
return 0;
}
