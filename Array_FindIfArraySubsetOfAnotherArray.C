#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define LoadFactor 2


struct LinkNode{
int count;
int data;
struct LinkNode* next;
};
typedef struct LinkNode LNode;

struct BlockNode{
int bCount;
LNode* next;
};
typedef struct BlockNode BNode;



struct HashNode{
int capacity;
int count;
BNode** HArray;
};
typedef struct HashNode HNode;

HNode* CreateHash(int n){

HNode* tmpNode=(HNode*)malloc(sizeof(HNode));
tmpNode->count=0;
tmpNode->capacity=n/LoadFactor ;
tmpNode->HArray=(BNode**)malloc(sizeof(BNode*)*tmpNode->capacity);

int i;
for(i=0;i<tmpNode->capacity;i++){
    tmpNode->HArray[i]=(BNode*)malloc(sizeof(BNode));
tmpNode->HArray[i]->bCount=0;
tmpNode->HArray[i]->next=NULL;
}


return tmpNode;
}


int Hash(HNode* hashNode,int elm){
return elm%hashNode->capacity;
}

int Search(HNode* hashNode,int elm){
int index=Hash(hashNode,elm);
LNode* tmpNode=hashNode->HArray[index]->next;
while(tmpNode){
if(tmpNode->data==elm){
return 1;
}
tmpNode=tmpNode->next;
}
return 0;

}

void IncreaseCount(HNode* hashNode,int elm){

int index=Hash(hashNode,elm);

LNode* tmpNode=hashNode->HArray[index]->next;

while(tmpNode){
if(tmpNode->data==elm){
tmpNode->count++;
}
tmpNode=tmpNode->next;
}


}

void InsertHash(HNode* hashNode,int elm){
if(Search(hashNode,elm)){
IncreaseCount(hashNode,elm);
return;
}

int index=Hash(hashNode,elm);

LNode* tmpNode=(LNode*)malloc(sizeof(LNode));
tmpNode->count=1;
tmpNode->data=elm;
tmpNode->next=hashNode->HArray[index]->next;
hashNode->HArray[index]->next=tmpNode;

}

void RemoveHash(HNode* hashNode,int elm){

int index=Hash(hashNode,elm);
LNode* tmpNode=hashNode->HArray[index]->next;
LNode* prev=NULL;

while(tmpNode){
if(tmpNode->data==elm){
if(tmpNode->count>1){
tmpNode->count--;
return;
}else{
    if(prev==NULL){
    hashNode->HArray[index]->next=NULL;
    }else{
prev->next=tmpNode->next;
    }
free(tmpNode);
return;

}
}
prev=tmpNode;
tmpNode=tmpNode->next;
}

}


int FindIfSubset(int* mArr,int n,int* sArr,int m){


int i;
int j;

for(i=0;i<m;i++){

for(j=0;j<n;j++){

if(sArr[i]==mArr[j]){
mArr[j]=-1;
break;
}
}
if(j==n){
return 0;
}
}
return 1;
}


void TraverseHash(HNode* hashRoot){

int i;
LNode* tmpNode;

for(i=0;i<hashRoot->capacity;i++){
tmpNode=hashRoot->HArray[i]->next;
printf("\n[%d] :  ",i);
while(tmpNode){
printf("-->  %d (%d) ",tmpNode->data,tmpNode->count);
tmpNode=tmpNode->next;
}

}



}

int FindIfSubset2(int* mArr,int n,int* sArr,int m){

int i;
HNode* hashRoot=CreateHash(n);
//printf("\ncapacity and count : %d %d",hashRoot->capacity,hashRoot->count);
//getch();
for(i=0;i<n;i++){
InsertHash(hashRoot,mArr[i]);
}

//TraverseHash(hashRoot);

for(i=0;i<m;i++){
if(Search(hashRoot,sArr[i])){
RemoveHash(hashRoot,sArr[i]);
}else{
return 0;
}
}

return 1;

}


int main(){

int mArr[]={2,1,4,6,5,0,4};
int n=sizeof(mArr)/sizeof(mArr[0]);

int sArr[]={1,2,4,4,5,99};
int m=sizeof(sArr)/sizeof(sArr[0]);

/*O(n*m)
int result=FindIfSubset(mArr,n,sArr,m);
*/

//O(n)

int result=FindIfSubset2(mArr,n,sArr,m);



if(result){
printf("\nYes ! Subset");
}else{
printf("\nNo! no subset");
}







return 0;
}
