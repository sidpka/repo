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

int Identify(struct HNode* root,struct HNode* root1){

struct LNode* tmpNode=root->next;
struct LNode* tmpNode1=root1->next;


while(1){
if(!tmpNode && !tmpNode1){
return 1;
}
if(!tmpNode && tmpNode1){
return 0;
}
else if(tmpNode && !tmpNode1){
return 0;
}
else if(tmpNode->data !=tmpNode1->data){
return 0;
}
else{
tmpNode=tmpNode->next;
tmpNode1=tmpNode1->next;
}

}


}

struct LNode* ReverseGroup(struct LNode* root,int n){

struct LNode* current=root;
struct LNode* prev=NULL;
struct LNode* next;
struct LNode* rootHolder=root;
int count=0;
while(current && count<n){
next=current->next;
current->next=prev;
prev=current;
current=next;
count++;
}

if(current){
rootHolder->next=current;
count=0;
while(current && count<n-1 ){
current=current->next;
count++;
}
if(current->next){
current->next=ReverseGroup(current->next,n);
}
}
return prev;
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
printf("\nEnter to reverse in group \nEnter group length : ");
scanf("%d",&n);
root->next=ReverseGroup(root->next,n);

getch();
Traverse(root);
return 0;
}
