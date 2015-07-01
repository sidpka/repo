#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct DLNode{
int data;
struct DLNode* next;
struct DLNode* prev;
};

void InsertFront(struct DLNode** head,int data){
struct DLNode* newNode=(struct DLNode*)malloc(sizeof(struct DLNode));
newNode->data=data;
newNode->prev=NULL;
newNode->next=(*head);
(*head)=newNode;
}

void Traverse(struct DLNode* head){
struct DLNode* tmpNode=head;
while(tmpNode){
printf("%d -->  <-- ",tmpNode->data);
tmpNode=tmpNode->next;
}
printf(" NULL");
}

void InsertLast(struct DLNode** head,int data){
struct DLNode* newNode=(struct DLNode*)malloc(sizeof(struct DLNode));
newNode->next=NULL;
newNode->data=data;

if((*head)==NULL){
newNode->prev=NULL;
(*head)=newNode;
return;
}
struct DLNode* tmpNode=(*head);
while(tmpNode->next){
tmpNode=tmpNode->next;
}
newNode->prev=tmpNode;
tmpNode->next=newNode;
}
void InsertBefore(struct DLNode* prev,int data){
struct DLNode* newNode=(struct DLNode*)malloc(sizeof(struct DLNode));
newNode->data=data;
if(!prev){
return;
}
printf("\nEntering here..\n\n\n");
newNode->prev=prev->prev;
newNode->next=prev;
prev->prev->next=newNode;
prev->prev=newNode;

}

void Delete(struct DLNode* nodeToDelete){

nodeToDelete->next->prev=nodeToDelete->prev;
nodeToDelete->prev->next=nodeToDelete->next;

free(nodeToDelete);

}

void Reverse(struct DLNode** head){

struct DLNode* tmpNode=(*head);
struct DLNode* tmpHolder=NULL;

while(tmpNode){

tmpHolder=tmpNode->prev;
tmpNode->prev=tmpNode->next;
tmpNode->next=tmpHolder;
if(!tmpNode->prev){
(*head)=tmpNode;
}
tmpNode=tmpNode->prev;
}

}

int main(){

struct DLNode* head=NULL;
int i,data;
for(i=0;i<5;i++){
printf("\nEnter data : ");
scanf("%d",&data);
InsertLast(&head,data);
}
printf("\n%d nodes inserted ...",i);
getch();
printf("\nEnter to traverse...\n\n");
getch();
Traverse(head);
getch();
printf("\nEnter data to insert at prev node ....");
scanf("%d",&data);
InsertBefore(head->next->next,data);
printf("\nInserted...\n\nEnter to traverse...\n\n");
getch();
Traverse(head);
getch();
printf("\nEnter to reverse the list \n");
getch();
Reverse(&head);
Traverse(head);
getch();
return 0;
}
