#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
It implements minimum heap
ignore the name of functions which says max
inner functionality is such that it implements min tree
*/
struct HeapNode{

int* Array;
int count;
int capacity;
};

typedef struct HeapNode Heap;

int GetParent(Heap* heap,int i){
if(i<=0 || i>=heap->count){
return -1;
}
else{
return (i-1)/2;
}
}


int GetLeftChild(Heap* heap,int i){
    int left=2*i+1;
if(i<0 || left>=heap->count){
return -1;
}else{
return left;
}
}
int GetRightChild(Heap* heap,int i){
    int right=2*i+2;
if(i<0 || right>=heap->count){
return -1;
}else{
return right;
}
}

void PercolateDown(Heap* heap,int i){
int left=GetLeftChild(heap,i);
int right=GetRightChild(heap,i);

int min;

if(left !=-1 && heap->Array[i]>heap->Array[left]){
min=left;
}else{
min=i;
}

if(right !=-1 && heap->Array[min]>heap->Array[right]){
min=right;
}

if(min!=i){
int tmpData=heap->Array[min];
heap->Array[min]=heap->Array[i];
heap->Array[i]=tmpData;
PercolateDown(heap,min);
}

}
//it functions as delete min
int DeleteMax(Heap* heap){
if(heap->count>0){
int tmpData=heap->Array[0];
heap->Array[0]=heap->Array[heap->count-1];
heap->count--;
PercolateDown(heap,0);
return tmpData;
}else{
return -1;
}
}

int GetMax(Heap* heap){
if(heap->count>0){
return heap->Array[0];
}else{
return -1;
}
}

void PercolateUp(Heap* heap,int data){
int i=heap->count;
while(i>0 && data< heap->Array[(i-1)/2]){
heap->Array[i]=heap->Array[(i-1)/2];
i=(i-1)/2;
}
heap->Array[i]=data;
}

void ResizeHeap(Heap* heap){

int *Array=heap->Array;
//heap->capacity*=2;
heap->Array=(int*)malloc(sizeof(int)*2*heap->capacity);
if(!heap->Array){
printf("\nMemory error\n");
}
int i;
for(i=0;i<heap->capacity;i++){
heap->Array[i]=Array[i];
}

heap->capacity*=2;
free(Array);
}


void Insert(Heap* heap,int data){


if(heap->count==heap->capacity){
ResizeHeap(heap);
}
PercolateUp(heap,data);
heap->count++;
}

Heap* CreateHeap(int size){

Heap* heap=(Heap*)malloc(sizeof(Heap));
if(!heap){
printf("\nMemory Error\n");
}
heap->count=0;
heap->capacity=size;
heap->Array=(int*)malloc(sizeof(int)*heap->capacity);
if(!heap->Array){
printf("\nMemory Eroor\n");
}
return heap;
}

void BuildHeap(Heap* heap,int* Array,int n){

if(!heap){
return;
}

while(heap->capacity<n){
ResizeHeap(heap);
}

int i;
for(i=0;i<n;i++){
heap->Array[i]=Array[i];
}
heap->count=n;
for(i=(n-1)/2;i>=0;i--){
PercolateDown(heap,i);
}

}

void HeapSort(Heap* heap){
if(!heap){
return;
}
int n=heap->count;
int i;
int tmp;
printf("\n");
for(i=(n-1);i>0;i--){
tmp=heap->Array[0];
//printf("%d  ",tmp);
heap->Array[0]=heap->Array[heap->count-1];
heap->Array[heap->count-1]=tmp;
heap->count--;
PercolateDown(heap,0);
}
heap->count=n;
/*
for(i=0;i<n;i++){
printf("%d  ",heap->Array[i]);
}
*/
}

void GetMinK(Heap* heap,int* Array,int n,int k){

int i,tmpData;
for(i=k;i<n;i++){
    tmpData=GetMax(heap);
    if(tmpData>Array[i]){
    heap->Array[0]=Array[i];
    PercolateDown(heap,0);
    }
}


}


void SortAll(Heap* heap,int* Array,int n,int k){
if(!heap){
return;
}

int i;
int j=0;
for(i=k+1;i<n;i++){
Array[j++]=DeleteMax(heap);
Insert(heap,Array[i]);
}

while(GetMax(heap)!=-1){
Array[j++]=DeleteMax(heap);
}


}


int main(){

printf("\nLets create heap\n");
getch();
Heap* heap=CreateHeap(1);

int n;
printf("\nEnter the number of elements you want to create array with : ");
scanf("%d",&n);
int* Array=(int*)malloc(sizeof(int)*n);
int i;
printf("\nEnter elements of array\n");
for(i=0;i<n;i++){
scanf("%d",&Array[i]);
}
printf("\nEnter the value of k : ");
int k;
scanf("%d",&k);
BuildHeap(heap,Array,k+1);
printf("\nPress enter to get sort elements\n");
getch();
SortAll(heap,Array,n,k);
printf("\nSorted\n\n");
//In place sorting in Array itself

for(i=0;i<n;i++){
printf("%d  ",Array[i]);
}
getch();
return 0;
}
