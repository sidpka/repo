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

void Traverse(struct HNode* root){
struct LNode* tmpNode=root->next;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}
}



void Merge(struct LNode* root,struct LNode* root1,struct LNode* root2){

struct LNode* tmpNode=root;
struct LNode* tmpNode1=root1;


struct LNode** lastNode=&root2;
struct LNode* newNode;
while(1){

if(!tmpNode){
(*lastNode)=tmpNode1;
break;
}
else if(!tmpNode1){
(*lastNode)=tmpNode;
break;
}
else if(tmpNode->data<=tmpNode1->data){
newNode=(struct LNode*)malloc(sizeof(struct LNode));
newNode->data=tmpNode->data;
newNode->next=NULL;
(*lastNode)=newNode;
tmpNode=tmpNode->next;
}
else{
newNode=(struct LNode*)malloc(sizeof(struct LNode));
newNode->data=tmpNode1->data;
newNode->next=NULL;
(*lastNode)=newNode;
tmpNode1=tmpNode1->next;
}

(lastNode)=&(*lastNode)->next;

}
}

void SplitAndSort(struct LNode* root,struct LNode* root2){
if(root==NULL){
return;
}

struct LNode* tmpNode=root;
struct LNode* root1;

struct LNode* tp=root;
struct LNode* slowPtr=root;
struct LNode* fastPtr=root;

while(fastPtr && fastPtr->next){
slowPtr=slowPtr->next;
fastPtr=fastPtr->next->next;
}
root1=slowPtr->next;
slowPtr->next=NULL;
SplitAndSort(root,root2);
SplitAndSort(root1,root2);
Merge(root,root1,root2);
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

printf("\nSorting two Lists : \n");
SplitAndSort(root->next,root2->next);
Traverse(root2);
getch();
return 0;
}
