#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define row 4
#define col 4


struct HeapNode{

int data;
int rowIndex;
int elmIndex;
};
typedef struct HeapNode HNode;

int Left(int i){

int left=2*i+1;
if(left<row){
return left;
}else{
return -1;
}
}

int Right(int i){

int right=2*i+2;
if(right<row){
return right;
}else{
return -1;
}

}

void Swap(HNode* a,HNode* b){

HNode tmp;
tmp.data=(*a).data;
tmp.rowIndex=(*a).rowIndex;
tmp.elmIndex=(*a).elmIndex;

(*a).data=(*b).data;
(*a).rowIndex=(*b).rowIndex;
(*a).elmIndex=(*b).elmIndex;

(*b).data=tmp.data;
(*b).rowIndex=tmp.rowIndex;
(*b).elmIndex=tmp.elmIndex;

}

void PercolateDown(HNode arr[row],int i){

int left=Left(i);
int right=Right(i);

int min;
//printf("\nHere in percolate");
if(left!=-1 && arr[left].data<arr[i].data){
min=left;
}else{
min=i;
}

if(right!=-1 && arr[right].data < arr[min].data){
min=right;
}

if(i!=min){
Swap(&arr[i],&arr[min]);
PercolateDown(arr,min);


}



}

void Heapify(HNode arr[row]){


int i=(row-1)/2;

while(i>0){
PercolateDown(arr,i);
i--;
}





}

HNode GetMin(HNode arr[row]){

return arr[0];
}

void ExtractMin(HNode arr[row]){
PercolateDown(arr,0);
}

void PrintSorted(int mat[row][col]){


HNode HArray[row];

int i;

for(i=0;i<row;i++){
HArray[i].data=mat[i][0];
HArray[i].rowIndex=i;
HArray[i].elmIndex=0;
}

Heapify(HArray);

//printf("%d  ",HArray[0].data);


for(i=0;i<row*col;i++){
HNode tmpNode=GetMin(HArray);
printf("%d  ",tmpNode.data);
if(tmpNode.elmIndex<col-1){
   // printf("\nHere");
HArray[0].data=mat[tmpNode.rowIndex][tmpNode.elmIndex+1];
HArray[0].elmIndex=tmpNode.elmIndex+1;
HArray[0].rowIndex=tmpNode.rowIndex;
//printf("\nHere");
}else{
    HArray[0].data=INT_MAX;
    HArray[0].elmIndex=tmpNode.elmIndex+1;
HArray[0].rowIndex=tmpNode.rowIndex;
}
//ExtractMin(HArray);
PercolateDown(HArray,0);
}


}

int main(){


int mat[row][col]={ {10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};

PrintSorted(mat);




return 0;
}
