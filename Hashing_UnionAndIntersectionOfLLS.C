#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#define LoadFactor 3

struct LLNode{
int key;
int data;
LLNode* next;

};

typedef struct LLNode LNode;

struct BlockNode{
int bCount;
LNode* next;
};

typedef struct BlockNode BNode;

struct HashNode{
int size;
int count;
BNode** HashTable;

};

typedef struct HashNode HNode;



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

HNode* CreateHash(int size){

HNode* newNode=(HNode*)malloc(sizeof(HNode));
if(!newNode){
printf("\nMemory error");
}

newNode->count=0;
int tmpSize=(int)(size/LoadFactor);

// if the size will be prime hash function will distribute the data uniformally because it gives unique remainder
newNode->size=GetNextPrime(tmpSize);
//printf("\nSize is : %d",newNode->size);

newNode->HashTable=(BNode**)malloc(sizeof(BNode*)*newNode->size);
if(!newNode->HashTable){
printf("\nMemory error");
}
int i=0;
for(i=0;i<newNode->size;i++){
newNode->HashTable[i]=(BNode*)malloc(sizeof(BNode));
if(!newNode->HashTable[i]){
printf("\nMemory error");
}
newNode->HashTable[i]->bCount=0;
newNode->HashTable[i]->next=NULL;
}


return newNode;
}

int Hash(HNode* hashRoot,int data){
return data%hashRoot->size;
}

int Search(HNode* hashRoot,int data){
int index=Hash(hashRoot,data);
LNode* tmpNode=hashRoot->HashTable[index]->next;

while(tmpNode){
if(tmpNode->data==data){
return 1;
}
tmpNode=tmpNode->next;
}

return 0;
}


void Rehash(HNode* hashMain){

int oldSize=hashMain->size;
BNode** oldTable=hashMain->HashTable;

LNode* tmpNode,*tmpHolder;

hashMain->size *=2;

hashMain->HashTable=(BNode**)malloc(sizeof(BNode*)*hashMain->size);
int i,index;
for(i=0;i<hashMain->size;i++){
hashMain->HashTable[i]=(BNode*)malloc(sizeof(BNode));
hashMain->HashTable[i]->bCount=0;
hashMain->HashTable[i]->next=NULL;
}

for(i=0;i<oldSize;i++){

for(tmpNode=oldTable[i]->next; tmpNode; ){
index=Hash(hashMain,tmpNode->data);
tmpHolder=tmpNode;
tmpNode=tmpNode->next;
tmpHolder->key=index;
tmpHolder->next=hashMain->HashTable[index]->next;
hashMain->HashTable[index]->next=tmpHolder;
}
}

free(oldTable);
}

void Insert(HNode* hashRoot,int data){
if(Search(hashRoot,data)){
return;
}
int index=Hash(hashRoot,data);
//LNode* tmpNode=hashRoot->HashTable[index]->next;
LNode* newNode=(LNode*)malloc(sizeof(LNode));
if(!newNode){
printf("\nMemory error\n");
}
newNode->data=data;
newNode->key=index;
newNode->next=hashRoot->HashTable[index]->next;
hashRoot->HashTable[index]->next=newNode;
hashRoot->HashTable[index]->bCount++;
hashRoot->count++;
if(hashRoot->HashTable[index]->bCount ==LoadFactor){
Rehash(hashRoot);
}

}

void DeleteHash(HNode* hashRoot,int data){

if(!Search(hashRoot,data)){
return;
}

int index=Hash(hashRoot,data);

LNode* tmpNode,*prev;

for(tmpNode=hashRoot->HashTable[index]->next,prev=NULL;tmpNode;prev=tmpNode,tmpNode=tmpNode->next){
if(tmpNode->data==data){
if(prev!=NULL){
prev->next=tmpNode->next;
}else{
hashRoot->HashTable[index]->next=tmpNode->next;
}
hashRoot->HashTable[index]->bCount--;
hashRoot->count--;
free(tmpNode);

}

}

}

void Traverse(HNode* hashRoot){
int i;
LNode* tmpNode;
for(i=0;i<hashRoot->size;i++){
printf("\n [%d] ",i);
for(tmpNode=hashRoot->HashTable[i]->next;tmpNode;tmpNode=tmpNode->next){
printf("%d  -->>  ",tmpNode->data);
}
}
}


LNode* InsertLL(LNode* head,int data){

LNode* newNode=(LNode*)malloc(sizeof(LNode));
newNode->data=data;
if(!head){
newNode->next=NULL;
}else{
newNode->next=(head);
}
return newNode;
}

void TraverseLL(LNode* head){
LNode* tmpNode=head;
while(tmpNode){
printf("%d   --->>  ",tmpNode->data);
tmpNode=tmpNode->next;
}

}

int main(){
    /*
printf("\nPrime numb:\n\n");

printf("\n\n");
getch();
*/
//it populates array for prime numbers

PopulateP();

//
printf("\nEnter the number of records : ");
int n,data;
scanf("%d",&n);
HNode* hash=CreateHash(n);

printf("\nSize %d count %d",hash->size,hash->count);

int L_One_Count;
int L_Two_Count;

printf("\nEnter the number of elements in 1st list : \n\n");
scanf("%d",&L_One_Count);

int i;

LNode* head1=NULL;
LNode* head2=NULL;

printf("\nEnter the elements of 1st list \n");
for(i=0;i<L_One_Count;i++){
scanf("%d",&data);
head1=InsertLL(head1,data);
}

printf("\nTraverse list 1\n");
getch();
TraverseLL(head1);
getch();

printf("\nEnter the number of elements in 1st list : \n\n");
scanf("%d",&L_Two_Count);





printf("\nEnter the elements of 1st list \n");
for(i=0;i<L_Two_Count;i++){
scanf("%d",&data);
head2=InsertLL(head2,data);
}

printf("\nTraverse list 1\n");
getch();
TraverseLL(head2);
getch();

printf("\nPress enter to find union of first and second list...\n\n");

LNode* UnionList=NULL;

LNode* tmpNode=head1;
while(tmpNode){
Insert(hash,tmpNode->data);
UnionList=InsertLL(UnionList,tmpNode->data);
tmpNode=tmpNode->next;
}

tmpNode=head2;
LNode* IntersectionList=NULL;
while(tmpNode){
if(!Search(hash,tmpNode->data)){
UnionList=InsertLL(UnionList,tmpNode->data);
}
else{
IntersectionList=InsertLL(IntersectionList,tmpNode->data);
}
tmpNode=tmpNode->next;
}


printf("\nUnion Created \n");
getch();
printf("\nPress enter to see union \n");
getch();
TraverseLL(UnionList);
getch();
printf("\nPress enter to see intersection\n");
getch();
TraverseLL(IntersectionList);
getch();
return 0;
}
