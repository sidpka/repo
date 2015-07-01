#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct QUNode{
int front;
int rear;
int capacity;
char** Array;
};

typedef struct QUNode QNode;
int IsFullQueue(QNode* queue){
return (queue->rear+1)%queue->capacity==queue->front;
}
void EnQueue(QNode* queue,char* data){
if(IsFullQueue(queue)){
return;
}else{

queue->rear=(queue->rear+1)%queue->capacity;
queue->Array[queue->rear]=data;
if(queue->front==-1){
queue->front=queue->rear;
}
}
printf("\nEnqueued: %s\n",queue->Array[queue->rear]);
}
void Traverse(QNode* queue){
int i;
for(i=0;i<=queue->front;i++){


}

}
int IsEmptyQueue(QNode* queue){
return queue->front==-1;
}
char* DeQueue(QNode* queue){
    char* data;
    printf("\nDequque entering: front : %d\t elm : %s",queue->front,queue->Array[queue->front]);
if(IsEmptyQueue(queue)){
printf("\nUnderflow..\n");
}
else{

data=queue->Array[queue->front];
if(queue->front==queue->rear){
queue->front=-1;
queue->rear=-1;
}else{
queue->front=(queue->front +1)%(queue->capacity);
}
}
   printf("\nDequque leaving: front : %d",queue->front);
printf("\nDequeueing : %s\n\n",data);
return data;
}

int main(){
printf("\nEnter the value of n : ");
int n;
scanf("%d",&n);
struct QUNode* queue=(struct QUNode*)malloc(sizeof(QUNode));
queue->front=-1;
queue->rear=-1;
queue->capacity=10;
queue->Array=(char**)malloc(sizeof(char*)*10);
int i;
for(i=0;i<n;i++){
queue->Array[i]=(char*)malloc(sizeof(char)*10);
}
EnQueue(queue,"1");
char S1[20];

char S2[20];
char* tmpHolder=(char*)malloc(sizeof(char)*10);
char tmpZero[4]="0";
char tmpOne[4]="1";
while(n--){
tmpHolder=DeQueue(queue);
strcpy(S1,tmpHolder);
printf("\n%s",tmpHolder);
strcpy(S2,tmpHolder);
strcat(S1,tmpZero);
//printf("\nS1 is : %s",S1);
EnQueue(queue,S1);
strcat(S2,tmpOne);
//printf("\nS2 is : %s",S2);
EnQueue(queue,S2);


}

return 0;
}
