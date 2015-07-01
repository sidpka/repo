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


void EnQueue(QNode* queue,int data){



if(queue->front==-1 && queue->rear==-1){
queue->Array[++queue->rear]=data;
queue->front++;
}

else if(queue->rear==queue->capacity-1){
printf("\nOverflow..");
return;
}

else{
queue->Array[++queue->rear]=data;

}

}

void Traverse(QNode* queue){
int i;
for(i=queue->front;i<=queue->rear;i++){
printf("%d\t",queue->Array[i]);
}
}

int DeQueue(QNode* queue){
if(queue->rear<queue->front){
printf("\nUnderflow..");
return -1;
}
else{
return queue->Array[queue->front++];
}
}

int main(){
QNode* queue=(QNode*)malloc(sizeof(QNode));
queue->front=-1;
queue->rear=-1;
queue->capacity=5;
queue->Array=(int*)malloc(sizeof(int)*queue->capacity);

int i;
int data;
for(i=0;i<queue->capacity;i++){
printf("\nEnter data : ");
scanf("%d",&data);
EnQueue(queue,data);
}

printf("\n%d elements inserted..",i);
getch();
printf("\nPress enter to trverse ...\n\n");
Traverse(queue);
getch();
printf("\nDequeue now ..");
getch();
while(1){
int result=DeQueue(queue);
if(result==-1){
break;
}
printf("\nDeuqueued : %d",result);
getch();
}




return 0;
}
