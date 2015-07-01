#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Heap{
int *HArray;
int count;
int capacity;
};
typedef struct Heap HNode;

HNode* CreateHeap(int n){
HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->HArray=(int*)malloc(sizeof(int)*n);
tmpNode->count=0;
tmpNode->capacity=n;
return tmpNode;
}

void Insert(HNode* heapHead,int data){
int i=heapHead->count;

while(i>0 && heapHead->HArray[(i-1)/2]<data){
heapHead->HArray[i]=heapHead->HArray[(i-1)/2];
i=(i-1)/2;
}

heapHead->HArray[i]=data;
heapHead->count++;

}

int Left(HNode* heapHead,int i){
int left=2*i+1;
if(left>=heapHead->count){
return -1;
}else{
return left;
}
}

int Right(HNode* heapHead,int i){
int right=2*i+2;
if(right>=heapHead->count){
return -1;
}else{
return right;
}
}

void PercolateDown(HNode* heapHead,int i){

int left=Left(heapHead,i);
int right=Right(heapHead,i);

int max;

if(left!=-1 && heapHead->HArray[left]>heapHead->HArray[i]){
max=left;
}else{
max=i;
}

if(right!=-1 && heapHead->HArray[right]>heapHead->HArray[max]){
max=right;
}


if(max!=i){
int tmp=heapHead->HArray[i];
heapHead->HArray[i]=heapHead->HArray[max];
heapHead->HArray[max]=tmp;
PercolateDown(heapHead,max);
}

}

int Pop(HNode* heapHead){
int tmp=heapHead->HArray[0];
heapHead->HArray[0]=heapHead->HArray[heapHead->count-1];
//This below line helps in sorted output
heapHead->HArray[heapHead->count-1]=tmp;
heapHead->count--;
PercolateDown(heapHead,0);
return tmp;
}

int main(){
int arr[]={2,1,4,3,5,0,8};
int n=sizeof(arr)/sizeof(arr[0]);
int K=3;
HNode* heapHead=CreateHeap(n);
int i;
for(i=0;i<n;i++){
Insert(heapHead,arr[i]);
}
//If unsorted
printf("\n%d Largest elms :\n\n",K);
int j;
for(i=0;i<K;i++){
printf("%d  ",Pop(heapHead));
/*
for(j=0;j<heapHead->count;j++){
printf("%d  ",heapHead->HArray[j]);
}
*/
}

//Sorted
printf("\n");
for(i=n-K;i<n;i++){
printf("%d  ",heapHead->HArray[i]);
}
return 0;
}
