#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct DLLNode{
int data;
struct DLLNode* next;
struct DLLNode* prev;
};
typedef struct DLLNode Node;

void Insert(Node** head,int data){
Node* newNode=(Node*)malloc(sizeof(Node));

newNode->data=data;
newNode->prev=NULL;


if(!(*head)){
newNode->next=NULL;
(*head)=newNode;
return;
}
newNode->next=(*head);
(*head)->prev=newNode;
(*head)=newNode;



}

void Traverse(Node* head){
Node* tmpNode=head;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}

}

int Length(Node* head){

Node* tmpNode=head;
int len=0;
while(tmpNode){
len++;
tmpNode=tmpNode->next;
}
return len;

}

void Swap(Node** head,int k){

int n=Length(*head);
if(n<k){
return;
}
if(2*k-1==n){
return;
}

Node* xNode=(*head);
int i;

for(i=1;i<k;i++){
xNode=xNode->next;
}

Node* yNode=(*head);
for(i=1;i<(n-k+1);i++){
yNode=yNode->next;
}

if(xNode->prev){
xNode->prev->next=yNode;
}

if(yNode->prev){
yNode->prev->next=xNode;
}
Node* tmp=xNode->next;

xNode->next=yNode->next;
yNode->next=tmp;

if(k==1){
(*head)=yNode;
}
if(k==n){
(*head)=xNode;
}

}

int main(){

Node* head=NULL;
int i,data;
for(i=0;i<8;i++){
printf("\nEnter data to insert : ");
scanf("%d",&data);
Insert(&head,data);
}
printf("%d nodes inserted ...",i);
getch();
printf("\nEnter to traverse...\n");
getch();
Traverse(head);
getch();
int k;
printf("\nEnter value of K : ");
scanf("%d",&k);
Swap(&head,k);
printf("\nPress Enter to swap Kth node \n");
getch();
Traverse(head);
return 0;
}
