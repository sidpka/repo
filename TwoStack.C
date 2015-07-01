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

struct STNode{
QNode* Q1;
QNode* Q2;
};
typedef struct STNode SNode;

int IsEmptyQueue(QNode* queue){

return queue->front==-1;

}

int IsFullQueue(QNode* queue){

return (queue->rear+1)%queue->capacity==queue->front;

}

int QueueSize(QNode* queue){

if(queue->rear>=queue->front){
return (queue->rear- queue->front +1);
}else{
return (queue->capacity-queue->front+queue->rear+1);
}

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

void Push(SNode* stack,int data){
if(IsEmptyQueue(stack->Q2)){
EnQueue(stack->Q1,data);
}else{
EnQueue(stack->Q2,data);
}
}
int Pop(SNode* stack){
int size,i;
if(!IsEmptyQueue(stack->Q1)){
size=QueueSize(stack->Q1);
i=0;
while(i<size-1){
    i++;
EnQueue(stack->Q2,DeQueue(stack->Q1));

}
return DeQueue(stack->Q1);
}else if(!IsEmptyQueue(stack->Q2)){
size=QueueSize(stack->Q2);
i=0;
while(i<size-1){
    i++;
EnQueue(stack->Q1,DeQueue(stack->Q2));

}
return DeQueue(stack->Q2);
}


return -1;

}

int main(){
    SNode* stack=(SNode*)malloc(sizeof(SNode));
    stack->Q1=(QNode*)malloc(sizeof(QNode));


stack->Q1->front=-1;
stack->Q1->rear=-1;
stack->Q1->capacity=5;
stack->Q1->Array=(int*)malloc(sizeof(int)*5);

stack->Q2=(QNode*)malloc(sizeof(QNode));


stack->Q2->front=-1;
stack->Q2->rear=-1;
stack->Q2->capacity=5;
stack->Q2->Array=(int*)malloc(sizeof(int)*5);

int i;
int data;
for(i=0;i<5;i++){
printf("\nEnter data : ");
scanf("%d",&data);
Push(stack,data);
}

printf("\n%d elements inserted..",i);
getch();
printf("\mPopping now ..\n\n");
int tmpData;
while(1){
   tmpData=Pop(stack);
   if(tmpData==-1){
   printf("\nEnd");
   break;
   }
printf("%d  ",tmpData);
}

return 0;
}
