#include<stdio.h>
#include<conio.h>
#define ROW 4
#define COL 4

int FindIndex(int* arr,int low,int high){
//printf("\n%d",arr[low]);

if(high==low){
if(arr[low]==1){
return low;
}else{
return ROW;
}
}
if(low+1==high){
if(arr[low]==1){
return low;
}else if(arr[high]==1){
return high;
}else{
return ROW;
}
}

int mid=(low+high)/2;

if(arr[mid]==1 && arr[mid-1]==0){
return mid;
}else if(arr[mid]==1 && arr[mid-1]==1){
return FindIndex(arr,low,mid-1);
}

if(arr[mid]==0 && arr[mid+1]==1){
return mid+1;
}else if(arr[mid]==0 && arr[mid+1]==0){
return FindIndex(arr,mid+1,high);
}

}

int FindRow(int arr[ROW][COL]){

int min=ROW;

int i;
int tmp;
int maxIndex;
for(i=0;i<ROW;i++){
    if(arr[i][min-1]==1){
tmp=FindIndex(arr[i],0,COL-1);
    }
if(tmp<min){
min=tmp;
maxIndex=i;
}
if(min==0){
break;
}
}

return maxIndex;
}



int FindRow2(int arr[ROW][COL]){


int i;
int tmp;
int maxIndex;
int min;

min=FindIndex(arr[0],0,COL-1);
maxIndex=1;
for(i=1;i<ROW;i++){
  printf("\nHere");
if(arr[i][min-1]==1 && min>0){
while(arr[i][min-1]==1 && min>0){
min--;
}
maxIndex=i;
}

}

return maxIndex;
}

int main(){

int arr[ROW][COL]={{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};

//O(ROW Log(COL))
//int rowNumber=FindRow(arr);

//O(ROW+COL)
int rowNumber=FindRow2(arr);
printf("\nRow number with maximum number of 1 : %d",rowNumber);







return 0;
}
