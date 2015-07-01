#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
#define n 4


struct HeapNode{
//int* HArray;
int arrayIndex;
int elmIndex;
int data;
};

struct Heap{
struct HeapNode** HArray;
int count;
int capacity;
};

typedef struct Heap HNode;



HNode* CreateHeap(int size){

HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->count=0;
tmpNode->capacity=size;

int i;

tmpNode->HArray=(struct HeapNode**)malloc(sizeof(struct HeapNode*)*size);

for(i=0;i<tmpNode->capacity;i++){
tmpNode->HArray[i]=(struct HeapNode*)malloc(sizeof(struct HeapNode));
}

return tmpNode;

}





void PrintSortedArray(int* arr,int size){

int i;

for(i=0;i<size;i++){
printf("%d  ",arr[i]);
}


}


void InsertHeap(HNode* heapRoot,int elm,int arrayIndex,int elmIndex){

int i=heapRoot->count;

while(i>0 && elm <heapRoot->HArray[(i-1)/2]->data){
heapRoot->HArray[i]->data=heapRoot->HArray[(i-1)/2]->data;
heapRoot->HArray[i]->arrayIndex=heapRoot->HArray[(i-1)/2]->arrayIndex;
heapRoot->HArray[i]->elmIndex=heapRoot->HArray[(i-1)/2]->elmIndex;
//heapRoot->HArray[i]=heapRoot->HArray[(i-1)/2];
i=(i-1)/2;
}
heapRoot->HArray[i]->data=elm;
heapRoot->HArray[i]->arrayIndex=arrayIndex;
heapRoot->HArray[i]->elmIndex=elmIndex;
heapRoot->count++;
}

int Left(HNode* heapRoot,int i){

int left=2*i+1;

if(left<heapRoot->count){
return left;
}else{
return -1;
}

}

int Right(HNode* heapRoot,int i){

int right=2*i+2;

if(right<heapRoot->count){
return right;
}else{
return -1;
}

}

void PercolateDown(HNode* heapRoot,int i){

int left=Left(heapRoot,i);
int right=Right(heapRoot,i);
int min;
//printf("\nHere");
if(left!=-1 && heapRoot->HArray[left]->data< heapRoot->HArray[i]->data){
min=left;
}else{
min=i;
}

if(right!=-1 && heapRoot->HArray[right]->data<heapRoot->HArray[min]->data){
min=right;
}
//struct HeapNode* tmpNode=(struct HeapNode*)malloc(sizeof(struct HeapNode));
if(min!=i){
/*
tmpNode->data=heapRoot->HArray[i]->data;
tmpNode->arrayIndex=heapRoot->HArray[i]->arrayIndex;
tmpNode->elmIndex=heapRoot->HArray[i]->elmIndex;
heapRoot->HArray[i]->data=heapRoot->HArray[min]->data;
heapRoot->HArray[i]->arrayIndex=heapRoot->HArray[min]->arrayIndex;
heapRoot->HArray[i]->elmIndex=heapRoot->HArray[min]->elmIndex;
heapRoot->HArray[min]->data=tmpNode->data;
heapRoot->HArray[min]->arrayIndex=tmpNode->arrayIndex;
heapRoot->HArray[min]->elmIndex=tmpNode->elmIndex;
*/
int data=heapRoot->HArray[i]->data;
int arrayIndex=heapRoot->HArray[i]->arrayIndex;
int elmIndex=heapRoot->HArray[i]->elmIndex;

heapRoot->HArray[i]->data=heapRoot->HArray[min]->data;
heapRoot->HArray[i]->arrayIndex=heapRoot->HArray[min]->arrayIndex;
heapRoot->HArray[i]->elmIndex=heapRoot->HArray[min]->elmIndex;


heapRoot->HArray[min]->data=data;
heapRoot->HArray[min]->arrayIndex=arrayIndex;
heapRoot->HArray[min]->elmIndex=elmIndex;

PercolateDown(heapRoot,min);
}

}

struct HeapNode* ExtractMin(HNode* heapRoot){
struct HeapNode* tmpNode=(struct HeapNode*)malloc(sizeof(struct HeapNode));

tmpNode->data=heapRoot->HArray[0]->data;
tmpNode->arrayIndex=heapRoot->HArray[0]->arrayIndex;
tmpNode->elmIndex=heapRoot->HArray[0]->elmIndex;

//struct HeapNode* tmpNode=heapRoot->HArray[0];

if(heapRoot->count>1){
heapRoot->HArray[0]->data=heapRoot->HArray[heapRoot->count-1]->data;
heapRoot->HArray[0]->arrayIndex=heapRoot->HArray[heapRoot->count-1]->arrayIndex;
heapRoot->HArray[0]->elmIndex=heapRoot->HArray[heapRoot->count-1]->elmIndex;
heapRoot->count--;
PercolateDown(heapRoot,0);
}else{
heapRoot->count--;
}

return tmpNode;

}



int* GetSortedArray(int arr[][n],int k){
int size=n*k;
int* output=(int*)malloc(sizeof(int)*size);

HNode* heapRoot=CreateHeap(k);
//printf("\nCapacity : %d",heapRoot->capacity);

int i;

for(i=0;i<k;i++){
InsertHeap(heapRoot,arr[i][0],i,0);
}
/*
struct HeapNode* tmpNode=ExtractMin(heapRoot);
printf("\nData : %d  arrayIndex : %d  elm Index : %d",tmpNode->data,tmpNode->arrayIndex,tmpNode->elmIndex);
tmpNode=ExtractMin(heapRoot);
printf("\nData : %d  arrayIndex : %d  elm Index : %d",tmpNode->data,tmpNode->arrayIndex,tmpNode->elmIndex);
InsertHeap(heapRoot,arr[0][1],0,1);
tmpNode=ExtractMin(heapRoot);
printf("\nData : %d  arrayIndex : %d  elm Index : %d",tmpNode->data,tmpNode->arrayIndex,tmpNode->elmIndex);
*/

int index=0;
struct HeapNode* tmpNode;
int arrayIndex;
int elmIndex;
while(heapRoot->count>0){
tmpNode=ExtractMin(heapRoot);
//printf("\n%d ",tmpNode->data);
output[index++]=tmpNode->data;
arrayIndex=tmpNode->arrayIndex;
elmIndex=tmpNode->elmIndex;
if(elmIndex<n-1){
InsertHeap(heapRoot,arr[arrayIndex][elmIndex+1],arrayIndex,elmIndex+1);
}
}
/*
while(heapRoot->count){
output[index++]=ExtractMin(heapRoot)->data;
}*/
return output;
}

int main(){

int arr[][n]={{2,6,12,34},
              {1,9,20,1000},
              {23,34,90,2000},

              };


int k=sizeof(arr)/sizeof(arr[0]);

int* output=GetSortedArray(arr,k);
PrintSortedArray(output,n*k);


return 0;
}
