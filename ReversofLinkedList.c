#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Load_Factor 1
struct LNode{
int data;
struct LNode* next;
};

struct HNode{
int count;
struct LNode* next;
};

struct HashNode{
    struct LNode** Array;

};

struct LNode* NewNode(int data){
struct LNode* node=(struct LNode*)malloc(sizeof(struct LNode));
node->data=data;
node->next=NULL;
}

void Insert(struct HNode* root,int data){
if(root->next==NULL){
root->next=NewNode(data);
}
else{
struct LNode* tmpNode=root->next;
while(tmpNode->next){
tmpNode=tmpNode->next;
}
tmpNode->next=NewNode(data);

}
root->count++;

}

int SearchHash(struct HashNode* hashRoot,int data){
int index=data%5;
if(hashRoot->Array[index]->next){
   if(hashRoot->Array[index]->next->data==data){
return 0;
   }
}
else{
return 1;
}

}

int InsertHash(struct HashNode* hashRoot,int data){
    int index=data%5;
if(SearchHash(hashRoot,data)){
    printf("\n56here");
    struct LNode* newNode=(struct LNode*)malloc(sizeof(struct LNode));
    newNode->data=data;
    newNode->next=NULL;
hashRoot->Array[index]->next=newNode;
return 1;
}else{
return 0;
}
}


void Traverse(struct HNode* root){
struct LNode* tmpNode=root->next;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}
}



void PrintReverse(struct LNode* root){


if(!root){
return;
}

PrintReverse(root->next);

printf("%d -> ",root->data);


}

void RemoveDuplicate(struct HNode* root){

struct LNode* node=root->next;
struct LNode* next=root->next->next;

while(node && next){
if(node->data==next->data){
node->next=next->next;
free(next);
next=node->next;
}
else{
node=node->next;
next=next->next;
}
}



}
/*
void RD(struct HNode* root,struct HashNode* hashRoot){
struct LNode* tmpNode=root->next;
struct LNode* prev=root->next;
while(tmpNode){
printf("\n116");
  InsertHash(hashRoot,tmpNode->data);

  tmpNode=tmpNode->next;


}
}
*/


void RD(struct HNode* root,struct HashNode* hashRoot){
struct LNode* tmpNode=root->next;
struct LNode* prev=root->next;
while(tmpNode && prev){

  if(InsertHash(hashRoot,tmpNode->data)){

  prev=tmpNode;
  tmpNode=tmpNode->next;


  }
  else{

  prev->next=tmpNode->next;
  free(tmpNode);
  tmpNode=prev->next;

  }
}
}


void DeleteAlternate(struct HNode* root){

struct LNode* current=root->next->next;
struct LNode* prev=root->next;
while(current){
prev->next=current->next;
free(current);
if(prev->next){
current=prev->next->next;
prev=prev->next;
}else{
current=NULL;
}
}

}

void InsertTechnique(struct LNode* addPos,int data){
struct LNode* np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=data;
np->next=NULL;
printf("\n174");
(addPos)=np;

(addPos)=(addPos)->next;

}

void AlternatingSplit(struct LNode* root,struct LNode* root1,struct LNode* root2){

struct LNode* link=root->next;
struct LNode* pos1=root1->next;
struct LNode* pos2=root2->next;
int count=0;
while(link){
if(count&1){
Insert(pos2,link->data);
}else{
Insert(pos1,link->data);
}
link=link->next;
count=count+1;
}

}


int main(){
int i;
int data;
struct HNode* root=(struct HNode* )malloc(sizeof(struct HNode));
root->count=0;
root->next=NULL;
struct HNode* root1=(struct HNode* )malloc(sizeof(struct HNode));
root1->count=0;
root1->next=NULL;
struct HNode* root2=(struct HNode* )malloc(sizeof(struct HNode));
root2->count=0;
root2->next=NULL;
int n;
for(i=0;i<6;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root,data);
}

printf("\n%d Nodes inserted...",i);
getch();

struct HashNode* hashRoot=(struct HashNode*)malloc(sizeof(struct HashNode));
hashRoot->Array=(struct LNode**)malloc(sizeof(struct LNode*)*5);
for(i=0;i<5;i++){
hashRoot->Array[i]=(struct LNode*)malloc(sizeof(struct LNode));
hashRoot->Array[i]->next=NULL;
}
printf("\nEnter to traverse..\n\n");
getch();
Traverse(root);
getch();

AlternatingSplit(root,root1,root2);
printf("\nList1 :\n");
getch();
Traverse(root1);
getch();
printf("\nList2 :\n");
getch();
Traverse(root2);
getch();
printf("\nEnter to delete alternate nodes : \n");
getch();
DeleteAlternate(root);
Traverse(root);
getch();
printf("\nEnter to print reverse :\n");
getch();
PrintReverse(root->next);
getch();
/*
printf("\nEnter to remove duplicates >>\n");
getch();
RemoveDuplicate(root);
*/
printf("\nEnter to remove duplicates...");
getch();
RD(root,hashRoot);
Traverse(root);
getch();
}
