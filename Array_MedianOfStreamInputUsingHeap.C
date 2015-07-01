#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct HeapNode{

int capacity;
int count;
int type;
int* HArray;
};
typedef struct HeapNode HNode;

HNode* CreateHeap(int n,int type){

HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->count=0;
tmpNode->capacity=n;
tmpNode->type=type;
tmpNode->HArray=(int*)malloc(sizeof(int)*n);
return tmpNode;
}

void InsertHeap(HNode* heap,int data){

int i=heap->count;

while(i>0 && (heap->type==0?heap->HArray[(i-1)/2]>data : heap->HArray[(i-1)/2]<data)){
heap->HArray[i]=heap->HArray[(i-1)/2];
i=(i-1)/2;

}
heap->HArray[i]=data;
heap->count++;
}

int GetTop(HNode* heap){
return heap->HArray[0];
}

int Left(HNode* heap,int i){

int left=2*i+1;
if(left<heap->count){
return left;
}else{
return -1;
}
}



int Right(HNode* heap,int i){

int right=2*i+2;


if(right<heap->count){
return right;
}else{
return -1;
}



}



void PercolateDown(HNode* heap,int i){

int left=Left(heap,i);
int right=Right(heap,i);

int mM;

if(left!=-1 && (heap->type==0? heap->HArray[left]<heap->HArray[i] : heap->HArray[left]>heap->HArray[i])){
mM=left;
}else{
mM=i;
}

if(right!=-1 && (heap->type==0? heap->HArray[right]<heap->HArray[mM] : heap->HArray[right]>heap->HArray[mM])){
mM=right;
}

if(mM!=i){
int tmp=heap->HArray[i];
heap->HArray[i]=heap->HArray[mM];
heap->HArray[mM]=tmp;
PercolateDown(heap,mM);
}


}


int ExtractTop(HNode* heap){

int data=heap->HArray[0];
heap->HArray[0]=heap->HArray[heap->count-1];
heap->count--;
PercolateDown(heap,0);
return data;
}

int GetSignum(HNode* maxHeap,HNode* minHeap){
if(maxHeap->count==minHeap->count){
return 0;
}else if(maxHeap->count<minHeap->count){
return -1;
}else{
return 1;
}

}

int Average(int a,int b){
return (a+b)/2;
}

int FindMedian(int elm,int* median,HNode* minHeap,HNode* maxHeap){

int signum=GetSignum(maxHeap,minHeap);

switch(signum){

case 1:

if(elm<(*median)){
InsertHeap(minHeap,ExtractTop(maxHeap));
InsertHeap(maxHeap,elm);
}else{
InsertHeap(minHeap,elm);
}
(*median)=Average(GetTop(maxHeap),GetTop(minHeap));
//return (*median);
break;

case 0:

if(elm<(*median)){
//InsertHeap(minHeap,ExtractTop(maxHeap));
InsertHeap(maxHeap,elm);
(*median)=GetTop(maxHeap);
}else{
InsertHeap(minHeap,elm);
(*median)=GetTop(minHeap);
}
//(*median)=Average(GetTop(maxHeap),GetTop(minHeap));
//return (*median);
break;

case -1:

if(elm<(*median)){
//InsertHeap(minHeap,ExtractTop(maxHeap));
InsertHeap(maxHeap,elm);
}else{
    InsertHeap(maxHeap,ExtractTop(minHeap));
InsertHeap(minHeap,elm);
}
(*median)=Average(GetTop(maxHeap),GetTop(minHeap));
//return (*median);
break;
}
return (*median);
}

int main(){

int n;
printf("\nEnter the number of inputs : ");
scanf("%d",&n);
int arr[n];
int i;

HNode* heapMin=CreateHeap(n,0);
HNode* heapMax=CreateHeap(n,1);

int median;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&arr[i]);
median=FindMedian(arr[i],&median,heapMin,heapMax);
printf("\nMedian is : %d",median);
}

return 0;
}
