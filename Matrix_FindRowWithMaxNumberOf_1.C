#include<stdio.h>
#include<conio.h>
#define row 4
#define col 4


int BS(int* arr,int low,int high){

if(arr[low]==1){
return low;
}

if(arr[high]==0){
return  col;
}

int mid=(low+high)/2;

if(low+1<=mid && arr[mid]==1 && arr[mid-1]==0){
return mid;
}else if(mid+1<=high && arr[mid]==0 && arr[mid+1]==1){
return mid+1;
}else if(arr[mid]==1){
return BS(arr,low,mid-1);
}else{
return BS(arr,mid+1,high);
}



}

int FindRowWithMax_1(int mat[row][col]){

int index=col;

int tmpIndex;


int i;
index=BS(mat[0],0,col-1);
int rowIndex=0;
if(index==0){
return rowIndex;
}
//printf("\n%d",tmpIndex);
//getch();
for(i=1;i<row;i++){
if(mat[i][index-1]==1){
tmpIndex=BS(mat[i],0,col-1);
rowIndex=i;
if(tmpIndex==0){
return rowIndex;
}
index=tmpIndex;
}


}

return rowIndex;
}

int main(){

int mat[row][col]={{0,1,1,1},
                   {0,0,1,1},
                   {1,1,1,1},
                   {0,0,0,0}};

int rowWithMax_1=FindRowWithMax_1(mat);

printf("\nRow with max 1 : %d",rowWithMax_1);



return 0;
}
