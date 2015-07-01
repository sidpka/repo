#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct STNode{
int capacity;
int top;
int* Array;
};
typedef struct STNode SNode;

struct QUNode{
SNode* S1;
SNode* S2;
};
typedef struct QUNode QNode;

void CreateStack(SNode* stack,int size){
stack=(SNode*)malloc(sizeof(SNode));
stack->Array=(int*)malloc(sizeof(int)*5);
stack->top=-1;
stack->capacity=size;
if(!stack){
printf("\nEroor");
}
}

void Push(SNode* stack,int data){
if(stack->top==stack->capacity-1){
return;
}
stack->Array[++stack->top]=data;
}

void EnQueue(QNode* queue,int data){
Push(queue->S1,data);
}

int IsEmptyStack(SNode* stack){

return stack->top==-1;
}

int Pop(SNode* stack){

return stack->Array[stack->top--];
}

int DeQueue(QNode* queue){
if(IsEmptyStack(queue->S2)){
if(IsEmptyStack(queue->S1)){
return -1;
}else{
while(!IsEmptyStack(queue->S1)){
Push(queue->S2,Pop(queue->S1));
}
return Pop(queue->S2);
}
}
else{
return Pop(queue->S2);
}
}

int main(){
int size=5;
QNode* queue=(QNode*)malloc(sizeof(QNode));
CreateStack(queue->S1,size);
queue->S2=(SNode*)malloc(sizeof(SNode));
queue->S2->Array=(int*)malloc(sizeof(int)*size);
queue->S2->capacity=size;
queue->S2->top=-1;

//CreateStack(queue->S2,size);
//printf("\nTop S1: %d Top S2: %d",queue->S1->top,queue->S2->top);
int i,data;

for(i=0;i<size;i++){
printf("\nEnter data : ");
scanf("%d",&data);
EnQueue(queue,data);
}
printf("\nEnqueued\n");
getch();
printf("\nNow Deuquing\n\n");

//printf("\nTop S1: %d Top S2: %d",queue->S1->top,queue->S2->top);
while(1){
int result=DeQueue(queue);
if(result==-1){
printf("\nEnd \n");
break;
}
printf("%d  ",result);

}
return 0;
}
