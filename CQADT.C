#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct QueueNode{
int front;
int rear;
int capacity;
int* Array;
};
typedef struct QueueNode QNode;


int IsEmptyQueue(QNode* queue){

return queue->front==-1;

}

int IsFullQueue(QNode* queue){

return (queue->rear+1)%queue->capacity==queue->front;

}

int QueueSize(QNode* queue){

return (queue->capacity -queue->front+ queue->rear +1)%queue->capacity;

}
void ResizeQueue(QNode* queue){
    int size=queue->capacity;
    queue->capacity*=2;
queue->Array=(int*)realloc(queue->Array,queue->capacity);
if(!queue->Array){
printf("\nEroor");
return;
}
if(queue->front>queue->rear){
int i;
for(i=0;i<queue->front;i++){
queue->Array[i+size]=queue->Array[i];
}
queue->rear=queue->rear+size;
}
}
void EnQueue(QNode* queue,int data){
if(IsFullQueue(queue)){
ResizeQueue(queue);
}else{

queue->rear=(queue->rear+1)%queue->capacity;
queue->Array[queue->rear]=data;
if(queue->front==-1){
queue->front=queue->rear;
}
}
}

void Traverse(QNode* queue){
int i;
if(queue->front>=queue->rear){
for(i=queue->front;i<queue->capacity;i++){
printf("%d\t",queue->Array[i]);
}
for(i=queue->rear;i<queue->front;i++){
printf("%d\t",queue->Array[i]);
}
}else{
    printf("\nQueue rear : %d\n",queue->rear);
for(i=queue->front;i<=queue->rear;i++){
printf("%d\t",queue->Array[i]);
}

}

}

int DeQueue(QNode* queue){
    int data=-1;
if(IsEmptyQueue(queue)){
printf("\nUnderflow..\n");

}
else{
data=queue->Array[queue->front];
if(queue->front==queue->rear){
queue->front=queue->rear=-1;
}else{

queue->front=(queue->front +1)%queue->capacity;

}
}
return data;
}

void DeleteQueue(QNode* queue){

if(queue->Array){
free(queue->Array);
}
free(queue);

}



void Reverse(QNode* queue){
    if(IsEmptyQueue(queue)){
    return;
    }
int tmpData=DeQueue(queue);
Reverse(queue);
EnQueue(queue,tmpData);
}

int main(){
QNode* queue=(QNode*)malloc(sizeof(QNode));
queue->front=-1;
queue->rear=-1;
queue->capacity=5;
queue->Array=(int*)malloc(sizeof(int)*queue->capacity);

int i;
int data;
for(i=0;i<5;i++){
printf("\nEnter data : ");
scanf("%d",&data);
EnQueue(queue,data);
}

printf("\n%d elements inserted..",i);
getch();
printf("\nPress enter to trverse ...\n\n");
Traverse(queue);
getch();
printf("\nPress enter to reverse queue..\n");
Reverse(queue);
Traverse(queue);
getch();

return 0;
}
