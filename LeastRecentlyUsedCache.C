#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct DLL{
int pageNo;
struct DLL* next,*prev;
};
typedef struct DLL DNode;

struct Queue{
int count;
int capacity;
DNode* front;
DNode* rear;
};
typedef struct Queue QNode;

struct HashNode{
int capacity;
DNode** HArray;
};
typedef struct HashNode HNode;

QNode* CreateQueue(int n){
QNode* tmpNode=(QNode*)malloc(sizeof(QNode));
tmpNode->count=0;
tmpNode->capacity=n;
tmpNode->front=NULL;
tmpNode->rear=NULL;
return tmpNode;
}




int Hash(HNode* node,int key){
return key%node->capacity;
}

int Search(HNode* hashRoot,int key){
int index=Hash(hashRoot,key);

DNode* tmpNode=hashRoot->HArray[index];
while(tmpNode){
if(tmpNode->pageNo==key){
return 1;
}
}

return 0;
}

int prime[1000];

void PopulateP(){
int i,j;
prime[0]=1;
prime[1]=1;
prime[2]=0;
for(i=2;i<10;i++){
    if(!prime[i]){
for(j=2;j<100;j++){
prime[i*j]++;
}
    }
}
/*
for(i=0;i<100;i++){
if(!prime[i]){
printf("%d  ",i);
}
}
*/

}


int GetNextPrime(int size){
int i;
for(i=size;i<1000;i++){
if(prime[i]==0){
break;
}
}
return i;
}


HNode* CreateHash(int n){
HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->capacity=GetNextPrime(n);
tmpNode->HArray=(DNode**)malloc(sizeof(DNode*)*tmpNode->capacity);
int i;
for(i=0;i<n;i++){
tmpNode->HArray[i]=NULL;
}
return tmpNode;
}

void InsertHash(HNode* hashRoot,DNode* tmpNode){
int index=Hash(hashRoot,tmpNode->pageNo);
hashRoot->HArray[index]=tmpNode;
}

void FreeHash(HNode* hashRoot,DNode* tmpNode){
int index=Hash(hashRoot,tmpNode->pageNo);
hashRoot->HArray[index]=NULL;
}

/*
void Insert(QNode* queue,HNode* hashRoot,int pgNo){

if(queue->count<queue->capacity){
DNode* newNode=(DNode*)malloc(sizeof(DNode));
newNode->prev=NULL;
newNode->pageNo=pgNo;
if(queue->front==NULL){
    newNode->next=NULL;
    queue->front=newNode;
    queue->rear=newNode;
    InsertHash(hashRoot,newNode);
    return;
}else{
newNode->next=queue->front;
queue->front->prev=newNode;
queue->front=newNode;
InsertHash(hashRoot,newNode);
return;
}
}else{
DNode* tmpNode=queue->rear;
tmpNode->prev->next=NULL;
FreeHash(hashRoot,tmpNode);
free(tmpNode);
DNode* newNode=(DNode*)malloc(sizeof(DNode));
newNode->prev=NULL;
newNode->pageNo=pgNo;
newNode->next=queue->front;
queue->front->prev=newNode;
InsertHash(hashRoot,newNode);
return;
}

}
*/

DNode* InsertQueue(QNode* queue,int pgNo){

DNode* newNode=(DNode*)malloc(sizeof(DNode));
newNode->prev=NULL;
newNode->pageNo=pgNo;
if(queue->front==NULL){
    newNode->next=NULL;
    queue->front=newNode;
    queue->rear=newNode;
}else{
newNode->next=queue->front;
queue->front->prev=newNode;
queue->front=newNode;
}

queue->count++;
return queue->front;
}

void Insert(QNode* queue,HNode* hashRoot,int pgNo){
    if(queue->count<queue->capacity){
    DNode* tmpNode=InsertQueue(queue,pgNo);
    InsertHash(hashRoot,tmpNode);
    }else{
    DNode* tmpNode=queue->rear;
    tmpNode->prev->next=NULL;
    FreeHash(hashRoot,tmpNode);
    free(tmpNode);
    queue->count--;
    DNode* newNode=InsertQueue(queue,pgNo);
    InsertHash(hashRoot,newNode);
    }

}
void Traverse(QNode* queue){
DNode* tmpNode=queue->front;
while(tmpNode){
printf("%d  ",tmpNode->pageNo);
tmpNode=tmpNode->next;
}
}

void Search(QNode* queue,HNode* hashRoot,int pgNo){
if(queue->count==0){
printf("\nEmpty Cache");
return;
}
int index=Hash(hashRoot,pgNo);
DNode* tmpNode=hashRoot->HArray[index];

if(!tmpNode){
printf("\nNot found in cache ");
return;
}else{
if(tmpNode!=queue->front){
tmpNode->prev->next=tmpNode->next;
if(tmpNode->next){
tmpNode->next->prev=tmpNode->prev;
}

tmpNode->prev=NULL;
tmpNode->next=queue->front;
queue->front->prev=tmpNode;
queue->front=tmpNode;
}
printf("\nFound");
}

}

int main(){
int n;
printf("\nEnter the number of page numbers to be maintained in cache : ");
scanf("%d",&n);
QNode* queue=CreateQueue(n);
HNode* hashRoot=CreateHash(n);

int i;

int ch=1;
int data;
while(ch){

printf("\nEnter your choice : ");
printf("\n1.Insert");
printf("\n2.Search");
printf("\n3.Traverse");
printf("\n4.Exit\n");
scanf("%d",&ch);

switch(ch){

case 1:
printf("\nEnter page number : ");
scanf("%d",&data);
Insert(queue,hashRoot,data);
break;

case 2:
printf("\nENter the page number you want to search : ");
scanf("%d",&data);
Search(queue,hashRoot,data);
break;

case 3:
Traverse(queue);

int i;
printf("\n\n");
for(i=0;i<hashRoot->capacity;i++){
if(hashRoot->HArray[i]){
printf("%d  ",hashRoot->HArray[i]->pageNo);
}
}



break;

case 0:
break;
}

}




return 0;
}
