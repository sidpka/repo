#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct QueueNode{

int front;
int rear;
int capacity;
int* array;
};
typedef struct QueueNode QNode;

QNode* CreateQueue(int n){

QNode* tmpNode=(QNode*)malloc(sizeof(QNode));
tmpNode->capacity=n;
tmpNode->front=-1;
tmpNode->rear=-1;
tmpNode->array=(int*)malloc(sizeof(int)*n);

return tmpNode;
}

void EnQueue(QNode* queue,int data){

queue->rear=(queue->rear+1)%queue->capacity;

if(queue->front==-1){
queue->front=queue->rear;
}

queue->array[queue->rear]=data;

}

int DeQueue(QNode* queue){

int data=queue->array[queue->front];

if(queue->rear==queue->front){
queue->front=-1;
queue->rear=-1;
}else{

queue->front=(queue->front+1)%queue->capacity;

}


return data;
}

int IsQueueEmpty(QNode* queue){

return queue->front==-1;
}


int cmp(const void* a,const void* b){

return *(int*)a-*(int*)b;

}

int cmpD(const void* a,const void* b){

return *(int*)b-*(int*)a;

}

int FindLargestMultipleOf3(int arr[],int n){

QNode* q0=CreateQueue(n);
QNode* q1=CreateQueue(n);
QNode* q2=CreateQueue(n);

int sum=0;

int i;
qsort(arr,n,sizeof(int),cmp);

/*
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
*/

for(i=0;i<n;i++){
sum+=arr[i];
if(arr[i]%3==0){
EnQueue(q0,arr[i]);
}else if(arr[i]%3==1){
EnQueue(q1,arr[i]);
}else if(arr[i]%3==2){
EnQueue(q2,arr[i]);
}

}

if(sum%3==1){

if(!IsQueueEmpty(q1)){
DeQueue(q1);
}else{

if(!IsQueueEmpty(q2)){
DeQueue(q2);
}else{
return 0;
}

if(!IsQueueEmpty(q2)){
DeQueue(q2);
}else{
return 0;
}


}

}else if(sum%3==2){

if(!IsQueueEmpty(q2)){
DeQueue(q2);
}else{

if(!IsQueueEmpty(q1)){
DeQueue(q1);
}else{
return 0;
}

if(!IsQueueEmpty(q1)){
DeQueue(q1);
}else{
return 0;
}


}

}

int index=0;

while(!IsQueueEmpty(q0)){
arr[index++]=DeQueue(q0);
}

while(!IsQueueEmpty(q1)){
arr[index++]=DeQueue(q1);
}

while(!IsQueueEmpty(q2)){
arr[index++]=DeQueue(q2);
}

qsort(arr,index,sizeof(int),cmpD);

printf("\nLargest multiple of 3 is :  ");
for(i=0;i<index;i++){
printf("%d",arr[i]);
}

return 1;
}


int main(){

int arr[]={8, 1, 7, 6, 0};
int n=sizeof(arr)/sizeof(arr[0]);
int result=FindLargestMultipleOf3(arr,n);
if(!result){
printf("\nNot possible");
}


return 0;
}
