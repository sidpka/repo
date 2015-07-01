#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct DQueue{
int front;
int rear;
int capacity;
int* DArray;
};
typedef struct DQueue DNode;

DNode* CreateDQueue(int k){
DNode* tmpNode=(DNode*)malloc(sizeof(DNode));
tmpNode->front=-1;
tmpNode->rear=-1;
tmpNode->capacity=k;
tmpNode->DArray=(int*)malloc(sizeof(int)*k);
return tmpNode;
}

void PushBack(DNode* queue,int data){
queue->rear=(queue->rear+1)%queue->capacity;
queue->DArray[queue->rear]=data;
if(queue->front==-1){
queue->front=queue->rear;
}
}

int IsEmptyQueue(DNode* queue){
return queue->front==-1;
}

int PopFront(DNode* queue){
int data=queue->DArray[queue->front];
if(queue->front==queue->rear){
queue->front=-1;
queue->rear=-1;
}else{
queue->front=(queue->front+1)%queue->capacity;
}
return data;
}

int PopBack(DNode* queue){
int data;

data=queue->DArray[queue->rear];
if(queue->front==queue->rear){
queue->front=-1;
queue->rear=-1;
}else{
    if(queue->rear==0){
    queue->rear=queue->capacity-1;
    }else{
    queue->rear=(queue->rear-1)%queue->capacity;
    }

}
return data;
}

int GetQBack(DNode* queue){
return queue->DArray[queue->rear];
}

int GetQFront(DNode* queue){
return queue->DArray[queue->front];
}

void GetMaxOfSubArrays(int* arr,int n,int k){

DNode* queue=CreateDQueue(k);
//printf("\nFront : %d  rear : %d size : %d",queue->front,queue->rear,queue->capacity);

int i;
int data;
for(i=0;i<k;i++){

while(!IsEmptyQueue(queue) && arr[GetQBack(queue)]<=arr[i]){
data=PopBack(queue);
//printf("\nPopped : %d",data);
}

PushBack(queue,i);
//printf("\nRear : %d",queue->rear);
}

for(i=k;i<n;i++){
printf("%d  ",arr[GetQFront(queue)]);

while(!IsEmptyQueue(queue) && GetQFront(queue)<=i-k){
PopFront(queue);
}
//printf("\nRear : %d of i : %d and front : %d\n",queue->rear,i,queue->front);


while(!IsEmptyQueue(queue) && arr[GetQBack(queue)]<=arr[i]){
data=PopBack(queue);
//printf("\nPopped : %d",data);
}
//printf("\nFor i : %d  front : %d and data : %d\n",i,queue->front,queue->DArray[queue->front]);
PushBack(queue,i);
}

printf("%d  ",arr[GetQFront(queue)]);
}

int main(){

int arr[]={1, 2, 3, 1, 4, 5, 2, 3, 6};

int n=sizeof(arr)/sizeof(arr[0]);
int k=2;
GetMaxOfSubArrays(arr,n,k);
//printf("\nPress enter to see max of subarrays : \n\n");

return 0;
}
