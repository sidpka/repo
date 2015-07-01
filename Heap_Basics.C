#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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

int max;

if(left !=-1 && heap->Array[i]<heap->Array[left]){
max=left;
}else{
max=i;
}

if(right !=-1 && heap->Array[max]<heap->Array[right]){
max=right;
}

if(max!=i){
int tmpData=heap->Array[max];
heap->Array[max]=heap->Array[i];
heap->Array[i]=tmpData;
PercolateDown(heap,max);
}

}

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
while(i>0 && data> heap->Array[(i-1)/2]){
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



int main(){

printf("\nLets create heap\n");
getch();
Heap* heap=CreateHeap(1);

printf("\nHeap created : count : %d  capacity : %d\n",heap->count,heap->capacity);
getch();
int choice;
int data;
do{
printf("\nEnter your choice : ");
printf("\n1.Insert into Heap  ");
printf("\n2.Get Max");
printf("\n3.Delete Max");
printf("\n4. Exit\n\n");
scanf("%d",&choice);


switch(choice){

case 1:
printf("\nEnter data to insert : ");
scanf("%d",&data);
Insert(heap,data);
break;
case 2:

data=GetMax(heap);
printf("\nMax element in heap is :  %d\n",data);
break;

case 3:
data=DeleteMax(heap);
if(data==-1){
printf("\n\nheap empty");
continue;
}
printf("\nDeleted %d from heap \n",data);
}
}while(choice!=4);

return 0;
}
