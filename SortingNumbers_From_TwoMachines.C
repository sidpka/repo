#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct LL{
int data;
struct LL* next;
};
typedef struct LL LNode;

struct Bunch{
int count;
LNode** BArray;
};
typedef struct Bunch BNode;

struct Heap{
int capacity;
int count;
LNode** HArray;
};
typedef struct Heap HNode;

HNode* CreateHeap(int n){
HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->count=0;
tmpNode->capacity=n;
tmpNode->HArray=(LNode**)malloc(sizeof(LNode*)*n);
int i;
for(i=0;i<n;i++){
tmpNode->HArray[i]=NULL;
}
return tmpNode;
}



BNode* CreateBunch(int n){
BNode* newNode=(BNode*)malloc(sizeof(BNode));
newNode->count=n;
newNode->BArray=(LNode**)malloc(sizeof(LNode*)*n);
int i;
for(i=0;i<n;i++){
newNode->BArray[i]=NULL;
}
return newNode;
}

LNode* InsertLL(LNode* head,int data){
    LNode* tmpNode=(LNode*)malloc(sizeof(LNode));
    tmpNode->data=data;
if(!head){
tmpNode->next=NULL;
return tmpNode;
}else{
tmpNode->next=head;
return tmpNode;
}
}

void TraverseLL(LNode* head){
LNode* tmpNode=head;
while(tmpNode){
printf("%d  ",tmpNode->data);
tmpNode=tmpNode->next;
}
}

int Left(HNode* heapHead,int i){
int left=2*i+1;
if(left<heapHead->count){
return left;
}else{
return -1;
}
}

int Right(HNode* heapHead,int i){
int right=2*i+2;
if(right<heapHead->count){
return right;
}else{
return -1;
}
}

void InsertHeap(HNode* heapHead,LNode* node){
int i=heapHead->count;
while(i>0 && node->data< heapHead->HArray[(i-1)/2]->data){
heapHead->HArray[i]=heapHead->HArray[(i-1)/2];
i=(i-1)/2;
}
heapHead->HArray[i]=node;
heapHead->count++;
}

void PercolateDown(HNode* heapHead,int i){

int left=Left(heapHead,i);
int right=Right(heapHead,i);
int min;

if(left!=-1 && heapHead->HArray[left]!=NULL && heapHead->HArray[left]->data < heapHead->HArray[i]->data){
min=left;
}else{
min=i;
}

if(right!=-1 && heapHead->HArray[right]!=NULL && heapHead->HArray[right]->data < heapHead->HArray[min]->data){
min=right;
}

if(min!=i){
LNode* tmpNode=heapHead->HArray[min];
heapHead->HArray[min]=heapHead->HArray[i];
heapHead->HArray[i]=tmpNode;
PercolateDown(heapHead,min);
}
}

LNode* PopHeap(HNode* heapHead){

LNode* tmpNode=heapHead->HArray[0];
if(tmpNode==NULL){
return NULL;
}
heapHead->HArray[0]=heapHead->HArray[0]->next;
LNode* transferNode=heapHead->HArray[heapHead->count-1];
heapHead->HArray[heapHead->count-1]=heapHead->HArray[0];
heapHead->HArray[0]=transferNode;
if(heapHead->HArray[heapHead->count-1]==NULL){
heapHead->count--;
}
if(heapHead->count>0){
PercolateDown(heapHead,0);
}
return tmpNode;
}


void Sort(HNode* heapHead){


LNode* tmpNode;
while(1){
tmpNode=PopHeap(heapHead);
if(tmpNode==NULL){
return;
}
printf("%d  ",tmpNode->data);

}

}

int main(){
int machineCount;
printf("\nEnter the number of machines : ");
scanf("%d",&machineCount);
int n;
int i;
int data;
BNode* bunchHead=CreateBunch(machineCount);
HNode* heapHead=CreateHeap(machineCount);
printf("\nGet numbers from different machines in sorted order : \n\n");

for(i=0;i<machineCount;i++){
printf("\nEnter the number of elms in Machine[%d] : ",i);
scanf("%d",&n);
while(n--){
printf("\nEnter data for M[%d] : ",i);
scanf("%d",&data);
bunchHead->BArray[i]=InsertLL(bunchHead->BArray[i],data);
}
}

printf("\nTraverseing all the machines : ");
for(i=0;i<machineCount;i++){
printf("\nM[%d]  :  ",i);
TraverseLL(bunchHead->BArray[i]);
}
getch();
printf("\nPress enter to poulate heap : \n");
getch();

for(i=0;i<machineCount;i++){
InsertHeap(heapHead,bunchHead->BArray[i]);
}
printf("\nHeap updated \n");
getch();
printf("\nSorted numbers : \n");
getch();
Sort(heapHead);
getch();
}
