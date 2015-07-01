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

struct TSNode{
QNode* Q1;
QNode* Q2;
QNode* Q3;
};

typedef struct TSNode TNode;


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



int Cmp(const void* a,const void* b){

return (*(int*)a-*(int*)b);

}

int Compare(const void* a,const void* b){
return (*(int*)b-*(int*)a);
}

void FindIt(TNode* testRoot,int* Array,int size){

int i;
int sumAll=0;
for(i=0;i<size;i++){
    sumAll+=Array[i];

if(Array[i]%3==0){
EnQueue(testRoot->Q1,Array[i]);
}

else if(Array[i]%3==1){
EnQueue(testRoot->Q2,Array[i]);
}else{
EnQueue(testRoot->Q3,Array[i]);
}
}
/*testing

printf("\nTesting first queue..\n\n");
Traverse(testRoot->Q1);

printf("\nTesting first queue..\n\n");
Traverse(testRoot->Q2);

printf("\nTesting first queue..\n\n");
Traverse(testRoot->Q3);


end testing
*/
if(sumAll%3==1){

if(!IsEmptyQueue(testRoot->Q2)){
DeQueue(testRoot->Q2);
}

else if(!IsEmptyQueue(testRoot->Q3)){
DeQueue(testRoot->Q3);

if(!IsEmptyQueue(testRoot->Q3)){
DeQueue(testRoot->Q3);
}
else{
printf("\nNot possibe\n\n");
return;
}

}else{
printf("\nNot possibe\n\n");
return;
}

}



if(sumAll%3==2){

if(!IsEmptyQueue(testRoot->Q3)){
DeQueue(testRoot->Q3);
}
else if(!IsEmptyQueue(testRoot->Q2)){
DeQueue(testRoot->Q2);

if(!IsEmptyQueue(testRoot->Q2)){
DeQueue(testRoot->Q2);
}
else{
printf("\nNot possibe\n\n");
return;
}


}else{
printf("\nNot possibe\n\n");
return;
}

}


int* AuxArray=(int*)malloc(sizeof(int)*size);
int index=0;
while(!IsEmptyQueue(testRoot->Q1)){
AuxArray[index++]=DeQueue(testRoot->Q1);
}
while(!IsEmptyQueue(testRoot->Q2)){
AuxArray[index++]=DeQueue(testRoot->Q2);
}
while(!IsEmptyQueue(testRoot->Q3)){
AuxArray[index++]=DeQueue(testRoot->Q3);
}
qsort(AuxArray,index,sizeof(int),Compare);
printf("\n\nMax digit is : \n\n");
for(i=0;i<index;i++){
printf("%d",AuxArray[i]);
}

}


int main(){
int size;
printf("\nEnter size : ");
scanf("%d",&size);
TNode* testRoot=(TNode*)malloc(sizeof(TNode));
if(!testRoot){
printf("\nError\n\n");
}
testRoot->Q1=(QNode*)malloc(sizeof(QNode));
if(!testRoot->Q1){
printf("\nError");
}
testRoot->Q1->front=-1;
testRoot->Q1->rear=-1;
testRoot->Q1->capacity=size;
testRoot->Q1->Array=(int*)malloc(sizeof(int)*testRoot->Q1->capacity);
if(!testRoot->Q1->Array){
printf("\nError");
}
testRoot->Q2=(QNode*)malloc(sizeof(QNode));
if(!testRoot->Q2){
printf("\nError");
}
testRoot->Q2->front=-1;
testRoot->Q2->rear=-1;
testRoot->Q2->capacity=size;
testRoot->Q2->Array=(int*)malloc(sizeof(int)*testRoot->Q2->capacity);
if(!testRoot->Q2->Array){
printf("\nError");
}

testRoot->Q3=(QNode*)malloc(sizeof(QNode));
if(!testRoot->Q3){
printf("\nError");
}
testRoot->Q3->front=-1;
testRoot->Q3->rear=-1;
testRoot->Q3->capacity=size;
testRoot->Q3->Array=(int*)malloc(sizeof(int)*testRoot->Q3->capacity);
if(!testRoot->Q3->Array){
printf("\nError");
}

/*
CreateQueue(testRoot->Q1,size);
CreateQueue(testRoot->Q2,size);
CreateQueue(testRoot->Q3,size);
*/

int* Array=(int*)malloc(sizeof(int)*size);
if(!Array){
printf("\nError\n\n");
}
int i;
for(i=0;i<size;i++){
printf("\nEnter elm : ");
scanf("%d",&Array[i]);
}


printf("\n%d elements inserted..",i);
getch();

printf("\nSorting array");
qsort(Array,size,sizeof(int),Cmp);
printf("\nSorted array is : \n\n");
for(i=0;i<size;i++){
printf("%d  ",Array[i]);
}


getch();

printf("\nProceed to find max 3 mul \n");
getch();
FindIt(testRoot,Array,size);

return 0;
}
