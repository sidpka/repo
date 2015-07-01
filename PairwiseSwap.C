#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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
void swap(struct LNode* n1,struct LNode* n2){

int tmpNode;

tmpNode=n2->data;
n2->data=n1->data;
n1->data=tmpNode;


}
void PairwiseSwap(struct HNode* root){

struct LNode* current=root->next;
struct LNode* next=root->next->next;

while(current && next){
swap(current,next);
if(current->next->next && next->next->next){
current=current->next->next;
next=next->next->next;
}else{
break;
}
}

}

void LasttoFirst(struct HNode* root){
struct LNode* tmpNode=root->next;
struct LNode* prev;
while(tmpNode->next){
prev=tmpNode;
tmpNode=tmpNode->next;
}
prev->next=NULL;
tmpNode->next=root->next;
root->next=tmpNode;

}
int main(){
int i;
int data;
struct HNode* root=(struct HNode* )malloc(sizeof(struct HNode));
root->count=0;
root->next=NULL;
int n;
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
printf("\nFirst to last : \n");
getch();
LasttoFirst(root);
/*
printf("\nEnter to swap pairwise \n");
getch();
PairwiseSwap(root);
*/
Traverse(root);
getch();
}
