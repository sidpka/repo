#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct HiNode{

int capacity;
int count;
int* Array;

};
typedef struct HiNode HNode;

int GetLeft(HNode* heap,int i){
int left=2*i+1;
if(left>=heap->count){
return -1;
}else{
return left;
}
}

int GetRight(HNode* heap,int i){
int right=2*i+2;
if(right>=heap->count){
return -1;
}else{
return right;
}
}

int GetMax(HNode* heap){
    return heap->Array[0];
}

void ResizeHeap(HNode* heap){

heap->capacity*=2;
heap->Array=(int*)realloc(heap->Array,heap->capacity);

}

void InsertIntoHeap(HNode* heap,int data){
if(heap->count==heap->capacity){
ResizeHeap(heap);
}

int i=heap->count;

while(i>0 && heap->Array[(i-1)/2]<data){
heap->Array[i]=heap->Array[(i-1)/2];
i=(i-1)/2;
}
heap->Array[i]=data;
heap->count++;
}

void PercolateDown(HNode* heap,int i){

int max;
int left,right;
left=GetLeft(heap,i);
right=GetRight(heap,i);

if(left!=-1 && heap->Array[left]>heap->Array[i]){
max=left;
}else{
max=i;
}

if(right!=-1 && heap->Array[right]>heap->Array[max]){
max=right;
}

if(max!=i){
int tmpData=heap->Array[max];
heap->Array[max]=heap->Array[i];
heap->Array[i]=tmpData;
PercolateDown(heap,max);
}
}

void DeleteFromHeap(HNode* heap,int i){
heap->Array[i]=heap->Array[heap->count-1];
heap->count--;
PercolateDown(heap,i);
}

void Traverse(HNode* heap){
int i;
for(i=0;i<heap->count;i++){
printf(" || %d || ",heap->Array[i]);
}

}

int FindIndexInHeap(HNode* heap,int data,int k){
//printf("\nhere for %d",data);
int i;
for(i=0;i<k;i++){
if(heap->Array[i]==data){
break;
}
}
return i;
}

void FindMaxInWindow(HNode* heap,int* List,int k,int n){

int i;
int count=0;

for(i=0;i<k;i++){
InsertIntoHeap(heap,List[i]);
}
printf("\n[ %d ] Window's Max : %d",1+count++,GetMax(heap));

//printf("\nTraversing\n\n\n");
//Traverse(heap);
int index;
int toDeleteIndex=0;
for(i=k;i<n;i++){
index=FindIndexInHeap(heap,List[toDeleteIndex],k);
//printf("\nIndex to delete is : %d\n",index);
toDeleteIndex++;
DeleteFromHeap(heap,index);
InsertIntoHeap(heap,List[i]);
printf("\n[ %d ] Window's Max : %d",1+count++,GetMax(heap));
}
}

int main(){
int n,k;
printf("\nEnter the no of elements : ");
scanf("%d",&n);
HNode* heap=(HNode*)malloc(sizeof(HNode));
heap->count=0;
printf("\nEnter the size of sliding window : ");
scanf("%d",&k);
heap->capacity=k;
heap->Array=(int*)malloc(sizeof(int)*heap->capacity);

int i;
int data;
int* List=(int*)malloc(sizeof(int)*n);
printf("\nEnter the elements of the array : \n");
for(i=0;i<n;i++){
scanf("%d",&List[i]);
}

printf("\n%d items added to list ",n);
getch();
printf("\nPress enter to see the see max element in every slide : ");
getch();
FindMaxInWindow(heap,List,k,n);

printf("\n");

return 0;
}
