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

    struct LNode* newNode=(struct LNode*)malloc(sizeof(struct LNode));
    newNode->data=data;
    newNode->next=NULL;
hashRoot->Array[index]->next=newNode;
return 1;
}else{
return 0;
}
}

int Remove(struct HashNode* hashRoot,int data){

int id=data%5;
if(hashRoot->Array[id]->next){
if(hashRoot->Array[id]->next->data==data){
return 1;
}
}



return 0;
}
void Traverse(struct HNode* root){
struct LNode* tmpNode=root->next;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}
}
void RD(struct HNode* root,struct HNode* root1,struct HNode* root2,struct HashNode* hashRoot){
struct LNode* tmpNode=root->next;
struct LNode* prev=root->next;
while(tmpNode){

  InsertHash(hashRoot,tmpNode->data);


  tmpNode=tmpNode->next;

}

struct LNode* tmpNode1=root1->next;
while(tmpNode1){

if(Remove(hashRoot,tmpNode1->data)){
Insert(root2,tmpNode1->data);

}

tmpNode1=tmpNode1->next;

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
for(i=0;i<5;i++){
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

for(i=0;i<7;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root1,data);
}

printf("\n%d Nodes inserted...",i);
getch();
printf("\nEnter to traverse..\n\n");
getch();
Traverse(root1);
getch();
/*
printf("\nEnter to remove duplicates >>\n");
getch();
RemoveDuplicate(root);
*/
printf("\nEnter to find intersectio of two lists ...");
getch();
RD(root,root1,root2,hashRoot);
//RD(root,hashRoot);
Traverse(root2);
getch();
}
