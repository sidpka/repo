#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#define LoadFactor 4

//here we will use binary search tree instead of linked list to do chaining


struct TreeNode{
int key;
int data;
TreeNode* left,*right;

};

typedef struct TreeNode TNode;

struct BlockNode{
int bCount;
TNode* next;
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


int BstSearch(TNode* root,int data){
if(!root){
return 0;
}
if(root->data==data){
return 1;
}
else if(root->data < data){
return BstSearch(root->right,data);
}
else{
return BstSearch(root->left,data);
}
}

int Search(HNode* hashRoot,int data){
int index=Hash(hashRoot,data);
TNode* tmpNode=hashRoot->HashTable[index]->next;
return BstSearch(tmpNode,data);
}


/*

void Rehash(HNode* hashMain){

int oldSize=hashMain->size;
BNode** oldTable=hashMain->HashTable;

TNode* tmpNode,*tmpHolder;

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
*/
TNode* BstInsert(TNode* root,TNode* newNode){
if(!root){
root=newNode;
return root;
}

if(root->data< newNode->data){
root->right=BstInsert(root->right,newNode);
}

if(root->data > newNode->data){
root->left=BstInsert(root->left,newNode);
}

return root;

}


void Insert(HNode* hashRoot,int data){
if(Search(hashRoot,data)){
return;
}
int index=Hash(hashRoot,data);
//LNode* tmpNode=hashRoot->HashTable[index]->next;
TNode* newNode=(TNode*)malloc(sizeof(TNode));
if(!newNode){
printf("\nMemory error\n");
}
newNode->data=data;
newNode->key=index;
newNode->left=NULL;
newNode->right=NULL;
hashRoot->HashTable[index]->next= BstInsert(hashRoot->HashTable[index]->next,newNode);
hashRoot->HashTable[index]->bCount++;
hashRoot->count++;
if(hashRoot->HashTable[index]->bCount ==LoadFactor){
//Rehash(hashRoot);
}

}
/*
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

*/

void BstTraversal(TNode* root){
if(!root){
    return;
}
BstTraversal(root->left);
printf(" %d  ==> ",root->data);
BstTraversal(root->right);
}

void Traverse(HNode* hashRoot){
int i;
TNode* tmpNode;
for(i=0;i<hashRoot->size;i++){
printf("\n [%d] ",i);
tmpNode=hashRoot->HashTable[i]->next;
BstTraversal(tmpNode);

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
int ch;
while(1){
printf("\n1.Insert data :  ");
printf("\n2.Search data :  ");
printf("\n3.Delete data :    ");
printf("\n4.Traverse");
printf("\n5.Exit\n ");
scanf("%d",&ch);

switch(ch){

case 1:
printf("\nEnter data : ");
scanf("%d",&data);
Insert(hash,data);
break;
case 2:
printf("\nEnter data : ");
scanf("%d",&data);
data=Search(hash,data);
if(data){
printf("\nFound");
}else{
printf("\nNot found");
}
break;
case 3:
printf("\nEnter data : ");
scanf("%d",&data);
//DeleteHash(hash,data);
break;
case 4:
Traverse(hash);
break;
case 5:
return 0;


}
}

return 0;
}
