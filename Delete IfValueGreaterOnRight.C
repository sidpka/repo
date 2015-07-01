#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>
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

void Traverse(struct HNode* root){
struct LNode* tmpNode=root->next;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}
}

struct LNode* Reverse(struct HNode* root){

struct LNode* current=root->next;
struct LNode* prev=NULL;
struct LNode* node;

while(current){
node=current->next;
current->next=prev;
prev=current;
current=node;

}
return prev;
}

void Reset(struct HNode* root){

root->next=Reverse(root);

struct LNode* tmpNode=root->next;
struct LNode* prev;
int max=root->next->data;

while(tmpNode && tmpNode->next){
if(tmpNode->next->data<max){
prev=tmpNode->next;
tmpNode->next=prev->next;
free(prev);
}else{

max=tmpNode->next->data;
tmpNode=tmpNode->next;
}
}
root->next=Reverse(root);
}

void Adjust(struct HNode* root,struct HNode* root1){

struct LNode* tmpNode=root->next;
struct LNode** lastNode;
lastNode=&(root1->next);
struct LNode* prev;
while(tmpNode){
printf("\n%d ..96",tmpNode->data);
if(tmpNode->data & 1){
struct LNode* np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=tmpNode->data;
np->next=NULL;

(*lastNode)=np;
prev->next=tmpNode->next;
free(tmpNode);
tmpNode=prev->next;

}
else{

prev=tmpNode;
tmpNode=tmpNode->next;

}
lastNode=&(*lastNode)->next;

}


tmpNode->next=root1->next;
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
printf("\nEnter data for first lsit \n");
getch();
for(i=0;i<6;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root,data);
}

printf("\n%d Nodes inserted...",i);
getch();

printf("\nEnter to traverse..\n\n");
getch();
Traverse(root);
getch();
printf("\nEnter to reset:\n");
getch();
Adjust(root,root1);
Traverse(root);
getch();
return 0;
}
