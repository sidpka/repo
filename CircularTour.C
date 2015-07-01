#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct XNode{
int amount;
int distance;
};

typedef struct XNode Node;
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

for(i=queue->front;i<=queue->rear;i++){
printf("%d\t",queue->Array[i]);
}

}

}

int CheckAvailability(QNode* queue){

int sum=0;
int i;
if(queue->front>=queue->rear){
for(i=queue->front;i<queue->capacity;i++){
sum+=queue->Array[i];
}
for(i=queue->rear;i<queue->front;i++){
sum+=queue->Array[i];
}
}else{

for(i=queue->front;i<=queue->rear;i++){
sum+=queue->Array[i];
}

}
return sum;

}

int main(){
printf("\nEnter the no of petrol pumps : ");
int n;
scanf("%d",&n);

Node** Array=(Node**)malloc(sizeof(Node*)*n);
int i;
for(i=0;i<n;i++){
Array[i]=(Node*)malloc(sizeof(Node));
}

for(i=0;i<n;i++){
printf("\nEnter details : ");
scanf("%d %d",&Array[i]->amount,&Array[i]->distance);
}
int tmpData;

QNode* queue=(QNode*)malloc(sizeof(QNode));
queue->capacity=n;
queue->front=-1;
queue->rear=-1;
queue->Array=(int*)malloc(sizeof(int)*n);

int startIndex=0;
int endIndex=1;
tmpData=Array[startIndex]->amount-Array[startIndex]->distance;
while(endIndex!=startIndex || tmpData<0){

    while(tmpData<0 && startIndex!=endIndex){

    tmpData-=Array[startIndex]->amount-Array[startIndex]->distance;
    startIndex=(startIndex+1)%n;

    if(startIndex==0){
    printf("\nNot found any");
    return 0;
    }


    }

    tmpData+=Array[endIndex]->amount-Array[endIndex]->distance;

endIndex=(endIndex+1)%n;


}

printf("\nStarting Petrol Pump : %d",startIndex+1);










return 0;
}
