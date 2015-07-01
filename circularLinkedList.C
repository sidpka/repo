#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct CNode{
int data;
struct CNode* next;
};



void Insert(struct CNode** head,int data){

struct CNode* ptr1=(struct CNode*)malloc(sizeof(struct CNode));
ptr1->data=data;
ptr1->next=(*head);
struct CNode* tmp=(*head);

if((*head)!=NULL){
while(tmp->next!=(*head)){

tmp=tmp->next;

}
tmp->next=ptr1;
}
else{
ptr1->next=ptr1;
}
(*head)=ptr1;
}

void Traverse(struct CNode* head){

struct CNode* tmpNode=head;
if(head){
do{

printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}while(tmpNode!=head);
}

}

void SplitCLL(struct CNode* head,struct CNode** head1,struct CNode** head2){

struct CNode* slowptr=head;
struct CNode* fastptr=head;

while(fastptr->next!=head && fastptr->next->next!=head){
slowptr=slowptr->next;
fastptr=fastptr->next->next;
}
if(fastptr->next!=head){
fastptr=fastptr->next;
}

(*head1)=head;
(*head2)=slowptr->next;
slowptr->next=head;

fastptr->next=(*head2);

}

void SortedInsert(struct CNode** head,int data){

struct CNode* newPtr=(struct CNode*)malloc(sizeof(struct CNode));
newPtr->data=data;
newPtr->next=(*head);
struct CNode* tmpNode=(*head);

if(!(*head)){

newPtr->next=newPtr;
(*head)=newPtr;
}
else{
if(data<(*head)->data){
while(tmpNode->next!=(*head)){
tmpNode=tmpNode->next;
}
newPtr->next=(*head);
tmpNode->next=newPtr;

(*head)=newPtr;
}else{

while(tmpNode->next->data < data && tmpNode->next!=(*head)){
tmpNode=tmpNode->next;

}
newPtr->next=tmpNode->next;
tmpNode->next=newPtr;


}


}


}


int main(){
int i,data;
struct CNode* root=NULL;

for(i=0;i<5;i++){
    printf("\nInsert data : ");
    scanf("%d",&data);
SortedInsert(&root,data);
}
printf("\n%d nodes inserted ",i);
getch();
printf("\nPress enter to traverse\n");
Traverse(root);
getch();



/*
for(i=0;i<5;i++){
    printf("\nInsert data : ");
    scanf("%d",&data);
Insert(&root,data);
}
printf("\n%d nodes inserted ",i);
getch();
printf("\nPress enter to traverse\n");
Traverse(root);
getch();
printf("\nSplit the circular ll into two halves...");
getch();
struct CNode* head1=NULL;
struct CNode* head2=NULL;

SplitCLL(root,&head1,&head2);
printf("\nDone Splitting..\n");
getch();
Traverse(head1);
printf("\n\n");
Traverse(head2);
getch();
*/
return 0;
}
