#include<stdio.h>
#include<conio.h>



int FindIfSolvable(int arr[3][3]){

int invCount=0;

int i;
int j;

int * ar=(int*)arr;

for(i=0;i<8;i++){
for(j=i+1;j<9;j++){
if(ar[i] && ar[j]  && (ar[i]>ar[j]) ){

invCount++;
}
}
}






//printf("\nInv count : %d",invCount);

return !(invCount&1);
}

int main(){

int arr[3][3]={ {1,8,2},{0,4,3},{7,6,5} };

int result=FindIfSolvable(arr);
result==1?printf("\nSolvable"):printf("\nNot solvable");






return 0;
}
