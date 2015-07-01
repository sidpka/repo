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
}

int IsEmptyQueue(QNode* queue){
return queue->front==-1;
}
char* DeQueue(QNode* queue){
    char* data;
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

int main(){
printf("\nEnter the value of n : ");
int n;
scanf("%d",&n);
struct QUNode* queue=(struct QUNode*)malloc(sizeof(QUNode));
queue->front=-1;
queue->rear=-1;
queue->capacity=n;
queue->Array=(char**)malloc(sizeof(char*)*n);
int i;
for(i=0;i<n;i++){
queue->Array[i]=(char*)malloc(sizeof(char)*10);
}
EnQueue(queue,"1");
char* S1=(char*)malloc(sizeof(char)*10);
char* S2=(char*)malloc(sizeof(char)*10);;
char tmpZero[2]="0";
char tmpOne[2]="1";
while(n--){
S1=DeQueue(queue);
printf("\n%s",S1);
strcpy(S2,S1);
printf("\n\nS1 : %s  S2: %s",S1,S2);
strcat(S1,S2);

break;
}

return 0;
}
